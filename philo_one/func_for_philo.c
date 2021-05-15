#include "philo.h"

void 	write_message(t_phil *p, int type)
{
	pthread_mutex_lock(p->write_mute);
//	ft_putnbr(p->id)
	pthread_mutex_unlock(p->write_mute);
}

void	philo_lifetime(t_phil *p)
{
	if (p->parity == FALSE)
	{
		pthread_mutex_lock(p->rfork);
		write_message(p, FORK);
		pthread_mutex_lock(p->lfork);
		write_message(p, FORK);
		write_message(p, EAT);
	}
}

void	*func_for_philo(void *phil)
{
	t_phil	*p;
	pthread_t monitor;

	p = (t_phil *)phil;
	p->last_eat = current_time();
	pthread_create(&monitor, NULL, func_for_monitor, phil);
	pthread_detach(monitor);
	philo_lifetime(p);
	return (NULL);
}