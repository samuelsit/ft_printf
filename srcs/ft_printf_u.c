#include "../includes/ft_printf.h"

int ft_printf_u(va_list ap)
{
	int nb;

	nb = va_arg(ap, int);
	ft_putnbr_uns(nb);
	return (0);
}
