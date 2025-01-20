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
bool	verif_isdead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->sync_mutex);
	if (philo->data->is_dead == true)
		return (pthread_mutex_unlock(&philo->data->sync_mutex), true);
	pthread_mutex_unlock(&philo->data->sync_mutex);
	return (false);
}
void	begin_think(t_philo *philo)
{
	if (philo->data->num_of_philos % 2 == 0)
	{
		if (philo->id % 2 == 0)
		{
			print_message("is thinking", philo);
			usleep(philo->data->num_of_philos * 1000);
		}
	}
	else
	{
		if (philo->id == philo->data->num_of_philos)
		{
			print_message("is thinking", philo);
			usleep(philo->data->num_of_philos * 1000 * 2);
		}
		else if (philo->id % 2 == 0)
		{
			print_message("is thinking", philo);
			usleep(philo->data->num_of_philos * 1000);
		}
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
	while (1)
	{
		// printf("\033[0;31mnum of philos: %d\n\033[0m", philo->data->num_of_philos);
		// printf("\033[0;31mphilo id: %d\n\033[0m", philo->id);
		// printf("\033[0;31mmeal eaten: %d\n\033[0m", philo->meals_eaten);
		// if (philo->data->is_dead)
		// 	break ;
		ft_eat(philo);
		// if (philo->data->is_dead || philo->data->num_of_philos == 1)
		// 	break ;
		ft_sleep(philo);
		ft_think(philo);
		// if (philo->data->is_dead)
		// 	break ;
	}
	return (NULL);
}
