#include "../inc/philo.h"


int ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}	

int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_message(char *str, t_philo *philo, t_sync *sync)
{
	int	time;

	time = get_time() - sync->start_time;
	printf("%d %d %s\n", time, philo->id, str);
}

void	add_philo(t_data *data, t_philo *new)
{
	t_philo *current;

	current = data->p_manag.head;
	if (!current)
		data->p_manag.head = new;
	else
	{
		while(current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
		new->next = NULL;
	}
}

t_philo *new_philo(t_data *data, int i)
{
	t_philo *new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->id = i + 1;
	new->last_meal = 0;
	new->time_to_die = data->init.time_to_live;
	new->time_to_eat = data->init.time_to_eat;
	new->time_to_sleep = data->init.time_to_sleep;
	if (data->central.is_meals_eaten == true)
		new->meals_eaten = data->init.meals_eaten;
	new->sync = &data->central;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

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
		printf("time_to_live: %zu\n", current->time_to_die);
		printf("time_to_eat: %zu\n", current->time_to_eat);
		printf("time_to_sleep: %zu\n", current->time_to_sleep);
		printf("meals_eaten: %zu\n", current->meals_eaten);
		printf("sync: %p\n", current->sync);
		printf("next: %p\n", current->next);
		printf("prev: %p\n", current->prev);
		current = current->next;
	}
}