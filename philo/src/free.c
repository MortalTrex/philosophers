#include "philo.h"

void exit_error(t_data *data, char *msg)
{
	write(2, "Error: ", 7);
	write(2, msg, ft_strlen(msg));
	ft_free_all(data);
	exit();
}

void	ft_free_all(t_data *data)
{
	//pthread_join
	//pthread_mutex_destroy
	lst_clear_philo(data);
}

void	lst_clear_philo(t_data *data)
{
	t_philo *current;
	t_philo *tmp;

	current = data->p_manag.head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	data->p_manag.head = NULL;
}
