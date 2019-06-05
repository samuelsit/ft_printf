#include "../includes/ft_printf.h"

int ft_printf_c(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	ft_putchar(c);
	return (0);
}
