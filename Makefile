SRC_DIR = src
OBJS_DIR = obj

SRCS = main ft_atoi time display_error routine actions
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
SRCS := $(addsuffix .c, $(SRCS))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJS_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -rf

NAME = philo

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS) src/philo.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
