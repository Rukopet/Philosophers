#include "philo.h"

void	*func_for_monitor(void *phil)
{
	t_phil			*p;
	unsigned long	prev_time_eat;
	unsigned long	current_eat_count;

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
	pthread_mutex_lock(p->monitors_lock);
	if (p->st->count_eat < current_eat_count)
		pthread_mutex_lock(p->write_mute);
	else
		write_message(p, DIED);
	pthread_mutex_unlock(p->someone_dead);
	return (NULL);
}
