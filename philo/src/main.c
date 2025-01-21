/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:39:33 by rbalazs           #+#    #+#             */
/*   Updated: 2025/01/21 12:39:34 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_all(t_data *data)
{
	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
	}
	pthread_mutex_destroy(&data->sync_mutex);
}

void	launch_philo(t_data *data)
{
	pthread_t	t_monitor;
	int			i;

	i = 0;
	pthread_create(&t_monitor, NULL, &monitor, data->philos);
	while (i < data->num_of_philos)
	{
		pthread_create(&data->philos[i].philo_thread, NULL, routine,
			&data->philos[i]);
		i++;
	}
	i = 0;
	pthread_join(t_monitor, NULL);
	while (i < data->num_of_philos)
	{
		pthread_join(data->philos[i].philo_thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv) == false)
		return (EXIT_FAILURE);
	if (initializing(&data, argv, argc) == false)
	{
		ft_free_all(&data);
		return (EXIT_FAILURE);
	}
	launch_philo(&data);
	ft_free_all(&data);
	return (EXIT_SUCCESS);
}
