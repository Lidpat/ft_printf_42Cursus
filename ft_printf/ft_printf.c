/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:15:13 by lpalacio          #+#    #+#             */
/*   Updated: 2023/04/05 22:50:36 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int ft_strlen(const char *str)
{
	int i; 

	i = 0; 
	while (str[i] != 0)
		i++;
	return i;
}



int	ft_printf(char const *fmt, ...)
{
	char *str;
	va_list	args_init;
	va_list	args;
	
	write (1, fmt, ft_strlen(fmt));
	write (1, "\n", 1);
//	printf ("1st: %s", str); //
	va_start(args_init, fmt);
	va_copy(args, args_init);
//	va_end(args_init);
	str = va_arg(args, char *);
//printf ("in: %s", str);   //
	while (*str)
	{
		write (1, str, ft_strlen(str));
		write (1, "\n", 1);
		str = va_arg(args, char *);
	}
va_end(args_init);	
va_end(args);
	return 0;
}



/***********************/

#include <stdio.h>

int main (void)
{
	char str[20]="prueba cadena";
//	printf   ("original: %s", str);
//	write (1, "\n",1);
	ft_printf("ft_print:", "arg2");
	return 0;
}


