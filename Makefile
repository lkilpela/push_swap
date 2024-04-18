NAME = push_swap
CCFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

LIBFT = lib/libft

HDRS = -I./include -I$(LIBFT)/include/
LIBS = $(LIBFT)/build/libft.a
SRCS = src/init.c src/push_swap.c src/validate.c\
	src/utils.c src/free.c src/error.c\
	src/prepare_a_to_b.c src/prepare_b_to_a.c src/prepare_stack.c\
	src/sort_stacks.c src/sort_three.c src/commands/push.c\
	src/commands/reverse.c src/commands/rotate.c src/commands/swap.c
OBJS = $(SRCS:%.c=%.o)

all: libft $(NAME)

libft: 
	@make -C $(LIBFT)

%.o : %.c
	@echo "[$(NAME)] $(GREEN)Compiling $< into $@$(RESET)"
	@$(CC) $(CCFLAGS) -o $@ -c $< $(HDRS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HDRS) -o $(NAME) -fsanitize=address
	@echo "[$(NAME)] Built target push_swap"

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT)
	@echo "[$(NAME)] Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)/build
	@echo "[$(NAME)] Everything deleted."

re: fclean all
	@echo "[$(NAME)] Everything rebuilt."

.PHONY: all clean fclean re libft

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m