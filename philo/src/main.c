#include "../inc/philo.h"

int	main(int argc, char **argv)
{
    t_data data;

    
	if (verify_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
    init_input(data.philos, argv);
    printf("num_of_philos: %ld\n", data.philos->num_of_philos);
    printf("time_to_die: %ld\n", data.philos->time_to_die);
    printf("time_to_eat: %ld\n", data.philos->time_to_eat);
    printf("time_to_sleep: %ld\n", data.philos->time_to_sleep);
    printf("num_times_to_eat: %ld\n", data.philos->num_times_to_eat);
	return (EXIT_SUCCESS);
}
