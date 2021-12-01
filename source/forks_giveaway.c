#include "../include/philosophers.h"

void	forks_giveaway(t_philo *philo, t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		philo[i].left_fork = i;
		if (i == 0)
			philo[i].right_fork = table->number_of_philosophers - 1;
		else
			philo[i].right_fork = i - 1;
		// printf("name of philosopher %zu |||| left fork = %zu right fork = %zu\n ", philo[i].name, philo[i].left_fork, philo[i].right_fork);
		i++;
	}
}
