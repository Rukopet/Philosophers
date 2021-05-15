#include "philo.h"

unsigned int	current_time(void)
{
	unsigned int ret;
	static struct timeval t;

	gettimeofday(&t, NULL);
	ret = (t.tv_sec * (unsigned int)1000) + (t.tv_usec / 1000);
	return (ret);
}