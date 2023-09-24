/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:15:13 by lpalacio          #+#    #+#             */
/*   Updated: 2023/09/24 19:35:08 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_conversion (char cs, va_list args)
{
	void	*p;

	if (cs == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (cs == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (cs == 'p')
	{
		p = va_arg(args, void *);
		write (1, "0x", 2);
		return (2 + ft_printnbr_base((long unsigned int)p, "0123456789abcdef"));
	}
	else if (cs == 'd' || cs == 'i')
		return (ft_printnbr_fd(va_arg(args, int), 1));
	else if (cs == 'u')
		return (ft_printnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (cs == 'x')
		return (ft_printnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (cs == 'X')
		return (ft_printnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (cs == '%')
		return (write(1, "%", 1));
	else
		return (-1);
}

int	ft_printf(char const *fmt, ...)
{
	va_list	args_i;
	int		count;

	count = 0;
	va_start(args_i, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			count = count + write (1, fmt, 1);
		else
		{	
			fmt++;
			count = count + check_conversion(*fmt, args_i);
		}
		fmt++;
	}
	va_end(args_i);
	return (count);
}
/***********************/
/*
#include <stdio.h>
#include <limits.h>

int main (void)
{
	int	lenr;
	int	lenft;

	//printf("unsigned int: %d\n", UINT_MIN);

	lenft = ft_printf("num: %d\n",INT_MIN);
	lenr = 	  printf ("num: %d\n", INT_MIN);
	printf("int ft_pri: %d\n", lenft);
	printf("int printf: %d\n", lenr);
	return 0;
}
*/
