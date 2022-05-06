# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 03:09:25 by avalerio          #+#    #+#              #
#    Updated: 2022/03/04 02:09:42 by avalerio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	main.c utils.c ft_split.c
SRCDIR	=	./src/
SRCS	=	$(addprefix $(SRCDIR), $(FILES))
OBJS	=	${SRCS:.c=.o}
NAME	=	pipex
INCLUDE	=	-I includes
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address
RM		=	rm -f

.c.o:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:     clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re