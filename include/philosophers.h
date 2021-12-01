#ifndef PHILOSOPHERS_H
# define	PHILOSOPHERS_H

# include	<stdio.h>
# include	<pthread.h>
# include	<stdlib.h>
# include	<unistd.h>

typedef struct s_table
{
	size_t			number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*mutex_forks;
}			t_table;

typedef struct s_philo
{
	size_t			name;
	size_t			left_fork;
	size_t			right_fork;
	size_t			last_ate;
	t_table			*table;
}			t_philo;

void	init_struct(char **argv, int argc);
int		init_philo(t_table *table);
int		memfix(pthread_t **t, t_philo **p, t_table *table);

//utills
int		ft_atoi(const char *str);

#endif