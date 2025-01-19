#include "philo.h"

void	ft_think(t_philo *philo)
{
	print_message("is thinking", philo);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	print_message("has taken a fork", philo);
	if (philo->data->num_of_philos == 1)
	{
		ft_usleep(philo->data->time_to_die);
		pthread_mutex_unlock(&philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_message("has taken a fork", philo);
	print_message("is eating", philo);
	pthread_mutex_lock(&philo->data->sync_mutex);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->sync_mutex);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
}

void	ft_sleep(t_philo *philo)
{
	print_message("is sleeping", philo);
	ft_usleep(philo->data->time_to_sleep);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!philo->data->thread_ended && !philo->is_dead)
	{
		if (philo->data->thread_ended || philo->is_dead)
			break ;
		ft_eat(philo);
		if (philo->data->thread_ended || philo->is_dead
			|| philo->data->num_of_philos == 1)
			break ;
		ft_sleep(philo);
		if (philo->data->thread_ended || philo->is_dead)
			break ;
		ft_think(philo);
	}
	return (NULL);
}
