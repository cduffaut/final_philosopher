/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:32:14 by cduffaut          #+#    #+#             */
/*   Updated: 2023/10/24 21:21:19 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	put_c(char c)
{
	return (write (1, &c, 1));
}*/

int	print_hexa(unsigned long nbr, int format)
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
/*
int	main(void)
{
	int	count = 0;

	count = print_hexa((unsigned int)0, 0);
	printf ("\ncount = %d\n", count);
	count = printf ("%x", (unsigned int)0);
	printf ("\ncount = %d\n", count);

	count = print_hexa((unsigned int)-7352, 32);
	printf ("\ncount = %d\n", count);
	count = printf ("%X", (unsigned int)-7352);
	printf ("\ncount = %d\n", count);

	count = print_hexa((unsigned int)-2147483648, 32);
	printf ("\ncount = %d\n", count);
	count = printf ("%X", (unsigned int)-2147483648);
	printf ("\ncount = %d\n", count);

	count = print_hexa((unsigned int)2147483647, 32);
	printf ("\ncount = %d\n", count);
	count = printf ("%X", (unsigned int)2147483647);
	printf ("\ncount = %d\n", count);
	
	count = print_hexa((unsigned int)-18000, 32);
	printf ("\ncount = %d\n", count);
	count = printf ("%X", (unsigned int)-18000);
	printf ("\ncount = %d\n", count);
	return (0);
}*/
