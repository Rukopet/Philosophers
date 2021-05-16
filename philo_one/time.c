#include "philo.h"

void 			wait_function(unsigned int wait_timing)
{
	unsigned int	calc_time;

	calc_time = 0;
	usleep(wait_timing);
}

unsigned int	current_time(void)
{
	unsigned int ret;
	static struct timeval t;

	gettimeofday(&t, NULL);
	ret = (t.tv_sec * (unsigned int)1000) + (t.tv_usec / 1000);
	return (ret);
}