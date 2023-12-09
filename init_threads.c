/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 09:31:49 by csil              #+#    #+#             */
/*   Updated: 2023/12/09 17:49:59 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// to test without the usleep to see the diff
// detach thread ?
void	init_threads(t_bag *l)
{
	int			i;
	pthread_t	t0;

	l->start_time = get_time(l);
	if (l->meals_to_eat > 0)
		exec_thread(l, &t0, &monitor_if_meal, &l->lphilo[0], CREATE);
	i = -1;
	while (++i < l->nbr_philo)
	{
		exec_thread(l, &l->tid[i], &routine, &l->lphilo[i], CREATE);
		ft_usleep(1, l);
	}
	i = -1;
	while (++i < l->nbr_philo)
	{
		if (pthread_join(l->tid[i], NULL))
		{
			// temporary
			printf("thread join failed\n");
			return ;
		}
		//exec_thread(l, l->tid[i], &routine, &l->lphilo[i], JOIN);
	}
}
