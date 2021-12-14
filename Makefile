# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 17:10:26 by ehakam            #+#    #+#              #
#    Updated: 2021/12/14 17:23:14 by ehakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
WFLAGS	= -Wall -Wextra -Werrors
DEBUG	= -g -fsanitize=address
SRC		= src/*.c 
NAME	= philo

.PHONY all
all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(DEBUG) $(SRC) -o $(NAME)

.PHONY clean
clean:

.PHONY fclean
fclean: clean
	@rm -rf $(NAME)

.PHONY re
re: fclean all
