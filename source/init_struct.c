#include "../include/philosophers.h"

void	init_struct(t_table *table, char **argv, int argc)
{	
	table->number_of_philosophers = ft_atoi(argv[1]);
	table->number_of_times_each_philosopher_must_eat = ft_atoi(argv[2]);
	table->time_to_die = ft_atoi(argv[3]);
	table->time_to_eat = ft_atoi(argv[4]);
	if (argc == 5)
	{
		table->time_to_sleep = -1;
	}
	else
		table->time_to_sleep = ft_atoi(argv[5]);
}

void	init_philo(t_table *table)
{
	table->philo = malloc(sizeof(t_philo) * table->number_of_philosophers);
	if (table->philo == NULL)
	{
		printf("Couldn't allocate enough space\n");
		return ;
	}
}

void	*routine(void *t)
{
	t_table	table = *(t_table *) t;

	// pthread_mutex_lock(&table.mutex);
	printf("hello from thread %d\n", table.number_of_philosophers);
	// sleep(5);
	pthread_mutex_unlock(&table.mutex);
	return (NULL);
}

void	init_thread(t_table *table)
{
	pthread_t		*thread;
	int				i;

	pthread_mutex_init(&table->mutex, NULL);
	thread = (pthread_t *) malloc (table->number_of_philosophers
			* sizeof(pthread_t));
	if (thread == NULL)
	{
		printf("Couldn't allocate enough space\n");
		return ;
	}
	i = 0;
	while (i < table->number_of_philosophers)
	{
		printf("i = %d   ", i);
		table->philo[i].i = i;
		printf("philo = %d\n", table->philo[i].i);
		pthread_create(&thread[i], NULL, &routine, &table);
		i++;
	}
	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&table->mutex);
}
