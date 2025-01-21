/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:40:00 by rbalazs           #+#    #+#             */
/*   Updated: 2025/01/21 20:19:32 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	verif_isdead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->global_mutex);
	if (philo->data->is_dead == true)
		return (pthread_mutex_unlock(&philo->data->global_mutex), true);
	pthread_mutex_unlock(&philo->data->global_mutex);
	return (false);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	if (verif_isdead(philo) == true)
	{
		pthread_mutex_unlock(&philo->right_fork);
		return ;
	}
	print_message("has taken a fork", philo);
	pthread_mutex_lock(philo->left_fork);
	if (verif_isdead(philo) == true)
	{
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	print_message("has taken a fork", philo);
	print_message("is eating", philo);
	pthread_mutex_lock(&philo->data->global_mutex);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->global_mutex);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
}

void	begin_think(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		print_message("is thinking", philo);
		usleep(philo->data->num_of_philos * 1000);
	}
	if (philo->data->num_of_philos % 2 != 0
		&& philo->id == philo->data->num_of_philos)
	{
		print_message("is thinking", philo);
		usleep(philo->data->num_of_philos * 1000 * 2);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	begin_think(philo);
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (verif_isdead(philo) == false)
	{
		if (verif_isdead(philo) == true)
			break ;
		ft_eat(philo);
		if (verif_isdead(philo) == true
			&& philo->data->finished_eating == false)
			break ;
		print_message("is sleeping", philo);
		ft_usleep(philo->data->time_to_sleep);
		if (verif_isdead(philo) == true)
			break ;
		print_message("is thinking", philo);
	}
	return (arg);
}
