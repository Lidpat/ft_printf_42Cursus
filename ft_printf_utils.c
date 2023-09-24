/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:09:21 by lpalacio          #+#    #+#             */
/*   Updated: 2023/09/24 20:27:01 by lpalacio         ###   ########.fr       */
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

int	ft_putchar_fd(int c, int fd)
{
	return (write (fd, &c, 1));
}

void	ft_putint_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		ft_putchar_fd ('-', fd);
		n = -n;
	}
	c = '0' + n;
	ft_putchar_fd(c, fd);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	int	num;

	num = 0;
	if (n < 10 && n > -10)
		ft_putint_fd(n, fd);
	if (n <= -10)
	{
		num = -(n % 10);
		n = n / 10;
		ft_putnbr_fd(n, fd);
		ft_putint_fd(num, fd);
	}
	else if (n >= 10)
	{
		num = n % 10;
		n = n / 10;
		ft_putnbr_fd(n, fd);
		ft_putint_fd(num, fd);
	}
	return ;
}

int	count_printnbr(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count ++;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		count ++;
	}
	return (count);
}
