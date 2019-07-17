#include "../../includes/ft_printf.h"

int ft_printf_c(va_list ap, int display, int tronc)
{
	char c;

	c = va_arg(ap, int);
	if (display == 1)
		ft_putchar(c);
	return (1);
}
