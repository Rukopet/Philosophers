#include "philo.h"

void	*func_for_monitor(void *phil)
{
	t_phil			*p;
	unsigned long	prev_time_eat;
	int				current_eat_count;

	current_eat_count = 0;
	p = (t_phil *)phil;
	prev_time_eat = p->last_eat;
	while (p->st->tt_die >= (current_time() - p->start_time - prev_time_eat))
	{
		if (p->st->count_eat < current_eat_count)
			break ;
		if (prev_time_eat != p->last_eat)
		{
			prev_time_eat = p->last_eat;
			current_eat_count++;
		}
		usleep(50);
	}
	sem_wait(p->st->sem_monitor_off);
	if (p->st->count_eat < current_eat_count)
		sem_wait(p->st->sem_write);
	else
		write_message(p, DIED);
	sem_post(p->st->sem_dead);
	return (NULL);
}
