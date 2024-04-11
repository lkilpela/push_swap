NAME = push_swap
CCFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

LIBFT = lib/libft

HDRS = -I./include -I$(LIBFT)/include/
LIBS = $(LIBFT)/build/libft.a
SRCS = src/error.c src/init.c src/push_swap.c src/validate.c src/utils.c
OBJS = $(SRCS:%.c=%.o)

all: libft $(NAME)

libft: 
	@make -C $(LIBFT)

%.o : %.c
	@echo "\033[32m[push_swap] Compiling $< into $@\033[0m"
	@$(CC) $(CCFLAGS) -o $@ -c $< $(HDRS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HDRS) -o $(NAME) -fsanitize=address
	@echo "[push_swap] Built target push_swap"

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT)
	@echo "[push_swap] Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)/build
	@echo "[push_swap] Everything deleted."

re: fclean all
	@echo "[push_swap] Everything rebuilt."

.PHONY: all clean fclean re libft