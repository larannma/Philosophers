#include "../include/philosophers.h"

int	monitoring(t_philo *philo)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < (int)philo->table->number_of_philosophers)
		{
			if ((size_t)philo->table->time_to_die
				< time_now(philo[i].time) - philo[i].last_ate)
			{
				pthread_mutex_lock(&philo->table->mutex);
				printf("%ld %ld died\n", time_now(philo[i].time),
					philo[i].name + 1);
				return (1);
			}
			if (philo->table->count_to_eat % \
				(philo->table->number_of_times_each_philosopher_must_eat \
					* philo->table->number_of_philosophers) == 0
				&& philo->table->count_to_eat != 0)
			{
				pthread_mutex_lock(&philo->table->mutex);
				printf("dinner is end\n");
				return (1);
			}
			usleep(50);
		}
	}
}

int	init_forks(t_table *table)
{
	size_t	i;

	table->mutex_forks = malloc(sizeof(pthread_mutex_t)
			* table->number_of_philosophers);
	if (table->mutex_forks == NULL)
		return (1);
	if (pthread_mutex_init(&table->mutex, NULL))
		return (1);
	i = -1;
	while (++i < table->number_of_philosophers)
		if (pthread_mutex_init(&(table->mutex_forks[i]), NULL))
			return (1);
	return (0);
}

void	*routine(void *t)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *) t;
	table = philo->table;
	if (philo->name % 2 != 0)
		usleep(100);
	while (1)
	{
		take_forks(philo);
		pthread_mutex_lock(&philo->table->mutex);
		printf("%ld %ld is sleeping\n", time_now(philo->time), philo->name + 1);
		pthread_mutex_unlock(&philo->table->mutex);
		my_usleep(philo->table->time_to_sleep, philo->time);
		pthread_mutex_lock(&philo->table->mutex);
		printf("%ld %ld is thinking\n", time_now(philo->time), philo->name + 1);
		pthread_mutex_unlock(&philo->table->mutex);
	}
	return (NULL);
}

int	init_philo(t_table *table)
{
	t_philo			*philo;
	size_t			i;
	pthread_t		*thread;

	if (memfix(&thread, &philo, table))
		return (1);
	i = -1;
	while (++i < table->number_of_philosophers)
	{
		philo[i].name = i;
		philo[i].table = table;
	}
	forks_giveaway(philo, table);
	i = -1;
	while (++i < table->number_of_philosophers)
	{
		gettimeofday(&philo[i].time, NULL);
		philo[i].last_ate = 0;
		pthread_create(&thread[i], NULL, &routine, &philo[i]);
	}
	monitoring(philo);
	return (0);
}

int	init_struct(char **argv, int argc)
{	
	t_table			table;

	table.number_of_philosophers = ft_atoi(argv[1]);
	table.time_to_die = ft_atoi(argv[2]);
	table.time_to_eat = ft_atoi(argv[3]);
	table.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
	{
		table.number_of_times_each_philosopher_must_eat = -1;
	}
	else
		table.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	if (init_forks(&table) || init_philo(&table))
		return (1);
	return (0);
}
