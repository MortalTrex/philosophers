/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:39:38 by rbalazs           #+#    #+#             */
/*   Updated: 2025/01/21 13:44:55 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_and_print_death(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].data->num_of_philos)
	{
		if (get_time()
			- philos->last_meal > (uint64_t)philos[i].data->time_to_die)
		{
			print_message("died", &philos[i]);
			pthread_mutex_lock(&philos[i].data->global_mutex);
			philos[0].data->is_dead = true;
			pthread_mutex_unlock(&philos[i].data->global_mutex);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	verif_everyone_ate(t_philo *philos)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos[0].data->meals_eaten_max == -1)
		return (false);
	while (i < philos[0].data->num_of_philos)
	{
		pthread_mutex_lock(&philos[0].data->global_mutex);
		if (philos[i].meals_eaten >= philos[0].data->meals_eaten_max)
			finished_eating++;
		pthread_mutex_unlock(&philos[0].data->global_mutex);
		i++;
	}
	if (finished_eating == philos[0].data->num_of_philos)
	{
		pthread_mutex_lock(&philos[0].data->global_mutex);
		philos[0].data->is_dead = true;
		pthread_mutex_unlock(&philos[0].data->global_mutex);
		return (true);
	}
	return (false);
}

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (verif_isdead(philo) == false)
	{
		if (verif_everyone_ate(philo) == true)
			break ;
	}
	return (arg);
}
