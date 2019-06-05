#include "../includes/ft_printf.h"

int ft_printf_s(va_list ap)
{
	char *str;

	str = va_arg(ap, char *);
	ft_putstr(str);
	return (0);
}
