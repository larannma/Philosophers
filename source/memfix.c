#include "../include/philosophers.h"

int	memfix(pthread_t **t, t_philo **p, t_table *table)
{
	*t = (pthread_t *)malloc(sizeof(pthread_t) * table->number_of_philosophers);
	if (*t == NULL)
		return (1);
	*p = (t_philo *)malloc(sizeof(t_philo) * table->number_of_philosophers);
	if (*p == NULL)
		return (1);
	return (0);
}