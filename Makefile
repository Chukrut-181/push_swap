NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c list_ops.c argv_quality_evaluation.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	cc -o $(NAME) $(OBJS)
	@echo "push_swap compilation OK"

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@echo "All .o files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "push_swap removed"

re: fclean all

.PHONY: all clean fclean re