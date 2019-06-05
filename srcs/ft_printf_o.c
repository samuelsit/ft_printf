#include "../includes/ft_printf.h"

int ft_printf_o(va_list ap)
{
	int nb;

	nb = va_arg(ap, int);
	ft_putnbr_base(nb, "01234567");
	return (0);
}
