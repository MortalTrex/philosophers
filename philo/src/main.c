#include "philo.h"

// void launch_philo(t_data *data)
// {
// 	t_philo *current;
// 	int i;

// 	i = 0;
// 	current = data->p_manag.head;
// 	while(i < data->init.num_of_philos)
// 	{
// 		pthread_create(&current->tid, NULL, &routine, current);
// 		pthread_join(current->tid, NULL);
// 		current = current->next;
// 		i++;
// 	}
// }

int	main(int argc, char **argv)
{
	t_data		data;

	memset(&data, 0, sizeof(t_data));
	//PARSING FINISHED
	if (parsing(argc, argv) == ERROR)
		return (EXIT_FAILURE);
	//INITIALIZING FINISHED
	if (initializing(&data, argv, argc) == ERROR)
		return (EXIT_FAILURE);
	launch_philo(&data);
	//g_print_lst(&data);
	ft_free_all(&data);
	return (EXIT_SUCCESS);
}
