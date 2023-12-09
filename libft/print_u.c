/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:33:03 by cduffaut          #+#    #+#             */
/*   Updated: 2023/10/24 21:19:59 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/* unsigned_int = a non-negative integer in the range [0 to 4294967295] */

int	unsigned_len(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		count += 1;
	}
	return (count);
}

int	print_u(unsigned int n)
{
	char	temp;
	int		len;

	len = unsigned_len(n);
	temp = n + 48;
	if (n < 10)
		write (1, &temp, 1);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (len);
}
/*
int	main(void)
{
	printf ("\n%d\n", print_u((unsigned int)4294967295));
	printf ("\n%d\n", print_u((unsigned int)0));
	printf ("\n%d\n", print_u((unsigned int)48000));
	printf ("\n%d\n", print_u((unsigned int)90));
	return (0);
}*/
