#include "philo.h"

pthread_t **alloc_threads(t_st *s)
{
	pthread_t	**ret;
	int			i;

	ret = (pthread_t **)malloc(sizeof(pthread_t *) * s->amount);
	if (!ret)
		return (NULL);
	i = -1;
	while (++i != s->amount * 2)
	{
		ret[i] = malloc(sizeof(pthread_t));
		if (!ret[i])
			return (NULL);
	}
	ret[i] = NULL;
	return (ret);
}

t_phil **alloc_phils(t_st *s, unsigned int start_time)
{
	t_phil	**ret;
	int i;

	ret = (t_phil **)malloc(sizeof(t_phil *) * (s->amount));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i != s->amount)
	{
		ret[i] = malloc(sizeof(t_phil));
		if (!ret[i])
			return (NULL);
		memset(ret[i], 0, sizeof(t_phil));
	}
	s->forks = alloc_mutexes_forks(s);
	if (!s->forks)
		return (NULL);
	fill_forks_for_philos(ret, s, start_time);
	return (ret);
}

int create_philo(t_st *s, pthread_mutex_t *write, pthread_mutex_t *someone_dead)
{
	pthread_t **tr;
	t_phil **p;
	int	i;
	unsigned int start_time;

	start_time = current_time();
	tr = alloc_threads(s);
	p = alloc_phils(s, start_time);
	if (!tr || !p)
		return (0);
	i = -1;
	while (++i != s->amount)
	{
		p[i]->write_mute = write;
		p[i]->someone_dead = someone_dead;
		if (0 != pthread_create(tr[i], NULL, func_for_philo, p[i]))
			return (0);
		pthread_detach(*tr[i]);
		usleep(100);
	}
	i = -1;
	pthread_mutex_lock(someone_dead);
	return (1);
}