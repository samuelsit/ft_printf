#include "../../includes/ft_printf.h"

int ft_printf_hx(va_list ap, int display, int tronc)
{
	unsigned short nb;
	int len;

	len = 0;
	nb = (unsigned short)va_arg(ap, int);
	len += ft_putnbr_base_printf(nb, "0123456789abcdef", display);
	return (len);
}
