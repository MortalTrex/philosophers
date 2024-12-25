#include "../inc/philo.h"

bool	ft_args_are_correct(int nb)
{
	if (nb < 1 || nb > PHILO_MAX)
		return (write(1, "Error : Argument out of range", 30), false);
	return (true);
}

bool	ft_args_are_numbers(char *argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	antilonglong(char *str)
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
			return (true);
		i++;
	}
	return (false);
}

bool	verify_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		write(1, "Error : Wrong number of arguments\n", 35);
		return (false);
	}
	while (i < argc)
	{
		if (antilonglong(argv[i]) == true)
			return (write(1, "Error : Argument too long", 26), false);
		if (ft_args_are_numbers(argv[i]) == false)
			return (write(1, "Error : Arguments must be numbers", 34), false);
		i++;
	}
	return (true);
}
