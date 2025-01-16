#include "philo.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void exit_error(t_data *data, char *msg)
{
	write(2, "Error: ", 7);
	write(2, msg, ft_strlen(msg));
	ft_free_all(data);
	exit(EXIT_FAILURE);
}

void	ft_free_all(t_data *data)
{
	//pthread_join
	free(data->philos);
	pthread_mutex_destroy(&data->sync_mutex);
	pthread_mutex_destroy(&data->print_mutex);
}

