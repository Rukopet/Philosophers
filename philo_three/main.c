#include "philo.h"

int pars_values(t_st *s, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	if (argv[1] <= 0)
		return (0);
	s->amount = ft_atoi(argv[1]);
	if (s->amount > 200 || s->amount <= 1)
		return (0);
	s->tt_die = ft_atoi(argv[2]);
	if (s->tt_die < 0)
		return (0);
	s->tt_eat = ft_atoi(argv[3]);
	s->tt_sleep = ft_atoi(argv[4]);
	s->count_eat = INT32_MAX;
	if (argv[5])
		s->count_eat = ft_atoi(argv[5]);
	if (s->tt_eat < 0 || s->tt_sleep < 0 || s->count_eat < 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_st	s;

	memset(&s, 0, sizeof(s));
	if (!pars_values(&s, argc, argv))
		return (-1);
	if (!init_sem_for_phil(&s))
		return (-1);
	if (!create_philo(&s))
		return (-1);
	return (1);
}
