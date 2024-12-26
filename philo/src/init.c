#include "philo.h"

void g_print_lst(t_data *data);


void	init_input(t_data *data, char **argv)
{
	data->init.num_of_philos = ft_atol(argv[1]);
	data->init.time_to_live = ft_atol(argv[2]);
	data->init.time_to_eat = ft_atol(argv[3]);
	data->init.time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
	{
		data->init.meals_eaten = ft_atol(argv[5]);
		data->central.is_meals_eaten = true;
	}
}

int	create_mutex(t_data *data)
{
	pthread_mutex_init(&data->central.death_lock, NULL);
	pthread_mutex_init(&data->central.eat_lock, NULL);
	pthread_mutex_init(&data->central.write_lock, NULL);
	return (SUCCESS);
}

int create_list(t_data *data)
{
	t_philo	*new;
	int i;

	i = 0;
	while(i < data->init.num_of_philos)
	{
		new = new_philo(data, i);
		if (!new)
			return (ERROR);
		if (add_philo(data, new) == ERROR)
		{
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int initializing(t_data *data, char **argv)
{
	init_input(data, argv);
	create_mutex(data);
	create_list(data);
	
	return (SUCCESS);
}