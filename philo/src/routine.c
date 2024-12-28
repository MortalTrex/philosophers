#include "philo.h"

void *routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	printf("philo %d\n", philo->id);
	return (NULL);
}