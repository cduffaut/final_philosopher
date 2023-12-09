/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:31:34 by cduffaut          #+#    #+#             */
/*   Updated: 2023/10/24 21:18:45 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	prct_case(const char *str, va_list stock, int i)
{
	int	count;

	count = 0;
	if (str[i + 1] == '%')
		return (write(1, "%", 1));
	else if (str[i + 1] == 'c')
		count += print_c((char)va_arg(stock, int));
	else if (str[i + 1] == 's')
		count += print_s(va_arg(stock, char *));
	else if (str[i + 1] == 'p')
		count += print_p(va_arg(stock, unsigned long long));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		count += ft_putnbr((int)va_arg(stock, int));
	else if (str[i + 1] == 'u')
		count += print_u(va_arg(stock, unsigned int));
	else if (str[i + 1] == 'x')
		count += print_hexa(va_arg(stock, unsigned int), 0);
	else if (str[i + 1] == 'X')
		count += print_hexa(va_arg(stock, unsigned int), 32);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	stock;

	i = 0;
	count = 0;
	va_start(stock, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += prct_case(str, stock, i);
			i += 2;
		}
		else
		{
			write (1, &str[i], 1);
			i++;
			count++;
		}
	}
	va_end(stock);
	return (count);
}
/*
int	main(void)
{
	int	count;

	count = ft_printf(" %d ", -1);
	ft_printf("\n%d\n", count);
	
	count = printf(" %i ", -1);
	printf("\n%d\n", count);
	return (0);
}*/

/*
int	main(void)
{
	//int	nbr = 0;
	int	count = 0;

	// TEST STRINGS
	nbr = ft_printf("FAKE = %s\n", "corazón");
	printf ("FAKE = %d\n", nbr);
	nbr = printf("TRUE = %s\n", "corazón");
	printf ("TRUE = %d\n", nbr);

	// TEST CHARS
	nbr = ft_printf("FAKE = %c\n", 'u');
	printf ("FAKE = %d\n", nbr);
	nbr = printf("TRUE = %c\n", 'u');
	printf ("TRUE = %d\n", nbr);

	// TEST NBR
	nbr = ft_printf("FAKE = %d\n", 0);
	ft_printf ("FAKE = %d\n", nbr);
	nbr = printf("TRUE = %d\n", 0);
	printf ("TRUE = %d\n", nbr);
	nbr = ft_printf("FAKE = %d\n", 2147483647);
	ft_printf ("FAKE = %d\n", nbr);
	nbr = printf("TRUE = %d\n", 2147483647);
	printf ("TRUE = %d\n", nbr);
	nbr = ft_printf("FAKE = %d\n", -2147483648);
	ft_printf ("FAKE = %d\n", nbr);
	nbr = printf("TRUE = %ld\n", -2147483648);
	printf ("TRUE = %d\n", nbr);

	// TEST INTRU %

	nbr = ft_printf("FAKE = test %c et puis %%\n", 'K');
	ft_printf ("FAKE = %d\n", nbr);
	nbr = printf("TRUE = test %c et puis %%\n", 'K');
	printf ("TRUE = %d\n", nbr);

	// TEST HEXA
	count = print_hexa((unsigned int)0, 0);
	printf ("\ncount = %d\n", count);
	count = printf ("%x", (unsigned int)0);
	printf ("\ncount = %d\n", count);

	count = ft_printf("%X", -7352);
	ft_printf ("\ncount = %d\n", count);
	count = printf ("%X", (unsigned int)-7352);
	printf ("\ncount = %d\n", count);

	count = print_hexa((unsigned int)-2147483648, 32);
	printf ("\ncount = %d\n", count);
	count = printf ("%X", (unsigned int)-2147483648);
	printf ("\ncount = %d\n", count);


	count = ft_printf("%X\n", -7352);
	printf ("count = %d\n", count);
	count = printf ("%X\n", (unsigned int)-7352);
	printf ("count = %d\n", count);

	// TEST PTR

	count = printf ("REAL = %p", (void *)4444);
	printf ("\n%d\n", count);
	count = ft_printf ("FAKE = %p",4444);
	ft_printf ("\n%d\n", count);
	count = ft_printf ("%x", -777772);
	ft_printf("\n%d\n", count);
	return (0);
}*/
