#include "../includes/ft_printf.h"

int ft_printf_i(va_list ap)
{
	int nb;
	int len;

	len = 0;
	nb = va_arg(ap, int);
	len = ft_putnbr(nb);
	return (len);
}
