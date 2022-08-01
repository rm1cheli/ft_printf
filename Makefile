NAME    =   libftprintf.a
SRCS    =   ft_16putnbr.c   ft_putnbr.c   ft_putstr.c   ft_printf.c
HEADER	=	ft_printf.h

OBJ		=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I.

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

bonus	:	 $(OBJ_B) $(HEADER)
	ar rcs $(NAME) $(OBJ_B)

clean	:
	rm -f $(OBJ) $(OBJ_B)

fclean  :   clean
	rm -f $(NAME)

re      :   fclean all
