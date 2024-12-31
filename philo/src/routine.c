#include "philo.h"

void *routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	while(philo->sync->is_dead == false)
	{
		if (philo->meals_eaten)
		pthread_mutex_lock(philo->fork_right);
		print_message("has taken a fork\n", philo, philo->sync);
		pthread_mutex_lock(philo->fork_left);
		print_message("has taken a fork\n", philo, philo->sync);
		print_message("is eating", philo, philo->sync);
		philo->meals_eaten++;
		usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		print_message("is sleeping\n", philo, philo->sync);
		usleep(philo->time_to_sleep);
		print_message("is thinking\n", philo, philo->sync);
	}
	return (NULL);
}
