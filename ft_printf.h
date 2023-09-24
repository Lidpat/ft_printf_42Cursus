/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:12:28 by lpalacio          #+#    #+#             */
/*   Updated: 2023/09/24 20:13:08 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(char const *fmt, ...);

size_t	ft_strlen(const char *s);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(int c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		count_printnbr(int n);

int		ft_printnbr_base(long unsigned n, char *base);
int		count_putnbr_base(long unsigned int n, size_t base_len);
void	ft_putnbr_base(long unsigned n, char *base, size_t base_len);

#endif
