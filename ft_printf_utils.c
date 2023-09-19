/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:09:21 by lpalacio          #+#    #+#             */
/*   Updated: 2023/09/19 20:16:06 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != 0)
		n ++;
	return (n);
}

int	ft_putstr_fd(char *s, int fd)
{
	int count;

	if (s == NULL)
		s = "(null)";
	count = ft_strlen(s);
	write (fd, s, count);
	return (count);
}

int	ft_putchar_fd(int c, int fd)
{
	return (write (1, &c, fd));
}

int	ft_putint_fd(int n, int fd)
{
	char	c;
	int	count;

	count = 0;
	if (n < 0)
	{
		count = ft_putchar_fd ('-', fd);
		n = -n;
	}
	c = '0' + n;
	return (count + ft_putchar_fd(c, fd));
}

int	ft_putnbr_fd(int n, int fd)
{
	int	num;
	int count;

	num = 0;
		
	if (n < 10 && n > -10)
		count = ft_putint_fd(n, fd);
	else if (n <= -10)
	{
		num = -(n % 10);
		n = n / 10;
		count = ft_putnbr_fd(n, fd) + 1;
		
//		printf ("\tcount: %d\t", count);  // OJO!
//		fflush(0);	//OJO!!!

		ft_putint_fd(num, fd);
	}
	else if (n >= 10)
	{
		num = n % 10;
		n = n / 10;
		count = ft_putnbr_fd(n, fd) + 1;

//		printf ("\tcount: %d\t", count); // OJO!!!
//		fflush(0);  // OJO!!

		ft_putint_fd(num, fd);
	}
//	printf ("\tcount: %d\n", count);
	return (count);
}
