SRC	=	srcs/ft_putchar.c	\
		srcs/ft_putnbr_base_printf.c	\
		srcs/ft_strlen.c	\
		srcs/ft_putnbr_uns_printf.c	\
		srcs/ft_putstr.c	\
		srcs/ft_putnbr_printf.c	\
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
		srcs/ft_printf_xmaj.c	\
		srcs/ft_atoi_printf.c

AC	=	ar rc

CC	=	gcc

NAME	=	libftprintf.a

CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AC) $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
