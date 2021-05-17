#include "philo.h"

void 			wait_function(unsigned int wait_timing)
{
	unsigned int	calc_time;
	unsigned int	current_timer;
	unsigned int 	steps_count;
	unsigned int 	step;

	current_timer = 0;
	calc_time = 0;
	steps_count = wait_timing * 1000 / TIMER_CURRENT_MILISECS;
	while (steps_count != step)
	{
		usleep(TIMER_CURRENT_MILISECS);
		++step;
	}
}

unsigned int	current_time(void)
{
	unsigned int ret;
	static struct timeval t;

	gettimeofday(&t, NULL);
	ret = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	return (ret);
}