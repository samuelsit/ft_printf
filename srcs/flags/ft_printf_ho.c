#include "../../includes/ft_printf.h"

int ft_printf_ho(va_list ap, int display, int tronc)
{
	unsigned short nb;
	int len;

	len = 0;
	nb = (unsigned short)va_arg(ap, int);
	len += ft_putnbr_base_printf(nb, "01234567", display);
	return (len);
}
