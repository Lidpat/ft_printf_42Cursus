/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_basec                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:09:21 by lpalacio          #+#    #+#             */
/*   Updated: 2023/09/19 22:07:54 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdigit(int n, char *base, int base_len)
{
	int		count;
	char	c;

	count = 0;
	if (n < 0)
	{
//		count = ft_putchar_fd ('-', 1);
		n = -n;
	}
	c = base[n];
	return (count + ft_putchar_fd(c, 1));
}

int	ft_printnbr_base(unsigned n, char *base)
{
	int	num;
	int count;
	int base_len;

	//param_control
	if (base == NULL)
		return (-1);
	//if base contiene dos veces mismo valor
	//if base contiene '+ -'

	num = 0;
	base_len = ft_strlen(base);		
	if (n < base_len && n >= 0)
		count = ft_printdigit(n, base, base_len);
	else if (n <= -base_len)
	{
		num = -(n % base_len);
		n = n / base_len;
		count = ft_printnbr_base(n, base) + 1;
		
//		printf ("\tcount: %d\t", count);  // OJO!
//		fflush(0);	//OJO!!!

		ft_printdigit(num, base, base_len);
	}
	else if (n >= base_len)
	{
		num = n % base_len;
		n = n / base_len;
		count = ft_printnbr_base(n, base) + 1;

//		printf ("\tcount: %d\t", count); // OJO!!!
//		fflush(0);  // OJO!!

		ft_printdigit(num, base, base_len);
	}
//	printf ("\tcount: %d\n", count);
	return (count);
}

