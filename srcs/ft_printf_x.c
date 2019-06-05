#include "../includes/ft_printf.h"

int ft_printf_x(va_list ap)
{
	int nb;

	nb = va_arg(ap, int);
	ft_putnbr_base(nb, "0123456789abcdef");
	return (0);
}
