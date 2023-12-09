/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:23:03 by csil              #+#    #+#             */
/*   Updated: 2023/12/09 22:52:01 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philos(t_bag *l)
{
	int		i;

	i = 0;
	while (i < l->nbr_philo)
	{
		l->lphilo[i].id = (i + 1);
		l->lphilo[i].meal_counter = 0;
		l->lphilo[i].stock = l;
		l->lphilo[i].eating = 0;
		l->lphilo[i].t_to_die = l->time_to_die;
		pthread_mutex_init(&l->lphilo[i].lock, NULL);
		i++;
	}
}

static void	init_forks(t_bag *stock)
{
	int		i;

	i = -1;
	while (++i < stock->nbr_philo)
	{
		exec_mutex(stock, &stock->lfork[i], INIT);
	}
	i = 0;
	stock->lphilo[0].l_fork = &stock->lfork[0];
	stock->lphilo[0].r_fork = &stock->lfork[stock->nbr_philo - 1];
	i = 1;
	while (i < stock->nbr_philo)
	{
		stock->lphilo[i].l_fork = &stock->lfork[i];
		stock->lphilo[i].r_fork = &stock->lfork[i - 1];
		i++;
	}
}

// Malloc philo list - t_philo type
// Malloc fort list - mutex type
// Malloc thread id list - pthread_t type
// init all fork mutexes from the tab
// assign each mutexes to the forks to each philos
// init mutexes for the writing part, time checking part
// and lock part
void	init_lists(t_bag *stock)
{
	stock->lphilo = backup_malloc(stock, sizeof(t_philo) * stock->nbr_philo);
	stock->lfork = backup_malloc(stock,
			sizeof(pthread_mutex_t) * stock->nbr_philo);
	stock->tid = backup_malloc(stock, sizeof(pthread_t) * stock->nbr_philo);
	init_forks(stock);
	init_philos(stock);
}
