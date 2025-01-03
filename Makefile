SRCS = ./src/main.c ./src/ft_atoi.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = philo

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

