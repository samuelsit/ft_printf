#include "../../includes/ft_printf.h"

int ft_printf_u(va_list ap, int display, int tronc)
{
	unsigned int nb;
	int len;

	len = 0;
	nb = (unsigned int)va_arg(ap, int);
	ft_putnbr_uns_printf(nb, display, &len);
	return (len);
}
