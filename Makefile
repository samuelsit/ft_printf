SRC	=	srcs/ft_putchar.c	\
		srcs/ft_putnbr_base.c	\
		srcs/ft_strlen.c	\
		srcs/ft_putnbr_uns.c	\
		srcs/ft_putstr.c	\
		srcs/ft_putnbr.c	\
		srcs/ft_printf.c	\
		srcs/ft_printf_b.c	\
		srcs/ft_printf_c.c	\
		srcs/ft_printf_d.c	\
		srcs/ft_printf_i.c	\
		srcs/ft_printf_o.c	\
		srcs/ft_printf_p.c	\
		srcs/ft_printf_s.c	\
		srcs/ft_printf_smaj.c	\
		srcs/ft_printf_u.c	\
		srcs/ft_printf_x.c	\
		srcs/ft_printf_xmaj.c

AC	=	ar rc

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

OBJ	=	$(SRC:.c=.o)

NAME	=	libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AC) $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
