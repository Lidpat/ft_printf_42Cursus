
#include "ft_printf.h"

static unsigned int	mem_size(int const n)
{
	unsigned int	count;
	int				aux;

	count = 1;
	aux = n;
	if (n <= 0)
		count++;
	while (aux != 0)
	{
		count++;
		aux = aux / 10;
	}
	return (count);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*buff;

	buff = (unsigned char *)b;
	while (len--)
		buff[len] = c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	max_size_t;

	max_size_t = (size_t) - 1;
	if (size > 0 && count > max_size_t / size)
		return (NULL);
	ptr = malloc (count * size);
	if (ptr != NULL)
		ft_bzero (ptr, count * size);
	return (ptr);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	count;

	count = mem_size (n);
	s = (char *)ft_calloc (count, sizeof(char));
	if (s == NULL)
		return (NULL);
	count--;
	s[count] = 0;
	while (count-- > 0)
	{
		if (n < 0)
			s[count] = '0' - n % 10;
		else
			s[count] = '0' + n % 10;
		n = n / 10;
		if (n == 0 && count == 1)
		{
			s[0] = '-';
			count--;
		}	
	}
	return (s);
}

int  ft_write_dec(int n)
{
	char *str;
	int	count;

	str = ft_itoa(n);
	if (str == NULL)
		return -1;
	count = ft_putstr_fd(str, 1);
	return (count);
  
}
