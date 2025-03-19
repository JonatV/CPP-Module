# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 16:50:42 by jveirman          #+#    #+#              #
#    Updated: 2025/03/19 12:44:11 by jveirman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
NAME = violence
CC = c++
CFLAGS = -Wall -Wextra -Werror
STD = -std=c++98
ifdef DEV
	DEV_FLAGS = -g3 -fsanitize=address
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
