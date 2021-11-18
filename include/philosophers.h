#ifndef PHILOSOPHERS_H
# define	PHILOSOPHERS_H

# include	<stdio.h>
# include	<pthread.h>
# include	<stdlib.h>
# include	<unistd.h>

typedef struct s_philo
{
	int	i;
}			t_philo;

typedef struct s_table
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	t_philo			*philo;
	pthread_mutex_t	mutex;
	int				remember;
}			t_table;

void	init_struct(t_table *table, char **argv, int argc);
void	init_philo(t_table *table);
void	init_thread(t_table *table);

//utills
int		ft_atoi(const char *str);

#endif