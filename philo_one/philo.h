#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_phil
{
}				t_phil;

typedef struct	s_st
{
	int				amount;
	unsigned int	tt_die;
	unsigned int	tt_eat;
	unsigned int	tt_sleep;
	int				count_eat;
}					t_st;

char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);
int create_philo(t_st *s);
void	*func_for_philo(void *phil);
//void 	*monitor(void *phil);

#endif
