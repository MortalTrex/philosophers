#include "philo.h"

int	ft_args_are_correct(int nb)
{
	if (nb < 1 || nb > PHILO_MAX)
		return (write(1, "Error : Argument out of range", 30), ERROR);
	return (SUCCESS);
}

bool ft_args_are_numbers(char *argv)
{
	int	i;

	i = 1;
	if (argv[0] == '-')
		return (ERROR);
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	antilonglong(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0' || str[i] == '+' || str[i] == '-')
		i++;
	str += i;
	i = 0;
	while (str[i])
	{
		if (i >= 10)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	parsing(int argc, char **argv)
{
	int	i;
	long number;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		write(1, "Error : Wrong number of arguments\n", 35);
		return (ERROR);
	}
	while (i < argc)
	{
		if (!argv[i][0])
			return (write(2, "Error : Argument is NULL", 25), ERROR);
		if (antilonglong(argv[i]) == ERROR)
			return (write(2, "Error : Argument too long", 26), ERROR);
		if (ft_args_are_numbers(argv[i]) == ERROR)
			return (write(2, "Error : Arguments must be numbers", 34), ERROR);
		number = ft_atol(argv[i]);
		if (number == 0 && i == 1)
			return (write(2, "Error : Philo is 0", 19), ERROR);
		if (number < -2147483648 || number > 2147483647)
			return (write(2, "Error : Argument out of range", 30), ERROR);
		i++;
	}
	return (SUCCESS);
}
