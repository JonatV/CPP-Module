# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 17:28:47 by jveirman          #+#    #+#              #
#    Updated: 2025/05/15 12:27:30 by jveirman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp
NAME = easyfind
CC = c++
CFLAGS = -Wall -Wextra -Werror
STD = -std=c++98
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(STD) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(STD) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
