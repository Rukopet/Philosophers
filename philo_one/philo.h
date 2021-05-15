#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>


# define EAT 0
# define SLEEP 1
# define FORK 2
# define THINK 3
# define DIED 4
# define END 5

# define  TRUE 1
# define	FALSE 0

typedef struct	s_st
{
	int				amount;
	unsigned int	tt_die;
	unsigned int	tt_eat;
	unsigned int	tt_sleep;
	int				count_eat;
	pthread_mutex_t **forks;
}					t_st;

typedef struct	s_phil
{
	t_st		*st;
	int			parity;
	int 		id;

	pthread_mutex_t *lfork;
	pthread_mutex_t *rfork;
	unsigned int 	last_eat;


	pthread_mutex_t *write_mute;
	pthread_mutex_t *someone_dead;
	unsigned int start_time
}				t_phil;

char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);

void ft_putnbr(int val);
int create_philo(t_st *s, pthread_mutex_t *write_mute, \
	pthread_mutex_t *someone_dead);
void	*func_for_philo(void *phil);
void	*func_for_monitor(void *phil);
unsigned int	current_time(void);

int 	fill_forks_for_philos(t_phil **philos, t_st *s, unsigned int start_time);
pthread_mutex_t **alloc_mutexes_forks(t_st *s);
pthread_mutex_t **alloc_mutexes_deads(t_st *s);
void 	write_message(t_phil *p, int type);
//void 	*monitor(void *phil);

#endif
