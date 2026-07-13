/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-18 11:28:26 by fionni            #+#    #+#             */
/*   Updated: 2026-03-18 11:28:26 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isnumber(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
    	return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
	}
	if (str[i] == '\0')
	{
		return (1);
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long nbr;
	int i;
	int digit;

	i = 0;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		if (nbr > LONG_MAX / 10 || (nbr == LONG_MAX / 10 && digit > LONG_MAX % 10))
			return (-1);
		nbr = nbr * 10 + digit;
		i++;
	}
	return (nbr);
}

long parse_arg(char *str)
{
	long value;
	if (!isnumber(str))
		return (-1);
	value = ft_atol(str);
	if(value <= 0)
		return (-1);
	return (value);
}

int	init_data(t_data *data, int argc, char **argv)
{
	long	value;

	if (argc != 5 && argc != 6)
		return (0);
	if ((value = parse_arg(argv[1])) == -1)
		return (0);
	data->num_philos = value;
	if ((value = parse_arg(argv[2])) == -1)
		return (0);
	data->time_to_die = value;
	if ((value = parse_arg(argv[3])) == -1)
		return (0);
	data->time_to_eat = value;
	if ((value = parse_arg(argv[4])) == -1)
		return (0);
	data->time_to_sleep = value;
	data->meals_required = -1;
	if (argc == 6 && (value = parse_arg(argv[5])) == -1)
		return (0);
	if (argc == 6)
		data->meals_required = value;
	data->simulation_stop = 0;
	return (1);
}
