NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = push_swap manage_data utils
BONUS_SRC = checker manage_data utils
LIBFT = libft.a

RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
	
all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(LIBFT) $(SRC:=.o)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC:=.o) $(LIBFT)

$(BONUS_NAME): $(LIBFT) $(BONUS_SRC:=.o)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_SRC:=.o) $(LIBFT)
	
$(LIBFT):
	@$(MAKE) -C libft bonus
	@cp libft/libft.a .
	@cp libft/libft.h .
	@echo "libft.a compiled and imported"

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	rm -f libft.a
	rm -f libft.h
ifneq (,$(wildcard libft/))
	$(MAKE) -C libft fclean
endif

re: fclean all

.PHONY: clean fclean re all bonus