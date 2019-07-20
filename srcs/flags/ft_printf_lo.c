#include "../../includes/ft_printf.h"

int ft_printf_lo(va_list ap, int display, int tronc)
{
	long int nb;
	int len;

	len = 0;
	nb = va_arg(ap, long);
	len = ft_putnbr_base_printf(nb, "01234567", display);
	return (len);
}
