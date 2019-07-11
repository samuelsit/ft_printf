#include "../includes/ft_printf.h"

int ft_printf_o(va_list ap)
{
	int nb;
	int len;

	len = 0;
	nb = va_arg(ap, int);
	len = ft_putnbr_base(nb, "01234567");
	return (len);
}
