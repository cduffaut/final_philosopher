/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:15:39 by csil              #+#    #+#             */
/*   Updated: 2023/12/09 23:54:43 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_bag *l, int i, int msg)
{
	long long	time;

	pthread_mutex_lock(&l->print_state);
	time = get_time(l) - l->start_time;
	if (l->dead != 1)
	{
		printf ("%lld %d ", time, l->lphilo[i].id);
		if (msg == DIED && l->dead == 0)
		{
			l->dead = 1;
			printf ("died\n");
		}
		else if (msg == THINK)
			printf ("is thinking\n");
		else if (msg == EAT)
			printf ("is eating\n");
		else if (msg == SLEEP)
			printf ("is sleeping\n");
		else if (msg == FORK)
			printf ("has taken a fork\n");
	}
	pthread_mutex_unlock(&l->print_state);
}

static void	ft_eat(t_philo *philo)
{
	exec_mutex(philo->stock, philo->r_fork, LOCK);
	print_action(philo->stock, philo->id - 1, FORK);
	exec_mutex(philo->stock, philo->l_fork, LOCK);
	print_action(philo->stock, philo->id - 1, FORK);
	philo->eating = 1;
	philo->t_to_die = get_time(philo->stock) + philo->stock->time_to_die;
	ft_usleep((philo->stock->time_to_eat), philo->stock);
	print_action(philo->stock, philo->id - 1, EAT);
	philo->meal_counter++;
	philo->eating = 0;
	exec_mutex(philo->stock, philo->r_fork, UNLOCK);
	exec_mutex(philo->stock, philo->l_fork, UNLOCK);
}

// general routine for the philos
void	*routine(void *philo)
{
	t_philo	*lphilo;

	lphilo = (t_philo *) philo;
	exec_mutex(lphilo->stock, &lphilo->lock, LOCK);
	lphilo->t_to_die = get_time(lphilo->stock) + lphilo->stock->time_to_die;
	exec_mutex(lphilo->stock, &lphilo->lock, UNLOCK);
	exec_thread(lphilo->stock, &lphilo->th_philo, &monitor, lphilo, CREATE);
	while (lphilo->stock->dead == 0)
	{
		ft_eat(lphilo);
		print_action(lphilo->stock, lphilo->id - 1, SLEEP);
		ft_usleep(lphilo->stock->time_to_sleep, lphilo->stock);
		print_action(lphilo->stock, lphilo->id - 1, THINK);
	}
	exec_thread(lphilo->stock, &lphilo->th_philo, NULL, NULL, JOIN);
	return (NULL);
}

// check if the number of meals to eat has been reached
void	*monitor_if_meal(void *philo)
{
	t_philo	*lphilo;

	lphilo = (t_philo *)philo;
	while (lphilo->stock->dead == 0)
	{
		exec_mutex(lphilo->stock, &lphilo->lock, LOCK);
		if (lphilo->meal_counter >= lphilo->stock->meals_to_eat)
			lphilo->stock->dead = 1;
		exec_mutex(lphilo->stock, &lphilo->lock, UNLOCK);
	}
	return (NULL);
}

// check the utility of the inc meal counter in the if statement
// while no one is dead, the prog run and let routine go
void	*monitor(void *philo)
{
	t_philo	*lphilo;

	lphilo = (t_philo *)philo;
	while (lphilo->stock->dead == 0)
	{
		exec_mutex(lphilo->stock, &lphilo->lock, LOCK);
		if (lphilo->t_to_die <= get_time(lphilo->stock) && lphilo->eating == 0)
			print_action(lphilo->stock, lphilo->id - 1, DIED);
		if (lphilo->stock->meals_to_eat <= lphilo->meal_counter)
		{
			lphilo->stock->end_simu = 1;
			lphilo->meal_counter++;
		}
		exec_mutex(lphilo->stock, &lphilo->lock, UNLOCK);
	}
	return (NULL);
}
