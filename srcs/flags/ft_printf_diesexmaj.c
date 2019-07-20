#include "../../includes/ft_printf.h"

int ft_printf_diesexmaj(va_list ap, int display, int tronc)
{
	int nb;
	int len;

	len = 0;
	nb = va_arg(ap, int);
	if (nb == 0)
	{
		if (display == 1)
			ft_putchar('0');
		return (1);
	}
	else
	{
		if (display == 1)
			ft_putstr("0X");
		len += 2;
	}
	len += ft_putnbr_base_printf(nb, "0123456789ABCDEF", display);
	return (len);
}
