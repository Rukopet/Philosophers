#include "philo.h"

void 	print_mess(char *mess, int id, unsigned long time)
{
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(id);
	write(1, mess, ft_strlen(mess));
}

void	write_message(t_phil *p, int type)
{
	unsigned long	curr_time;
	static short	flag;

	flag = 0;
	pthread_mutex_lock(p->write_mute);
	curr_time = current_time() - p->start_time;
	if (!flag)
	{
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
			++flag;
			print_mess(" died\n", p->id, curr_time);
			return ;
		}
	}
	pthread_mutex_unlock(p->write_mute);
}

void	philo_lifetime(t_phil *p)
{
	if (p->parity == TRUE)
		wait_function(p->st->tt_eat - 1);
	while (1)
	{
		pthread_mutex_lock(p->rfork);
		write_message(p, FORK);
		pthread_mutex_lock(p->lfork);
		write_message(p, FORK);
		write_message(p, EAT);
		p->last_eat = current_time() - p->start_time;
		wait_function(p->st->tt_eat);
		pthread_mutex_unlock(p->lfork);
		pthread_mutex_unlock(p->rfork);
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
