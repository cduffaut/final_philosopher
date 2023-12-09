/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_and_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:48:50 by csil              #+#    #+#             */
/*   Updated: 2023/12/09 22:47:34 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_destroy_mutex(t_bag *stock)
{
	int		i;

	exec_mutex(stock, &stock->print_state, DESTROY);
	exec_mutex(stock, &stock->lock, DESTROY);
	exec_mutex(stock, &stock->time_state, DESTROY);
	i = 0;
	while (i < stock->nbr_philo)
	{
		exec_mutex(stock, &stock->lfork[i], DESTROY);
		exec_mutex(stock, &stock->lphilo[i].lock, DESTROY);
		i++;
	}
}

void	free_all_and_exit(t_bag *list, int nbr)
{
	if (list)
	{
		ft_destroy_mutex(list);
		if (list->tid)
		{
			free (list->tid);
			list->tid = NULL;
		}
		if (list->lfork)
		{
			free (list->lfork);
			list->lfork = NULL;
		}
		if (list->lphilo)
		{
			free (list->lphilo);
			list->lphilo = NULL;
		}
	}
	exit (nbr);
}

void	print_error(t_bag *list, char *str, int nbr, int destroy)
{
	ft_printf("%s\n", str);
	if (destroy == 1)
		free_all_and_exit(list, nbr);
	else
		exit (nbr);
}
