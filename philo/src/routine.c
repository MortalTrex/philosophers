#include "philo.h"

void *routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	if (philo->id % 2)
		print_message("is thinking", philo, philo->sync);
	return (NULL);
}
