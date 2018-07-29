# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akotilie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/01 19:50:05 by akotilie          #+#    #+#              #
#    Updated: 2018/07/01 19:50:07 by akotilie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = akotilie.filler

FLAGS = -Wall -Werror -Wextra

GNL = get_next_line/get_next_line.c

FILLER =  start.c direction.c shape.c helpers.c read_map.c 

LIBFT = libft/libft.a

COMPILED = $(FILLER:.c=.o) $(GNL:.c=.o)

all:	$(NAME)

$(NAME): $(COMPILED) $(LIBFT) $(COLOR_COM)
	@gcc $(FLAGS) -o $(NAME) $(COMPILED) $(LIBFT)

$(LIBFT):	liball

liball:
	@make -C ./libft

clean:
	@make clean -C ./libft

fclean:	clean