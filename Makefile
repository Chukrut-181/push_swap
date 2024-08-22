NAME = push_swap

PS_LIB_NAME = push_swap.a

PS_LIB_SOURCES = argv_checks.c ft_split.c ft_split_utils.c initial_stack_creation.c \
swap_command.c push_command.c rotate_command.c reverse_rotate_command.c \
push_swap_algorythm.c node_evaluations.c stack_utils.c push_swap_utils.c

MAIN = main.c

PS_LIB_OBJECTS = $(PS_LIB_SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(PS_LIB_NAME) $(NAME)

$(PS_LIB_NAME): $(PS_LIB_OBJECTS)
	ar rcs $(PS_LIB_NAME) $(PS_LIB_OBJECTS)

$(NAME): $(PS_LIB_NAME) $(MAIN)
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN) $(PS_LIB_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(PS_LIB_OBJECTS)

fclean: clean
	$(RM) $(PS_LIB_NAME) $(NAME)

re: fclean all

.PHONY: all clean fclean re
