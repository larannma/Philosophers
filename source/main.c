#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments\n");
		return (0);
	}
	init_struct(&table, argv, argc);
	init_philo(&table);
	init_thread(&table);
	return (0);
}
