#include "philo.h"

static void	init_input(t_data *data, char **argv, int argc)
{
	data->num_of_philos = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->start_time = get_time();
	if (argc == 6)
		data->meals_eaten_max = ft_atol(argv[5]);
	if (argc == 5)
		data->meals_eaten_max = -1;
}

static void	init_data_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->sync_mutex, NULL) != SUCCESS)
		exit_error(data, "Sync_mutex creation failed.");
	if (pthread_mutex_init(&data->print_mutex, NULL) != SUCCESS)
		exit_error(data, "Print_mutex creation failed.");
}

static void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->num_of_philos);
	if (!data->philos)
		exit_error(data, "Philos array creation failed.");
	while (i < data->num_of_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].last_meal = data->start_time;
		if (i == data->num_of_philos - 1)
			data->philos[i].left_fork = &data->philos[0].right_fork;
		else
			data->philos[i].left_fork = &data->philos[i + 1].right_fork;
		if (pthread_mutex_init(&data->philos[i].right_fork, NULL) != SUCCESS)
			exit_error(data, "Philos thread creation failed.");
		data->philos[i].data = data;
		data->philos[i].meals_eaten = 0;
		i++;
	}
}

void	initializing(t_data *data, char **argv, int argc)
{
	init_input(data, argv, argc);
	init_data_mutex(data);
	init_philo(data);
}
