/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:32:45 by cduffaut          #+#    #+#             */
/*   Updated: 2023/10/24 21:19:47 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	print_hexa_p(unsigned long long nbr, int format)
{
	int		count;
	char	*tab;

	count = 0;
	tab = "0123456789abcdef";
	if (nbr < 10)
		return (print_c(tab[nbr]));
	else if (nbr < 16)
		return (print_c(tab[nbr] - format));
	else
	{
		count = print_hexa(nbr / 16, format);
		return (count + print_hexa(nbr % 16, format));
	}
}

int	print_p(long long nbr)
{
	int	count;

	count = 0;
	count += print_s("0x");
	count += print_hexa_p((unsigned long long)nbr, 0);
	return (count);
}
/*
int	main(void)
{
	int	count;

	count = 0;
	count = printf ("%p", (void *)"prout");
	printf ("\n%d\n", count);
	count = print_p((unsigned long long)"prout");
	printf ("\n%d\n", count);
	return (0);
}*/
