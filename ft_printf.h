/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printft.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:12:28 by lpalacio          #+#    #+#             */
/*   Updated: 2023/09/09 21:14:11 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#include <stdio.h>   ///OJO!!!

int  ft_printf(char const *fmt, ...);

size_t  ft_strlen(const char *s);
int  ft_putstr_fd(char *s, int fd);
int  ft_write_char(int c);

char  *itoa(int n);
int  ft_write_dec(int n);