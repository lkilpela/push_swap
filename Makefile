NAME = push_swap
CCFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

LIBFT = ./lib/libft

HDRS = -I./include -I $(LIBFT)/include
LIBS = $(LIBFT)/build/libft.a
SRCS = src/
OBJS = $(SRCS:%.c=%.o)

all: libft $(NAME)

libft: 
	@make -C $(LIBFT)

%.o : %.c
	@echo "\033[32m[pipex] Compiling $< into $@\033[0m"
	@$(CC) $(CCFLAGS) -o $@ -c $< $(HDRS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HDRS) -o $(NAME) -fsanitize=address
	@echo "[pipex] Built target pipex"

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT)
	@echo "[pipex] Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)/build
	@echo "[pipex] Everything deleted."

re: fclean all
	@echo "[pipex] Everything rebuilt."

.PHONY: all clean fclean re libft