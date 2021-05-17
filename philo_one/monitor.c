#include "philo.h"

void	*func_for_monitor(void *phil)
{
	t_phil *p;
	unsigned int	prev_time_eat;
	unsigned int	current_eat_count;
	unsigned int 	time_without_eat;

	prev_time_eat = 0;
	current_eat_count = 0;
	time_without_eat = 0;
	p = (t_phil *)phil;
	prev_time_eat = p->last_eat;
	time_without_eat = current_time() - p->last_eat;
//	while (p->st->tt_die > time_without_eat && \
//	p->st->count_eat >= current_eat_count)
//	{
//		time_without_eat = current_time() - p->last_eat;
//		if (prev_time_eat != p->last_eat)
//		{
//			prev_time_eat = current_time() - p->last_eat;
//			current_eat_count++;
//		}
//	}
//	pthread_mutex_lock(p->write_mute);
//	write_message(p, DIED);
//	pthread_mutex_unlock(p->someone_dead);
	return (NULL);
}
