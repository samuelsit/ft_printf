#include "../../includes/ft_printf.h"

int ft_printf_f(va_list ap, int display)
{
	float nb;
	int len;

	nb = va_arg(ap, double);
	len = ft_putnbr_printf_float(nb, display);
	if (nb >= 0)
		return (len);
	else
		return (len + 1);
}
