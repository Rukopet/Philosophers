#include "philo.h"

void 	write_message(t_phil *p, int type)
{
	unsigned int	curr_time;

	pthread_mutex_lock(p->write_mute);
	curr_time = current_time() - p->start_time;
	if (type == FORK)
		printf("%d\t%d\thas taken a fork\n", curr_time, p->id);
	else if (type == EAT)
		printf("%d\t%d\tis eating\n", curr_time, p->id);
	else if (type == SLEEP)
		printf("%d\t%d\tis sleeping\n", curr_time, p->id);
	else if (type == THINK)
		printf("%d\t%d\tis thinking\n", curr_time, p->id);
	else if (type == DIED)
		printf("%d\t%d\tdied\n", curr_time, p->id);
	pthread_mutex_unlock(p->write_mute);
}

void	philo_lifetime(t_phil *p)
{
	if (p->parity == TRUE)
		usleep(p->st->tt_eat);
	pthread_mutex_lock(p->rfork);
	write_message(p, FORK);
	pthread_mutex_lock(p->lfork);
	write_message(p, FORK);
	write_message(p, EAT);
	wait_function(p->st->tt_eat);
	p->last_eat = current_time() - p->start_time;
	pthread_mutex_unlock(p->lfork);
	pthread_mutex_unlock(p->rfork);
	write_message(p, SLEEP);
	wait_function(p->st->tt_sleep);
	write_message(p, THINK);
	wait_function(p->st->tt_sleep);
}

void	*func_for_philo(void *phil)
{
	t_phil	*p;
	pthread_t monitor;

	p = (t_phil *)phil;
	pthread_create(&monitor, NULL, func_for_monitor, phil);
	pthread_detach(monitor);
	philo_lifetime(p);
	return (NULL);
}