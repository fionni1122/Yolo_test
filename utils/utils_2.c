/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-25 14:38:23 by fionni            #+#    #+#             */
/*   Updated: 2026-03-25 14:38:23 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int init_forks(t_data *data)
{
    int    i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if(!data->forks)
		return (0);
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			return (0);
		}
		i++;
	}
	return (1);
}

int	init_philos_struct(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if(!data->philos)
		return (0);
	while(i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = 0;
		data->philos[i].left_fork = i;
		data->philos[i].right_fork = (i + 1) % data->num_philos;
		data->philos[i].data = data;
		i++;
	}
	return (1);
}
