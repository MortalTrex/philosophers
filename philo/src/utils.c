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

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((uint64_t)(tv.tv_sec) * 1000)
		+ ((uint64_t)(tv.tv_usec) / 1000));
}

void	print_message(char *str, t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->data->print_mutex);
	time = get_time() - philo->data->start_time;
	printf("%d %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->print_mutex);
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

void print_tab(t_data *data)
{
	if (!data)
		return ;
	int i;

	for (i = 0; i < data->num_of_philos; i++)
	{
		printf("////////////////////////\n");
		printf("\033[1;32mid: %d\n", data->philos[i].id);
		printf("\033[1;33mleft_fork: %p\n", data->philos[i].left_fork);
		printf("\033[1;33mright_fork: %p\n", &data->philos[i].right_fork);
		printf("\033[1;31mis_dead: %d\n", data->philos[i].is_dead);
		printf("\033[1;36mlast_meal: %zu\n", data->philos[i].last_meal);
		printf("\033[1;35mmeals_eaten: %d\n", data->philos[i].meals_eaten);
		printf("\033[0m");
		printf("////////////////////////\n");
	}
}
