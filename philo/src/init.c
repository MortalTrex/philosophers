#include "../inc/philo.h"

void	init_input(t_philo *philo, char **argv)
{
	printf("init_input\n");
	(void)philo;
	(void)argv;
	philo->num_of_philos = (size_t)(argv[1]);
	philo->time_to_die = (size_t)ft_atoi(argv[2]);
	philo->time_to_eat = (size_t)ft_atoi(argv[3]);
	philo->time_to_sleep = (size_t)ft_atoi(argv[4]);
	// if (argv[5])
	// 	philo->num_times_to_eat = ft_atoi(argv[5]);
}