#include "../../includes/ft_printf.h"

int ft_printf_ho(va_list ap, int display, int tronc)
{
	int nb;
	int len;

	len = 0;
	nb = va_arg(ap, int);
	ft_putchar('0');
	len++;
	len += ft_putnbr_base_printf(nb, "01234567", display);
	return (len);
}
