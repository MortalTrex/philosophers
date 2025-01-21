/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:40:11 by rbalazs           #+#    #+#             */
/*   Updated: 2025/01/21 12:40:12 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_args_are_correct(int nb)
{
	if (nb < 1 || nb > 200)
		return (write(1, "Error : Argument out of range", 30), false);
	return (true);
}

bool	ft_args_are_numbers(char *argv)
{
	int	i;

	i = 1;
	if (argv[0] == '-')
		return (false);
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
			return (false);
		i++;
	}
	return (true);
}

bool	check_args(int argc, char **argv)
{
	int		i;
	long	number;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		write(1, "Error : Wrong number of arguments\n", 35);
		return (false);
	}
	while (i < argc)
	{
		if (!argv[i][0])
			return (write(2, "Error : Argument is NULL", 25), false);
		if (antilonglong(argv[i]) == false)
			return (write(2, "Error : Argument too long", 26), false);
		if (ft_args_are_numbers(argv[i]) == false)
			return (write(2, "Error : Arguments must be numbers", 34), false);
		number = ft_atol(argv[i]);
		if (number == 0 && i == 1)
			return (write(2, "Error : Philo is 0", 19), false);
		if (number < -2147483648 || number > 2147483647)
			return (write(2, "Error : Argument out of range", 30), false);
		i++;
	}
	return (true);
}
