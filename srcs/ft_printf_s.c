#include "../includes/ft_printf.h"

int ft_printf_s(va_list ap, int display)
{
	int		n;
	char	*str;

	str = va_arg(ap, char *);
	if (display == 1)
		ft_putstr(str);
	n = ft_strlen(str);
	return (n);
}
