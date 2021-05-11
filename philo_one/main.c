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

	memset(&s, 0, sizeof(s));
	if (!pars_values(&s, argc, argv))
		return (-1);
	if (!create_philo(&s))
		return (-1);
	return (1);
}
