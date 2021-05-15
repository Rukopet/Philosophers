#include "philo.h"

int pars_values(t_st *s, int argc, char **argv)
{
	if (argc != 6)
		return (0);
	if (argv[1] <= 0)
		return (0);
	s->amount = ft_atoi(argv[1]);
	s->tt_die = ft_atoi(argv[2]);
	s->tt_eat = ft_atoi(argv[3]);
	s->tt_sleep = ft_atoi(argv[4]);
	s->count_eat = ft_atoi(argv[5]);
	return (1);
}

int	main(int argc, char **argv)
{
	t_st	s;
	pthread_mutex_t write_mute;
	pthread_mutex_t someone_dead;

	memset(&s, 0, sizeof(s));
	if (!pars_values(&s, argc, argv))
		return (-1);
	pthread_mutex_init(&write_mute, NULL);
	pthread_mutex_init(&someone_dead, NULL);
	pthread_mutex_lock(&someone_dead);
	if (!create_philo(&s, &write_mute, &someone_dead))
		return (-1);
	return (1);
}
