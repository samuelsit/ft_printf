SRC	=	srcs/utils/ft_putchar.c	\
		srcs/utils/ft_putnbr_base_printf.c	\
		srcs/utils/ft_strlen.c	\
		srcs/utils/ft_putnbr_uns_printf.c	\
		srcs/utils/ft_putstr.c	\
		srcs/utils/ft_putstr_tronc.c	\
		srcs/utils/ft_putnbr_printf.c	\
		srcs/utils/ft_atoi_printf.c	\
		srcs/utils/ft_strcmp.c	\
		srcs/flags/ft_printf_c.c	\
		srcs/flags/ft_printf_d.c	\
		srcs/flags/ft_printf_o.c	\
		srcs/flags/ft_printf_p.c	\
		srcs/flags/ft_printf_s.c	\
		srcs/flags/ft_printf_u.c	\
		srcs/flags/ft_printf_x.c	\
		srcs/flags/ft_printf_xmaj.c	\
		srcs/flags/ft_printf_ld.c	\
		srcs/flags/ft_printf_lo.c	\
		srcs/flags/ft_printf_lx.c	\
		srcs/flags/ft_printf_lld.c	\
		srcs/flags/ft_printf_llo.c	\
		srcs/flags/ft_printf_llx.c	\
		srcs/flags/ft_printf_dieseo.c	\
		srcs/flags/ft_printf_diesex.c	\
		srcs/flags/ft_printf_diesexmaj.c	\
		srcs/bonus/ft_printf_b.c	\
		srcs/bonus/ft_printf_smaj.c	\
		srcs/ft_printf.c	\
		srcs/tri_ft.c	\
		srcs/init_tab.c	\
		srcs/flag1.c

AC	=	ar rc

CC	=	gcc -g3

NAME	=	libftprintf.a

#CFLAGS	=	-Wall -Wextra -Werror

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
