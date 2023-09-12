#include <unistd.h>
#include <stdarg.h>

#include <stdio.h>   ///OJO!!!

int  ft_printf(char const *fmt, ...);

size_t  ft_strlen(const char *s);
int  ft_putstr_fd(char *s, int fd);
int  ft_write_char(int c);

char  *itoa(int n);
int  ft_write_dec(int n);
