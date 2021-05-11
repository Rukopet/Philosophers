#include "philo.h"

pthread_t **alloc_threads(t_st *s)
{
	pthread_t	**ret;
	int			i;

	ret = (pthread_t **)malloc(sizeof(pthread_t *) * (s->amount * 2 + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i != s->amount * 2)
	{
		ret[i] = malloc(sizeof(pthread_t));
		if (!ret[i])
			return (NULL);
	}
	ret[i] = NULL;
	return (ret);
}

t_phil **alloc_phils(t_st *s)
{
	t_phil	**ret;
	int i;

	ret = (t_phil **)malloc(sizeof(t_phil *) * (s->amount * 2));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i != s->amount * 2)
	{
		ret[i] = malloc(sizeof(t_phil));
		if (!ret[i])
			return (NULL);
	}
	return (ret);
}

int create_philo(t_st *s)
{
	pthread_t **tr;
	t_phil **p;
	int	i;

	tr = alloc_threads(s);
	p = alloc_phils(s);
	if (!tr || !p)
		return (0);
	i = -1;
//	while (tr[++i] != NULL)
//	{
//		if (s->amount <= i)
	while (++i != s->amount)
		if (0 != pthread_create(tr[i], NULL, func_for_philo, &p[i]))
			return (0);
//		else
//		if (monitor tred)
//	}
	i = -1;
	while (++i != s->amount)
		if (0 != pthread_join(*tr[i], NULL))
			return (0);

	return (1);
}