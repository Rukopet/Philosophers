#include "philo.h"

void	wait_function(unsigned long wait_timing)
{
	unsigned long	timer;

	timer = current_time();
	while (current_time() - timer < wait_timing)
		usleep(30);
}

unsigned long	current_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}
