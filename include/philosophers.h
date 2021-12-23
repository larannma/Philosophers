/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhawk <mhawk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:05:54 by mhawk             #+#    #+#             */
/*   Updated: 2021/12/23 12:09:03 by mhawk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include	<stdio.h>
# include	<pthread.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<sys/time.h>

typedef struct s_table
{
	size_t			number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*mutex_forks;
	long long		time;
	size_t			count_to_eat;
}			t_table;

typedef struct s_philo
{
	size_t			name;
	size_t			left_fork;
	size_t			right_fork;
	size_t			last_ate;
	t_table			*table;
	struct timeval	time;
}			t_philo;

int		init_struct(char **argv, int argc);
int		init_philo(t_table *table);
int		memfix(pthread_t **t, t_philo **p, t_table *table);
void	forks_giveaway(t_philo *philo, t_table *table);
void	take_forks(t_philo *philo);
long	time_now(struct timeval time1);
void	my_usleep(long time, struct timeval now);

//utills
int		ft_atoi(const char *str);

#endif