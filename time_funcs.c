/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 23:26:48 by csil              #+#    #+#             */
/*   Updated: 2023/12/09 22:58:12 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		print_error(list, "Error: gettimeofday failed", EXIT_FAILURE, 1);
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
