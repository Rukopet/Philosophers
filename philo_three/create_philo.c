#include "philo.h"

t_phil **alloc_phils(t_st *s, unsigned long start_time)
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
	fill_forks_for_philos(ret, s, start_time);
	return (ret);
}

int create_philo(t_st *s)
{
	t_phil **p;
	int	i;
	unsigned long start_time;

	start_time = current_time();
	p = alloc_phils(s, start_time);
	if (!p)
		return (0);
	i = -1;
	while (++i != s->amount)
	{
		p[i]->pid = fork();
		if (p[i]->pid < 0)
			return (0);
		else if (p[i]->pid == 0)
			func_for_philo(p[i]);
	}
	sem_wait(s->sem_dead);
	return (1);
}