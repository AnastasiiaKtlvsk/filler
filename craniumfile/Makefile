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

FILLER =  read_map.c shape.c direction.c helpers.c start.c get_next_line/get_next_line.c

LIBFT = libft/libft.a

COMPILED = $(FILLER:.c=.o)

HEADERS = cranium.h get_next_line/get_next_line.h

all: $(NAME)

$(NAME): $(COMPILED) $(LIBFT)
	@gcc $(FLAGS) -o $(NAME) $(COMPILED) $(HEADERS) $(LIBFT)

$(LIBFT): liball

liball:
	@make re -C ./libft

clean:
	@make clean -C ./libft
	@/bin/rm -f $(COMPILED)

fclean: clean
	@make fclean -C ./libft
	@/bin/rm  -f $(NAME)

re: fclean all