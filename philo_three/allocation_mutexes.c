#include "philo.h"

int	init_sem_for_phil(t_st *st)
{
	sem_unlink("sem_forks");
	sem_unlink("sem_write");
	sem_unlink("sem_dead");
	sem_unlink("sem_monitor_off");
	st->sem_forks = sem_open("sem_forks", O_CREAT | O_EXCL, 0644, st->amount);
	st->sem_write = sem_open("sem_write", O_CREAT | O_EXCL, 0644, 1);
	st->sem_dead = sem_open("sem_dead", O_CREAT | O_EXCL, 0644, 1);
	sem_wait(st->sem_dead);
	st->sem_monitor_off = sem_open("sem_monitor_off", O_CREAT | O_EXCL, 0644, 1);
	if (st->sem_dead == SEM_FAILED || st->sem_write == SEM_FAILED || \
	st->sem_dead == SEM_FAILED || st->sem_dead == SEM_FAILED)
		return (0);
	return (1);
}

int	fill_forks_for_philos(t_phil **philos, t_st *s, unsigned long start_time)
{
	int i;

	i = -1;
	while (++i < s->amount)
	{
		philos[i]->parity = FALSE;
		philos[i]->st = s;
		if (i % 2 == 0)
			philos[i]->parity = TRUE;
		philos[i]->start_time = start_time;
		philos[i]->id = i;
	}
	return (1);
}