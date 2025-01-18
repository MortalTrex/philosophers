#include "philo.h"

bool	philosopher_dead(t_philo *philo, int time_to_die)
{
	if (get_time() - philo->last_meal > (uint64_t)time_to_die)
		return (true);
	return (false);
}


bool	verif_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].data->num_of_philos)
	{
		if (philosopher_dead(&philos[i], philos[i].data->time_to_die))
		{
			print_message("died", &philos[i]);
			pthread_mutex_lock(&philos[i].data->sync_mutex);
			philos[i].is_dead = true;
			philos[0].data->thread_ended = true;
			pthread_mutex_unlock(&philos[i].data->sync_mutex);
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
	// On compte le nombre de philosophes qui ont fini de manger
	while (i < philos[0].data->num_of_philos)
	{
		pthread_mutex_lock(&philos[0].data->sync_mutex);
		if (philos[i].meals_eaten >= philos[0].data->meals_eaten_max)
			finished_eating++;
		pthread_mutex_unlock(&philos[0].data->sync_mutex);
		i++;
	}
	// Si tous les philosophes ont fini de manger alors on termine la simulation
	if (finished_eating == philos[0].data->num_of_philos)
	{
		pthread_mutex_lock(&philos[0].data->sync_mutex);
		philos[i].is_dead = true;
		philos[0].data->thread_ended = true;
		pthread_mutex_unlock(&philos[0].data->sync_mutex);
		return (true);
	}
	return (false);
}


void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
		if (verif_dead(philo) == true || verif_everyone_ate(philo) == true)
		{
			break ;
		}
	return (arg);
}
