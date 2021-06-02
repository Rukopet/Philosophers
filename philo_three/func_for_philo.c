#include "philo.h"

void	print_mess(char *mess, int id, unsigned long time)
{
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(id);
	write(1, mess, ft_strlen(mess));
}

void	write_message(t_phil *p, int type)
{
	unsigned long	curr_time;

	sem_wait(p->st->sem_write);
	curr_time = current_time() - p->start_time;
	if (type == FORK)
		print_mess(" has taken a fork\n", p->id, curr_time);
	else if (type == EAT)
		print_mess(" is eating\n", p->id, curr_time);
	else if (type == SLEEP)
		print_mess(" is sleeping\n", p->id, curr_time);
	else if (type == THINK)
		print_mess(" is thinking\n", p->id, curr_time);
	else if (type == DIED)
	{
		print_mess(" died\n", p->id, curr_time);
		return ;
	}
	sem_post(p->st->sem_write);
}

void	philo_lifetime(t_phil *p)
{
	if (p->parity == TRUE)
		wait_function(p->st->tt_eat - 1);
	while (1)
	{
		sem_wait(p->st->sem_forks);
		write_message(p, FORK);
		sem_wait(p->st->sem_forks);
		write_message(p, FORK);
		write_message(p, EAT);
		p->last_eat = current_time() - p->start_time;
		wait_function(p->st->tt_eat);
		sem_post(p->st->sem_forks);
		sem_post(p->st->sem_forks);
		write_message(p, SLEEP);
		wait_function(p->st->tt_sleep);
		write_message(p, THINK);
	}
}

void	*func_for_philo(void *phil)
{
	t_phil		*p;
	pthread_t	monitor;

	p = (t_phil *)phil;
	pthread_create(&monitor, NULL, func_for_monitor, phil);
	pthread_detach(monitor);
	p->last_eat = current_time() - p->start_time;
	philo_lifetime(p);
	return (NULL);
}
