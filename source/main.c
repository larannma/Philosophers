#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments\n");
		return (0);
	}
	while(1);
	if (init_struct(argv, argc))
		return (1);
	return (0);
}
