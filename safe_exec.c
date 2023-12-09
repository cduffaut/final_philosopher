/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 00:11:20 by csil              #+#    #+#             */
/*   Updated: 2023/12/09 17:53:52 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// verify the good execution of malloc
void	*backup_malloc(t_bag *list, int i)
{
	void	*final;

	final = malloc(i);
	if (!final)
	{
		print_error(list, "Error: failed allocation with malloc", EXIT_FAILURE);
	}
	return (final);
}

// check if the mutex exec haven't any error
void	check_exec_mutex(t_bag *list, int result, t_keyw kword)
{
	if (result == 0)
		return ;
	else if (kword == INIT)
		print_error(list, "mutex init failed", EXIT_FAILURE);
	else if (kword == LOCK)
		print_error(list, "mutex lock failed", EXIT_FAILURE);
	else if (kword == UNLOCK)
		print_error(list, "mutex unlock failed", EXIT_FAILURE);
	else if (kword == DESTROY)
		print_error(list, "mutex destroy failed", EXIT_FAILURE);
	else
		print_error(list, "wrong mutex kword", EXIT_FAILURE);
}

// exec mutex command depending on the arg in param
void	exec_mutex(t_bag *list, pthread_mutex_t *mutex, t_keyw kword)
{
	if (kword == INIT)
		check_exec_mutex(list, pthread_mutex_init(mutex, NULL), kword);
	else if (kword == LOCK)
		check_exec_mutex(list, pthread_mutex_lock(mutex), kword);
	else if (kword == UNLOCK)
		check_exec_mutex(list, pthread_mutex_unlock(mutex), kword);
	else if (kword == DESTROY)
		check_exec_mutex(list, pthread_mutex_destroy(mutex), kword);
	else
		print_error(list, "wrong mutex kword", EXIT_FAILURE);
}


// check if the mutex exec haven't any error
void	check_exec_thread(t_bag *list, int result, t_keyw kword)
{
	if (result == 0)
		return ;
	else if (kword == CREATE)
		print_error(list, "thread create failed", EXIT_FAILURE);
	else if (kword == JOIN)
		print_error(list, "thread join failed", EXIT_FAILURE);
	else if (kword == DETACH)
		print_error(list, "thread detach failed", EXIT_FAILURE);
	else
		print_error(list, "wrong thread kword", EXIT_FAILURE);
}

// exec thread command depending on the arg in param
void	exec_thread(t_bag *list, pthread_t *thread, void *(*foo)(void *),
			void *data, t_keyw kword)
{
	if (kword == CREATE)
		check_exec_thread(list, pthread_create(thread, NULL, foo, data), kword);
	else if (kword == JOIN)
		check_exec_thread(list, pthread_join(*thread, NULL), kword);
	else if (kword == DETACH)
		check_exec_thread(list, pthread_detach(*thread), kword);
	else
		print_error(list, "wrong thread kword", EXIT_FAILURE);
}
