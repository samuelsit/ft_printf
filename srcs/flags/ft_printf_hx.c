#include "../../includes/ft_printf.h"

int ft_printf_hx(va_list ap, int display, int tronc)
{
	int nb;
	int len;

	len = 0;
	nb = va_arg(ap, int);
	if (nb == 0)
		ft_putchar('0');
	else
	{
		ft_putstr("0x");
		len++;
	}
	len++;
	len += ft_putnbr_base_printf(nb, "0123456789abcdef", display);
	return (len);
}
