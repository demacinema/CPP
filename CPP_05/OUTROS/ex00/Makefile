# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: demrodri <demrodri@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 00:55:44 by demrodri          #+#    #+#              #
#    Updated: 2025/06/03 01:53:27 by demrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bureaucrat

SRC	=	$(wildcard *.cpp)
OBJ	=	$(SRC:.cpp=.o)

CC	=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re