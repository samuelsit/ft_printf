#include "../../includes/ft_printf.h"

int ft_printf_b(va_list ap, int display)
{
	int nb;
	int len;

	len = 0;
	nb = va_arg(ap, int);
	len = ft_putnbr_base_printf(nb, "01", display);
	return (len);
}
