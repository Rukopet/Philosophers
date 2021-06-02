#include "philo.h"

pthread_t	**alloc_threads(t_st *s)
{
	pthread_t	**ret;
	int			i;

	ret = (pthread_t **)malloc(sizeof(pthread_t *) * s->amount);
	if (!ret)
		return (NULL);
	i = -1;
	while (++i != s->amount)
	{
		ret[i] = malloc(sizeof(pthread_t));
		if (!ret[i])
			return (NULL);
	}
	ret[i] = NULL;
	return (ret);
}

t_phil	**alloc_phils(t_st *s, unsigned long start_time)
{
	t_phil	**ret;
	int		i;

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
	fill_forks_for_philos(ret, s, start_time);
	return (ret);
}

int	create_philo(t_st *s)
{
	pthread_t		**tr;
	t_phil			**p;
	int				i;
	unsigned long	start_time;

	start_time = current_time();
	tr = alloc_threads(s);
	p = alloc_phils(s, start_time);
	if (!tr || !p)
		return (0);
	i = -1;
	while (++i != s->amount)
	{
		if (0 != pthread_create(tr[i], NULL, func_for_philo, p[i]))
			return (0);
		pthread_detach(*(tr[i]));
	}
	sem_wait(s->sem_dead);
	return (1);
}
