/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:15:13 by lpalacio          #+#    #+#             */
/*   Updated: 2023/09/12 22:41:27 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *fmt, ...)  //OJO añadir const
{
	va_list	args_i;
	va_list	args_cp;
	int	count;
	
	count = 0;
	va_start(args_i,fmt);
	va_copy(args_cp, args_i);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			write (1, fmt, 1);
			count++;
		}
		else 
		{	fmt++;
			if(*fmt == 'c')
			{
				//No protege ifisprintable
				count = count + ft_write_char(va_arg(args_i, int));
			}
			else if (*fmt == 's')
			{
				//write_string(args_i)
				count = count + ft_putstr_fd(va_arg(args_i, char *), 1);
				
			}
			else if (*fmt == 'p')
			{
				//write_pointer(args_i) HEX (ft_putnbr_base)
				printf ("%p", va_arg(args_i, int*)) ;
			}
			else if (*fmt == 'd' || *fmt == 'i')
			{
				//write_itoa(args_i) ft_putnbr() OJO!!
				count = count + ft_write_dec(va_arg(args_i, int));
			}	
			else if (*fmt == 'u')
			{
				//ft_putnbr_base()
				count = count + ft_write_dec(va_arg(args_i, unsigned int));
			}
			else if (*fmt == 'x')
				//write_x_mins(args_i) HEX minus (ft_putnbr_base)
				write (1, "put_n_base\n",11);
			else if (*fmt == 'X')
				//write_hex_may(args_i) HEX Mayusc (ft_putnbr_base)
				write (1, "put_n_base\n",11);
			else if (*fmt == '%')
				write(1,"%",1);
			else
				return (-1); //error, sth not valid
		}
		fmt++;
//		c = va_arg(args_i, char *);
	}
	va_end(args_i);	
	va_end(args_cp);
	return count;
}



/***********************/

#include <stdio.h>

int main (void)
{
	int	lenr;
	int	lenft;
	unsigned int unum = 2415918848;
	int num = -21478383;
	char str[20]="cadena de textoº";
	//char	*str;

	lenft = ft_printf("algo o %s and num: %u\t u otro tipo de num: %i\n", str, unum, num);
	lenr = 	  printf ("algo o %s and num: %u\t u otro tipo de num: %i\n", str, unum, num);
	printf("int ft_pri: %d\n", lenft);
	printf("int printf: %d\n", lenr);
	return 0;
}
