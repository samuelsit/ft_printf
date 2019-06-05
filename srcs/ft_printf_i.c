#include "../includes/ft_printf.h"

int ft_printf_i(va_list ap)
{
	int nb;

	nb = va_arg(ap, int);
	ft_putnbr(nb);
	return (0);
}
