SRCS = main.cpp Harl.cpp
NAME = harl_filter
CC = clang++
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
