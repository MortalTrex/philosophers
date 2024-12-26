#include "philo.h"

void g_print_lst(t_data *data)
{
	t_philo *current;

	printf("main %p\n", data->p_manag.head);
	current = data->p_manag.head;
	while (current)
	{
		printf("============================================\n");
		printf("id: %d\n", current->id);
		printf("last_meal: %zu\n", current->last_meal);
		printf("time_to_live: %zu\n", current->time_to_live);
		printf("time_to_eat: %zu\n", current->time_to_eat);
		printf("time_to_sleep: %zu\n", current->time_to_sleep);
		printf("meals_eaten: %zu\n", current->meals_eaten);
		printf("sync: %p\n", current->sync);
		printf("next: %p\n", current->next);
		printf("prev: %p\n", current->prev);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_data		data;

	memset(&data, 0, sizeof(t_data));
	if (parsing(argc, argv) == ERROR)
		return (EXIT_FAILURE);
  if (initializing(&data, argv) == ERROR)
  {
    return (EXIT_FAILURE);
  }
  g_print_lst(&data);
  lst_clear_philo(&data);
	return (EXIT_SUCCESS);
}

