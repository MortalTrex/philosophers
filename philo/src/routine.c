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
		usleep(philo->data->time_to_die * 1000);
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
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
}

void	ft_sleep(t_philo *philo)
{
	print_message("is sleeping", philo);
	usleep(philo->data->time_to_sleep * 1000);
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	if (philo->id % 2 == 0)
		usleep(500);
	while (philo->is_dead == false)
	{
		printf("////////////////////////\n");
		printf("\033[1;32mid: %d\n", philo->id);
		printf("\033[1;31mis_dead: %d\n", philo->is_dead);
		printf("\033[1;36mlast_meal: %zu\n", philo->last_meal);
		printf("\033[1;35mmeals_eaten: %d\n", philo->meals_eaten);
		printf("\033[0m");
		printf("////////////////////////\n");
		ft_think(philo);
		ft_eat(philo);
		ft_sleep(philo);
	}
	return (NULL);
}