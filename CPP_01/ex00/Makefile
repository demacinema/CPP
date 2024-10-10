# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: demacinema <demacinema@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 00:18:52 by demrodri          #+#    #+#              #
#    Updated: 2024/10/10 20:49:28 by demacinema       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = ./brainz

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(NAME).dSYM

re: fclean $(NAME)

# Valgrind Leak Check Target
# leak: CFLAGS = $(CPPFLAGS) -g  # Add -g only for the leak target
leak: CPPFLAGS += -g  # Add -g only for the leak target
leak: $(NAME)
	valgrind --leak-check=full --track-origins=yes $(NAME)

.PHONY: all clean fclean re
