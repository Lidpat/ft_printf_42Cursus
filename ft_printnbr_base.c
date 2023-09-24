/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_basec                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:09:21 by lpalacio          #+#    #+#             */
/*   Updated: 2023/09/24 18:40:46 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_putnbr_base(long unsigned int n, size_t base_len)
{
	size_t count;

	count = 1;
	while (n >= base_len)
	{
		n = n / base_len;
		count ++;
	}
	return (count);
}

void	ft_putnbr_base(long unsigned int n, char *base, size_t base_len)
{
	long unsigned int	num;

	num = 0;
	if (n < base_len)
		ft_putchar_fd(base[n], 1);
	else if (n >= base_len)
	{
		num = n % base_len;
		n = n / base_len;
		ft_printnbr_base(n, base);
		ft_putchar_fd(base[num], 1);
	}
	return;
}

int	ft_printnbr_base (long unsigned n, char *base)
{
	size_t base_len;

	base_len = ft_strlen(base);
	if (base == NULL)
		return (-1);
	ft_putnbr_base(n, base, base_len);
	return (count_putnbr_base(n, base_len));
}

