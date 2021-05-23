
CC = clang
NAME = philo_three
FLAG = -Wall -g -Wextra -Werror
SRC = main.c ft_itoa.c ft_atoi.c create_philo.c func_for_philo.c\
		monitor.c time.c allocation_mutexes.c utils.c
OBJ = $(SRC:.c=.o)
HEADER = philo.h
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAG) -o $(NAME) $(SRC)

%.o: %.c libft.h
	@$(CC) -c $(FLAG) $< $(INC)

.PHONY: all clean fclean re

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
