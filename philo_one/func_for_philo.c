#include "philo.h"

void 	write_message(t_phil *p, int type)
{
	unsigned int	curr_time;
	int 			len;

	curr_time = current_time() - p->start_time;

	pthread_mutex_lock(p->write_mute);
	if (type == FORK)
	{
		ft_putnbr(curr_time);
		ft_putchar('\t');
		ft_putnbr(p->id);
		ft_putchar('\t');
		write(1, "has taken a fork\n", 17);
	}
//		printf("%d\t%d\thas taken a fork\n", curr_time, p->id);
	else if (type == EAT)
	{
		ft_putnbr(curr_time);
		ft_putchar('\t');
		ft_putnbr(p->id);
		ft_putchar('\t');
		write(1, "is eating\n", 10);
	}
	else if (type == SLEEP)
	{
		ft_putnbr(curr_time);
		ft_putchar('\t');
		ft_putnbr(p->id);
		ft_putchar('\t');
		write(1, "is sleeping\n", 12);
	}
	else if (type == THINK)
	{
		ft_putnbr(curr_time);
		ft_putchar('\t');
		ft_putnbr(p->id);
		ft_putchar('\t');
		write(1, "is thinking\n", 12);
	}
	else if (type == DIED)
	{
		ft_putnbr(curr_time);
		ft_putchar('\t');
		ft_putnbr(p->id);
		ft_putchar('\t');
		write(1, "is died\n", 8);
	}
	pthread_mutex_unlock(p->write_mute);
}

void	philo_lifetime(t_phil *p)
{
	if (p->parity == TRUE)
		wait_function(p->st->tt_eat);
	while (1)
	{
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

}

void	*func_for_philo(void *phil)
{
	t_phil	*p;
	pthread_t monitor;

	p = (t_phil *)phil;
	pthread_create(&monitor, NULL, func_for_monitor, phil);
	pthread_detach(monitor);
	p->last_eat = current_time();
	philo_lifetime(p);
	return (NULL);
}