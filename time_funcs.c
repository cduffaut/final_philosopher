/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 23:26:48 by csil              #+#    #+#             */
/*   Updated: 2023/12/09 08:18:32 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// return the time that have been passed from now since the
// start
long	time_now(t_bag *list)
{
	struct timeval	tv;
	long			time;

	time = 0;
	pthread_mutex_lock(&list->time_state);
	if (gettimeofday(&tv, NULL) == 0)
	{
		time = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
		time = time - list->start_time;
	}
	else
	{
		print_error(list, "Error: gettimeofday failed", EXIT_FAILURE);
	}
	pthread_mutex_unlock(&list->time_state);
	return (time);
}

long	get_time(t_bag *list)
{
	struct timeval	tv;
	long			time;

	time = 0;
	if (gettimeofday(&tv, NULL) == 0)
	{
		time = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	}
	else
	{
		print_error(list, "Error: gettimeofday failed", EXIT_FAILURE);
	}
	return (time);
}

// Pimped usleep so the func is more precise
void	ft_usleep(long sleep_time, t_bag *l)
{
	long	start;

	start = get_time(l);
	while (get_time(l) - start < sleep_time)
	{
		usleep(sleep_time / 10);
	}
}
