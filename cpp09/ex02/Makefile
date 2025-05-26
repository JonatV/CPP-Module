SRCS = main.cpp PmergeMe.cpp
NAME = PmergeMe
CC = c++
CFLAGS = -Wall -Wextra -Werror
STD = -std=c++98
OBJS = $(SRCS:.cpp=.o)
ifdef DEV
	DEV_FLAGS = -g3 -fsanitize=address
else
	DEV_FLAGS =
endif
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
