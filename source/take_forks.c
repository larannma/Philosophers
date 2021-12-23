/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhawk <mhawk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:12:32 by mhawk             #+#    #+#             */
/*   Updated: 2021/12/23 12:12:33 by mhawk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->mutex_forks[philo->left_fork]);
	pthread_mutex_lock(&philo->table->mutex);
	printf("%ld %ld has taken a fork\n", time_now(philo->time), philo->name + 1);
	pthread_mutex_unlock(&philo->table->mutex);
	pthread_mutex_lock(&philo->table->mutex_forks[philo->right_fork]);
	pthread_mutex_lock(&philo->table->mutex);
	philo->last_ate = time_now(philo->time);
	++philo->table->count_to_eat;
	printf("%ld %ld has taken a fork\n", time_now(philo->time), philo->name + 1);
	printf("%ld %ld is eating\n", time_now(philo->time), philo->name + 1);
	pthread_mutex_unlock(&philo->table->mutex);
	my_usleep(philo->table->time_to_eat, \
		philo->time);
	pthread_mutex_unlock(&philo->table->mutex_forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->mutex_forks[philo->right_fork]);
}
