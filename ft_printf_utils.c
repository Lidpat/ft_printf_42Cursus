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
	
	count = ft_strlen(s);
	write (fd, s, count);
	return count;
}
