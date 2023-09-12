#include "ft_printf.h"

int	ft_printf(char const *fmt, ...)
{
	va_list	args_i;
	va_list	args_cp;
	size_t	count;
	
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
				//write_pointer(args_i) HEX (put_n_base)
				printf ("%p", va_arg(args_i, int*)) ;
			}
			else if (*fmt == 'd' || *fmt == 'i')
			{
				//write_itoa(args_i)
				count = count + ft_write_dec(va_arg(args_i, int));
			}	
			else if (*fmt == 'u')
			{
				write (1, "unsigned int\n", 12);
			}
			else if (*fmt == 'x')
				//write_x_mins(args_i) HEX minus (put_n_base)
				write (1, "put_n_base\n",11);
			else if (*fmt == 'X')
				//write_hex_may(args_i) HEX Mayusc (put_n_base)
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
	size_t	lenr;
	size_t lenft;
	char str[15]="prueba cadena";
	int num = -15;

	lenft = ft_printf("algo o %s and num: %d\n", str, num);
	lenr = printf ("algo o %s and num: %d\n", str, num);
	printf("int ft_pri: %d\n", lenft);
	printf("int printf: %d\n", lenr);
	return 0;
}
