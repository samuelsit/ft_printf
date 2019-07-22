#include "../../includes/ft_printf.h"

int ft_printf_lu(va_list ap, int display, int tronc)
{
	unsigned long nb;
	int len;

	len = 0;
	nb = (unsigned long)va_arg(ap, long);
	ft_putnbr_uns_printf(nb, display, &len);
	return (len);
}
