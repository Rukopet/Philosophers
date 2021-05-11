
CC = clang
NAME = philo_one
FLAG = -Wall -g #-Wextra -Werror
SRC = main.c ft_itoa.c ft_atoi.c ft_strdup.c create_philo.c func_for_philo.c
OBJ = $(SRC:.c=.o)
HEADER = philo.h
all: $(NAME)

$(NAME): $(OBJ) $(BOBJ) $(HEADER) clean
	@$(CC) $(FLAG) -o $(NAME) $(SRC)

%.o: %.c libft.h
	@$(CC) -c $(FLAG) $< $(INC)

.PHONY: all clean fclean re

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
