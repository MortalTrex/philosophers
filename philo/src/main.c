#include "philo.h"

// void print_(t_data *data)
// {
//   t_philo *current = data->p_manag.head;
//   while(current)
//   {
//     // printf("ID [%d]\n", current->id);
//     current = current->next;
//   }
// }

int	main(int argc, char **argv)
{
	t_data		data;

	ft_bzero(&data, sizeof(t_data));
	if (parsing(argc, argv) == ERROR)
		return (EXIT_FAILURE);
  if (initializing(&data, argv) == ERROR)
    return (EXIT_FAILURE);
  // print_(&data);
	return (EXIT_SUCCESS);
}
