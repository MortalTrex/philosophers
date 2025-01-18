#include "philo.h"

void launch_philo(t_data *data)
{
	pthread_t	t_monitor;
	int i;

	i = 0;
	pthread_create(&t_monitor, NULL, &monitor, data->philos);
	while(i < data->num_of_philos)
	{
		pthread_create(&data->philos[i].philo_thread, NULL, routine, &data->philos[i]);
		i++;
	}
	i = 0;
	pthread_join(t_monitor, NULL);
	while(i < data->num_of_philos)
	{
		pthread_join(data->philos[i].philo_thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data		data;

	memset(&data, 0, sizeof(t_data));
	if (check_args(argc, argv) == ERROR)
		return (EXIT_FAILURE);
	initializing(&data, argv, argc);
	launch_philo(&data);
	ft_free_all(&data);
	return (EXIT_SUCCESS);
}
