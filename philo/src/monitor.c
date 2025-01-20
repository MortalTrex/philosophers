#include "philo.h"

void	verif_death(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].data->num_of_philos)
	{
		if (get_time() - philos->last_meal > (uint64_t)philos[i].data->time_to_die)
		{
			print_message("died", &philos[i]);
			pthread_mutex_lock(&philos[i].data->sync_mutex);
			philos[0].data->is_dead = true;
			pthread_mutex_unlock(&philos[i].data->sync_mutex);
		}
		i++;
	}
}

void	verif_everyone_ate(t_philo *philos)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos[0].data->meals_eaten_max == -1)
		return ;
	while (i < philos[0].data->num_of_philos)
	{
		pthread_mutex_lock(&philos[0].data->sync_mutex);
		if (philos[i].meals_eaten >= philos[0].data->meals_eaten_max)
			finished_eating++;
		pthread_mutex_unlock(&philos[0].data->sync_mutex);
		i++;
	}
	if (finished_eating == philos[0].data->num_of_philos)
	{
		pthread_mutex_lock(&philos[0].data->sync_mutex);
		philos[0].data->is_dead = true;
		pthread_mutex_unlock(&philos[0].data->sync_mutex);
	}
}

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		verif_death(philo);
		verif_everyone_ate(philo);
		if (philo[0].data->is_dead)
			break ;
	}
	return (arg);
}
