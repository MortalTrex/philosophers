#include "philo.h"

void	ft_free_all(t_data *data)
{
	//pthread_join
	//pthread_mutex_destroy
	lst_clear_philo(data);
	exit(EXIT_SUCCESS);
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
