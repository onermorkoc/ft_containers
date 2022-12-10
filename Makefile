CC = c++ 
RM = rm -rf
STD = -std=c++98
NAME = ft_containers
CFLAGS = -Wall -Werror -Wextra

SOURCES = ./Sources/main.cpp

OBJECT = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(CFLAGS) $(STD) $(OBJECT) -o $(NAME)

clean:
	$(RM) $(OBJECT)

fclean: clean
	$(RM) $(NAME)

re: fclean all