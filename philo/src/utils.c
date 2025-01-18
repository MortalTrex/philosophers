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

long	timestamp(t_data *data)
{
	return (get_time() - data->start_time);
}

int	ft_usleep(t_philo *philo, int timer)
{
	long	actual;
	long	end;

	actual = timestamp(philo->data) * 1000;
	end = actual + timer * 1000;
	while (actual <= end)
	{
		if (end - actual <= 1000)
		{
			usleep(end - actual);
			return (0);
		}
		if (philosopher_dead(philo, philo->data->time_to_die))
			return (1);
		usleep(1000);
		actual = timestamp(philo->data) * 1000;
	}
	return (0);
}

