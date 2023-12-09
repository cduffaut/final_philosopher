/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:12:26 by csil              #+#    #+#             */
/*   Updated: 2023/12/09 21:12:57 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdbool.h>

// Rename some exec to make code more readable / practical
/** shortcut for mutex **/
typedef pthread_mutex_t	t_mtx;

// define list to avoid error compil
typedef struct s_philo	t_philo;

/** keywords shortcuts for mutex & threads executions **/
typedef enum e_keyw
{
	CREATE,
	INIT,
	LOCK,
	UNLOCK,
	JOIN,
	DETACH,
	DESTROY,
	EAT,
	SLEEP,
	THINK,
	DIED,
	FORK,
}			t_keyw;

/** ARGVS information **/
typedef struct s_bag
{
	int					nbr_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				meals_to_eat;
	pthread_mutex_t		print_state;
	pthread_mutex_t		lock;
	pthread_mutex_t		time_state;
	pthread_mutex_t		*lfork;
	t_philo				*lphilo;
	pthread_t			*tid;
	long				start_time;
	int					dead;
	int					end_simu;
}				t_bag;

/** Philo struct **/
typedef struct s_philo
{
	int					id;
	pthread_t			th_philo;
	long				t_to_die;
	int					meal_counter;
	int					eating;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		lock;
	t_bag				*stock;
}				t_philo;

// parsing
void	parsing_args(t_bag *stock, char **argv);

// init functions
void	init_lists(t_bag *stock);

// thread & mutex exec function && backup function
void	exec_thread(t_bag *list, pthread_t *thread, void *(*foo)(void *),
			void *data, t_keyw kword);
void	check_exec_thread(t_bag *list, int result, t_keyw kword);
void	exec_mutex(t_bag *list, pthread_mutex_t *mutex,
			t_keyw kword);
void	check_exec_mutex(t_bag *list, int result, t_keyw kword);

// Init philos threads
void	init_threads(t_bag *l);

// free, exit & error
void	print_error(t_bag *list, char *str, int nbr);
void	*backup_malloc(t_bag *list, int i);
void	free_all_and_exit(t_bag *list, int nbr);

// time
long	get_time(t_bag *list);
void	ft_usleep(long nbr, t_bag *l);

// routine
void	*routine(void *lphilo);
void	*monitor(void *lphilo);
void	*monitor_if_meal(void *philo);

#endif
