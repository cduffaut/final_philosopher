/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:14:07 by csil              #+#    #+#             */
/*   Updated: 2023/12/09 21:13:10 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// create and detach the one thread associated with the philo
// wait until he dies
void	ft_one_philo(t_bag *stock)
{
	stock->start_time = get_time(stock);
	exec_thread(stock, &stock->tid[0], &routine, &stock->lphilo[0], CREATE);
	exec_thread(stock, &stock->tid[0], &routine, NULL, DETACH);
	while (stock->dead == 0)
		ft_usleep(0, stock);
	free_all_and_exit(stock, 0);
}

// check if the args in input are valids
// if yes : intiation is starting
// Else : print error code
int	main(int argc, char **argv)
{
	t_bag		stock;

	stock = (t_bag){};
	if (argc == 5 || argc == 6)
	{
		parsing_args(&stock, argv);
		init_lists(&stock);
		if (stock.nbr_philo == 1)
			ft_one_philo(&stock);
		init_threads(&stock);
		free_all_and_exit(&stock, 0);
	}
	else
	{
		print_error(&stock, "Error: wrong number of arguments", EXIT_FAILURE);
	}
	return (0);
}
