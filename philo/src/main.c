#include "philo.h"

int	main(int argc, char **argv)
{
	t_data		data;

	memset(&data, 0, sizeof(t_data));
	// data = (t_data) {};
	if (parsing(argc, argv) == ERROR)
		return (EXIT_FAILURE);
	if (initializing(&data, argv) == ERROR)
		return (EXIT_FAILURE);
	//g_print_lst(&data);
	lst_clear_philo(&data);
	return (EXIT_SUCCESS);
}
