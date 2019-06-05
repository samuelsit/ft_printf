#include "../includes/ft_printf.h"

int ft_printf_xmaj(va_list ap)
{
	int nb;

	nb = va_arg(ap, int);
	ft_putnbr_base(nb, "0123456789ABCDEF");
	return (0);
}
