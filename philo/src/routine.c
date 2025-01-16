#include "philo.h"

void  ft_think(t_philo *philo)
{
	print_message("is thinking", philo);
}

void  ft_eat(t_philo *philo)
{
	print_message("is eating", philo);
	usleep(philo->data->time_to_eat * 1000);
}

void ft_sleep(t_philo *philo)
{
	print_message("is sleeping", philo);
	usleep(philo->data->time_to_sleep * 1000);
}


void *routine(void *arg)
{
	t_philo *philo;


	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	if (philo->id % 2 == 0)
		usleep(500);
	while (philo->is_dead == false)
	{
		ft_think(philo);
		ft_eat(philo);
		ft_sleep(philo);
	}
	return (NULL);
}