#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>


# define EAT 0
# define SLEEP 1
# define FORK 2
# define THINK 3
# define DIED 4


# define TRUE 1
# define FALSE 0


typedef struct	s_st
{
	int				amount;
	unsigned long	tt_die;
	unsigned long	tt_eat;
	unsigned long	tt_sleep;
	int				count_eat;

	sem_t			*sem_forks;
	sem_t			*sem_write;
	sem_t			*sem_dead;
	sem_t			*sem_monitor_off;
}					t_st;

typedef struct	s_phil
{
	t_st		*st;
	short			parity;
	int 		id;
	int 			pid;

	unsigned long 	last_eat;
	unsigned long start_time;
}				t_phil;

int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);

void ft_putnbr(unsigned long n);
void ft_putchar(char c);
int create_philo(t_st *s);
void	*func_for_philo(void *phil);
void	*func_for_monitor(void *phil);
unsigned long	current_time(void);
void 			wait_function(unsigned long wait_timing);

int fill_forks_for_philos(t_phil **philos, t_st *s, unsigned long start_time);
int		init_sem_for_phil(t_st *st);
void 	write_message(t_phil *p, int type);

#endif
