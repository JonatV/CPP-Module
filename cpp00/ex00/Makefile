# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 09:24:56 by jveirman          #+#    #+#              #
#    Updated: 2024/12/20 11:14:48 by jveirman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = megaphone.cpp
NAME = megaphone
CC = clang++
CFLAGS = -Wall -Wextra -Werror
STD = -std=c++98
ifdef DEV
	# DEV_FLAGS = -g3 -fsanitize=address
	DEV_FLAGS = -Wno-shadow
else
	DEV_FLAGS =
endif

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(STD) $(DEV_FLAGS) $(OBJS) -o $(NAME)
	

%.o: %.cpp
	$(CC) $(CFLAGS) $(STD) $(DEV_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
