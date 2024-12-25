#include "philo.h"

int		add_philo(t_philo_manag *lst, t_philo *new)
{
	t_philo *current;

	current = lst->head;
	if (!current)
	{
		current = new;
	}
	else
	{
		while(current)
			current = current->next;
		current->next = new;
		new->prev = current;
		new->next = NULL;
	}
	return (SUCCESS);
}

t_philo *new_philo(t_data *data, int i)
{
	t_philo *new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->id = i + 1;
	new->last_meal = 0;
	new->time_to_live = data->init.time_to_live;
	new->time_to_eat = data->init.time_to_eat;
	new->time_to_sleep = data->init.time_to_sleep;
	if (data->central.is_meals_eaten == true)
		new->meals_eaten = data->init.meals_eaten;
	new->sync = &data->central;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}