/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:50:34 by csil              #+#    #+#             */
/*   Updated: 2023/12/09 22:57:48 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

// Return 1 if anything else than a number is found
static int	is_nbr(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

// simple atoi that return a valid int
static int	create_nbr(char *str)
{
	long	nbr;
	int		tmp;

	nbr = 0;
	while (*str && is_nbr(*str) == 0)
	{
		tmp = (*str - '0');
		nbr = (nbr * 10) + tmp;
		str++;
	}
	if (nbr > 2147483647)
		print_error(NULL, "Error: number is too big", EXIT_FAILURE, 0);
	return (nbr);
}

static int	is_white_sp(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (0);
	return (1);
}

//	Check if the arg is legit 
//	Return it in int version
//	Or return error message if something went wrong
static int	check_is_nbr_legit(char *str)
{
	int		i;
	long	len_nbr;

	len_nbr = 0;
	while (*str && is_white_sp(*str) == 0)
		str++;
	if (*str && *str == '+')
		str++;
	else if (*str && *str == '-')
		print_error(NULL, "Error: please enter only positive numbers",
			EXIT_FAILURE, 0);
	if (*str && is_nbr(*str) == 1)
		print_error(NULL, "Error: please enter only numbers", EXIT_FAILURE, 0);
	i = 0;
	while (str[i] && is_nbr(str[i]) == 0)
	{
		len_nbr++;
		i++;
	}
	if (len_nbr > 10)
		print_error(NULL, "Error: number is too big", EXIT_FAILURE, 0);
	else if (len_nbr == 0)
		print_error(NULL, "Error: an argument is missing", EXIT_FAILURE, 0);
	len_nbr = create_nbr(str);
	return (len_nbr);
}

//	Assign the args or return error if something does not respect the rules
// Convert all the time code in millisecond
void	parsing_args(t_bag *stock, char **argv)
{
	stock->nbr_philo = check_is_nbr_legit(argv[1]);
	stock->time_to_die = (check_is_nbr_legit(argv[2]));
	stock->time_to_eat = (check_is_nbr_legit(argv[3]));
	stock->time_to_sleep = (check_is_nbr_legit(argv[4]));
	if (argv[5])
		stock->meals_to_eat = check_is_nbr_legit(argv[5]);
	else
		stock->meals_to_eat = -1;
	if (stock->nbr_philo == 0)
		print_error(NULL, "Error: one philo min is required", EXIT_FAILURE, 0);
	stock->dead = 0;
	stock->end_simu = 0;
	pthread_mutex_init(&stock->lock, NULL);
	pthread_mutex_init(&stock->print_state, NULL);
}
