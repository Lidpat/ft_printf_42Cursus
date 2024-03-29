# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/24 20:40:23 by lpalacio          #+#    #+#              #
#    Updated: 2023/09/24 20:40:26 by lpalacio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_printf_utils.c ft_printnbr_base.c

OBJDIR = bin
OBJS	= ${SRCS:.c=.o}
DIR_OBJS = $(addprefix $(OBJDIR)/, $(OBJS))
NAME	= libftprintf.a
RM	= rm -rf
CC = gcc
CFLAGS	= -Wall -Wextra -Werror

bin/%.o : %.c
		$(CC) ${CFLAGS} -c $< -o $@
		

.SILENT:  #equivalent to @<commands>

${NAME}: $(DIR_OBJS)
	ar crus ${NAME} ${DIR_OBJS}

$(DIR_OBJS): | $(OBJDIR)

all:	${NAME}

${OBJDIR}:
	mkdir ${OBJDIR}

clean: 
		${RM} ${DIR_OBJS}

fclean:		clean
			${RM} ${NAME} $(OBJDIR)

re:	fclean all

.PHONY: all bonus clean fclean re
