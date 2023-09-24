/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:15:13 by lpalacio          #+#    #+#             */
/*   Updated: 2023/09/24 20:25:39 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	if (s == NULL)
		s = "(null)";
	count = ft_strlen(s);
	write (fd, s, count);
	return (count);
}

int	ft_printnbr_fd(int n, int fd)
{
	ft_putnbr_fd(n, fd);
	return (count_printnbr(n));
}

int	check_conversion(char cs, va_list args)
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
		return (2 + ft_printnbr_base((long unsigned)p, "0123456789abcdef"));
	}
	else if (cs == 'd' || cs == 'i')
		return (ft_printnbr_fd(va_arg(args, int), 1));
	else if (cs == 'u')
		return (ft_printnbr_base(va_arg(args, unsigned), "0123456789"));
	else if (cs == 'x')
		return (ft_printnbr_base(va_arg(args, unsigned), "0123456789abcdef"));
	else if (cs == 'X')
		return (ft_printnbr_base(va_arg(args, unsigned), "0123456789ABCDEF"));
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
