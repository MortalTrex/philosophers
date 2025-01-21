/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:40:16 by rbalazs           #+#    #+#             */
/*   Updated: 2025/01/21 13:26:03 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static bool	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->num_of_philos);
	if (!data->philos)
		return (printf("Philos array creation failed.\n"), false);
	while (i < data->num_of_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].last_meal = data->start_time;
		if (i == data->num_of_philos - 1)
			data->philos[i].left_fork = &data->philos[0].right_fork;
		else
			data->philos[i].left_fork = &data->philos[i + 1].right_fork;
		if (pthread_mutex_init(&data->philos[i].right_fork, NULL) != 0)
		{
			printf("Philos[%d] right_fork creation failed.\n", i);
			return (false);
		}
		data->philos[i].data = data;
		data->philos[i].meals_eaten = 0;
		data->philos[i].data->is_dead = false;
		i++;
	}
	return (true);
}

bool	initializing(t_data *data, char **argv, int argc)
{
	init_input(data, argv, argc);
	if (pthread_mutex_init(&data->global_mutex, NULL) != 0)
	{
		printf("global_mutex creation failed.\n");
		return (false);
	}
	if (init_philo(data) == false)
		return (false);
	return (true);
}
