CC = cc -Wall -Wextra -Werror
NAME = libftprintf.a
HEAD = printf.h
SRC = ft_printf.c ft_printf_utils.c

OBJ = $(SRC:.c=.o)

%.o : %.c Makefile $(HEAD)
	$(CC) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re