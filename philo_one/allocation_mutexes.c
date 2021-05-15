#include "philo.h"

pthread_mutex_t **alloc_mutexes_forks(t_st *s)
{
	pthread_mutex_t **ret;
	int	i;

	ret = (pthread_mutex_t **) malloc(sizeof(pthread_mutex_t *) * s->amount);
	if (!ret)
		return (NULL);
	i = -1;
	while (++i != s->amount)
	{
		ret[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(ret[i], NULL);
		if (!ret[i])
			return (NULL);
	}
	return (ret);
}

int 	fill_forks_for_philos(t_phil **philos, t_st *s, unsigned int start_time)
{
	int i;

	i = -1;
	while (++i < s->amount)
	{
		if (i == 0)
		{
			philos[i]->lfork = s->forks[i];
			philos[i]->rfork = s->forks[s->amount];
		}
		else
		{
			philos[i]->lfork = s->forks[i];
			philos[i]->rfork = s->forks[i - 1];
		}
		philos[i]->parity = FALSE;
		if (i % 2 == 0)
			philos[i]->parity = TRUE;
		philos[i]->start_time = start_time;
		philos[i]->id = i;
		philos[i]->dead_status = s->deadinside[i];
	}
	return (1);
}