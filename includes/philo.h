/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-18 15:10:47 by fionni            #+#    #+#             */
/*   Updated: 2026-03-18 15:10:47 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	long				num_philos;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				meals_required;
	long				simulation_stop;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		stop_mutex;
	t_philo				*philos;
}   t_data;

typedef struct s_philo
{
	long				id;
	long				meals_eaten;
	long				last_meal_time;
	pthread_t			thread;
	int					left_fork;
	int					right_fork;
	t_data				*data;
}	t_philo;

#endif