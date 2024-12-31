#include "philo.h"

void g_print_lst(t_data *data);

void	init_input(t_data *data, char **argv)
{
	data->init.num_of_philos = ft_atol(argv[1]);
	data->init.time_to_live = ft_atol(argv[2]);
	data->init.time_to_eat = ft_atol(argv[3]);
	data->init.time_to_sleep = ft_atol(argv[4]);
	data->central.start_time = get_time();
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
		pthread_mutex_init(&new->fork_mutex, NULL);
		pthread_mutex_init(&new->meals_eaten_mutex, NULL);
		pthread_mutex_init(&new->last_meal_mutex, NULL);
		add_philo(data, new);
		new = new->next;
		i++;
	}
	return (SUCCESS);
}

void init_peer(t_data *data)
{
	t_philo *current;
	int i;

	i = 0;
	current = data->p_manag.head;
	while(i < data->init.num_of_philos)
	{
		if (i % 2)
		{
			current->fork_left = &current->next->fork_mutex;
			current->fork_right = &current->fork_mutex;
		}
		else
		{
			current->fork_left = &current->fork_mutex;
			current->fork_right = &current->next->fork_mutex;
		}
		pthread_create(&current->tid, NULL, &routine, current);
		pthread_join(current->tid, NULL);
		current = current->next;
		i++;
	}
}

int initializing(t_data *data, char **argv)
{
	init_input(data, argv);
	if (create_mutex(data) == ERROR)
		return (ERROR);
	if (create_list(data) == ERROR)
		return (ERROR);
	init_peer(data);
	return (SUCCESS);
}