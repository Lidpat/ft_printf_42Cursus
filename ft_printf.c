/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:15:13 by lpalacio          #+#    #+#             */
/*   Updated: 2023/09/09 21:27:43 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *fmt, ...)  //OJO añadir const
{
	va_list	args_i;
	va_list	args_cp;

	va_start(args_i,fmt);
	va_copy(args_cp, args_i);
	while (*fmt)
	{
		if (*fmt != '%')
			write (1, fmt, 1);
		else 
		{	fmt++;
			if(*fmt == 'c')
			{
				//write_char(args_i)  STR= c +'\0'
				printf("%c",va_arg(args_i, char));
			}
			else if (*fmt == 's')
			{
				//write_string(args_i)
				write (1, va_arg(args_i, char*), 3);
			}
			else if (*fmt == 'p')
			{
				//write_pointer(args_i) HEX (put_n_base)
				printf ("%p", va_arg(args_i, int*)) ;
			}
			else if (*fmt == 'd' || *fmt == 'i' || *fmt == 'u')
				//write_itoa(args_i)
				write(1, "itoa\n", 5);
			else if (*fmt == 'x')
				//write_x_mins(args_i) HEX minus (put_n_base)
				write (1, "put_n_base\n",11);
			else if (*fmt == 'X')
				//write_hex_may(args_i) HEX Mayusc (put_n_base)
				write (1, "put_n_base\n",11);
			else if (*fmt == '%')
				write(1,"%",1);
			else
				return 1; //error, sth not valid
		}
		fmt++;
//		c = va_arg(args_i, char *);
	}
	va_end(args_i);	
	va_end(args_cp);
	return 0;
}



/***********************/

#include <stdio.h>

int main (void)
{
	//char str[15]="prueba cadena";
//	printf   ("original: %s", str);
//	write (1, "\n",1);
	ft_printf("algo %d o %s\n", 2, "b");
	return 0;
}


