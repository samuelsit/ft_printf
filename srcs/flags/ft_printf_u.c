#include "../../includes/ft_printf.h"

int ft_printf_u(va_list ap, int display, int tronc)
{
	int nb;
	int len;

	len = 0;
	nb = va_arg(ap, unsigned int);
	ft_putnbr_uns_printf(nb, display, &len);
	return (len);
}
