#include "philo.h"

void	*func_for_monitor(void *phil)
{
	t_phil *p;
	pthread_mutex_t *dead_status;

	p = (t_phil *)phil;
	dead_status = p->dead_status;
	return (NULL);
}
