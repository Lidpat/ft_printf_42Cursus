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

int	ft_write_char(int c_int)
{
	char c;

	c = (char)c_int;
	write (1, &c, 1);
	return (1);
}
