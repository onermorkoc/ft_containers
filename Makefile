CC = c++
RM = rm -rf
NAME = ft_containers
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

SOURCES = ./main.cpp

OBJECT = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(CFLAGS) $(OBJECT) -o $(NAME)

clean:
	$(RM) $(OBJECT)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re