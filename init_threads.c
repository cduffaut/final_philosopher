/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 09:31:49 by csil              #+#    #+#             */
/*   Updated: 2023/12/09 23:54:05 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// to test without the usleep to see the diff
// detach thread ?
void	init_threads(t_bag *l)
{
	int			i;
	pthread_t	t0;

	i = -1;
	l->start_time = get_time(l);
	if (l->meals_to_eat > 0)
		exec_thread(l, &t0, &monitor_if_meal, &l->lphilo[0], CREATE);
	while (++i < l->nbr_philo)
	{
		exec_thread(l, &l->tid[i], &routine, &l->lphilo[i], CREATE);
		ft_usleep(1, l);
	}
	i = -1;
	while (++i < l->nbr_philo)
		exec_thread(l, &l->tid[i], NULL, NULL, JOIN);
}
