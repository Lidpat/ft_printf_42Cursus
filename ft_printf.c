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
				//write_char(args_i)  STR= c +'\0' //No protege ifisprintable
				count = count + ft_write_char(va_arg(args_i,int));
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
				return (-1); //error, sth not valid
		}
		fmt++;
//		c = va_arg(args_i, char *);
	}
	va_end(args_i);	
	va_end(args_cp);
	return (count);
}



/***********************/

#include <stdio.h>

int main (void)
{
	size_t	lenr;
	size_t lenft;
	//char *str;
	//char str[15]="prueba cadena";

	lenr = printf ("printf: algo o %s\n", str);
	lenft = ft_printf("ft_pri: algo o %s\n", str);

	printf("int printf: %d\n", lenr);
	printf("int ft_pri: %d\n", lenft);
	return 0;
}
