#include "../include/philosophers.h"

int	init_forks(t_table *table)
{
	table->mutex_forks = malloc(sizeof(pthread_mutex_t)
			* table->number_of_philosophers);
	if (table->mutex_forks == NULL)
		return (1);
	return (0);
}

int	init_struct(char **argv, int argc)
{	
	t_table			table;

	table.number_of_philosophers = ft_atoi(argv[1]);
	table.number_of_times_each_philosopher_must_eat = ft_atoi(argv[2]);
	table.time_to_die = ft_atoi(argv[3]);
	table.time_to_eat = ft_atoi(argv[4]);
	if (argc == 5)
	{
		table.time_to_sleep = -1;
	}
	else
		table.time_to_sleep = ft_atoi(argv[5]);
	if (init_forks(&table) || init_philo(&table))
		return (1);
	return (0);
}

void	*routine(void *t)
{
	t_philo	*philo;

	philo = (t_philo *) t;
	pthread_mutex_lock(&philo->table->mutex);
	// printf("philo name || %zu\n", philo->name);
	pthread_mutex_unlock(&philo->table->mutex);
	return (NULL);
}

int	init_philo(t_table *table)
{
	t_philo			*philo;
	size_t			i;
	pthread_t		*thread;

	pthread_mutex_init(&table->mutex, NULL);
	philo = malloc(sizeof(t_philo) * table->number_of_philosophers);
	if (memfix(&thread, &philo, table))
		return (1);
	i = 0;
	while (i < table->number_of_philosophers)
	{
		philo[i].name = i;
		philo[i].table = table;
		i++;
	}
	forks_giveaway(philo, table);
	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_create(&thread[i], NULL, &routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&table->mutex);
	return (1);
}
