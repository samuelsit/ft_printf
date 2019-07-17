#include "../../includes/ft_printf.h"

int ft_printf_d(va_list ap, int display, int tronc)
{
	int nb;
	int len;

	len = 0;
	nb = va_arg(ap, int);
	len = ft_putnbr_printf(nb, display);
	if (nb >= 0)
		return (len);
	else
		return (len + 1);
}
