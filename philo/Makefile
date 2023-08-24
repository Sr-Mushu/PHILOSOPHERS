NAME	=	philo

CC		=	cc
CFLAGS	=	-g -Wall -Werror -Wextra -pthread

SRC		=	philo.c \
	static_data.c	\
	ft_atoi.c		\
	num_vali.c		\
	ft_utiliti.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
			@rm -f $(OBJ)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re