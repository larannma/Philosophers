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
	my_usleep(philo->table->number_of_times_each_philosopher_must_eat, \
		philo->time);
	pthread_mutex_unlock(&philo->table->mutex_forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->mutex_forks[philo->right_fork]);
}
