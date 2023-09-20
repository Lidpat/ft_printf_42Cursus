/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:15:13 by lpalacio          #+#    #+#             */
/*   Updated: 2023/09/19 22:07:50 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_conversion (char cs, va_list args)
{
	void *p;

	if(cs == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (cs == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (cs == 'p')
	{
		p = va_arg(args, void *);
		if (p == 0)
			return(write(1, "(nil)", 5));
		write (1, "0x", 2);
		return (2 + ft_printnbr_base((long unsigned)p, "0123456789abcdef"));
	}
	else if (cs == 'd' || cs == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (cs == 'u')
		return (ft_printnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (cs == 'x')
		return (ft_printnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (cs == 'X')
		return (ft_printnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (cs == '%')
		return (write(1,"%",1));
	else
		return (-1); //error, sth not valid
}

int	ft_printf(char const *fmt, ...)  //OJO añadir const
{
	va_list	args_i;
	int	count;
	
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
/* 			if(*fmt == 'c')
				count = count + ft_putchar_fd(va_arg(args_i, int), 1);
			else if (*fmt == 's')
				count = count + ft_putstr_fd(va_arg(args_i, char *), 1);
			else if (*fmt == 'p')
			{
				//write_pointer(args_i) HEX (ft_putnbr_base)
				count = count + write (1, "0x", 2);
				count = count + ft_printnbr_base(va_arg(args_i, long unsigned int), "0123456789abcdef");
			}
			else if (*fmt == 'd' || *fmt == 'i')
				count = count + ft_putnbr_fd(va_arg(args_i, int), 1);
			else if (*fmt == 'u')
				count = count + ft_printnbr_base(va_arg(args_i, unsigned int), "0123456789");
			else if (*fmt == 'x')
				count = count + ft_printnbr_base(va_arg(args_i, unsigned int), "0123456789abcdef");
			else if (*fmt == 'X')
				count = count + ft_printnbr_base(va_arg(args_i, unsigned int), "0123456789ABCDEF");
			else if (*fmt == '%')
				count = count + write(1,"%",1);
			else
				return (-1); //error, sth not valid */
		}
		fmt++;
	}
	va_end(args_i);	
	return count;
}



/***********************/

/* #include <stdio.h>

	int main (void)
{
	int	lenr;
	int	lenft;
	//unsigned int num = 103;
	//int num = -183832;
	//void *p;
	//char str[20]="cadena de texto";
	//char	*str;
	//p = &num;


	lenft = ft_printf("algo o %% and num: %p\t u otro tipo de num: %p\n", 0, 0);
	lenr = 	  printf ("algo o %% and num: %p\t u otro tipo de num: %p\n", 0, 0);
	printf("int ft_pri: %d\n", lenft);
	printf("int printf: %d\n", lenr);
	return 0;
} */
 