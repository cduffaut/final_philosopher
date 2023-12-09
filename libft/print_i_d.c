/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:32:23 by cduffaut          #+#    #+#             */
/*   Updated: 2023/10/24 21:19:27 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	len_nbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		count += 1;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		count += 1;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	char	temp;
	int		len;

	len = len_nbr(n);
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	temp = (n + 48);
	if (n < 10)
		write (1, &temp, 1);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (len);
}
