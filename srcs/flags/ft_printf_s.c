#include "../../includes/ft_printf.h"

int ft_printf_s(va_list ap, int display, int tronc)
{
	int		n;
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (tronc != NO_TRONC && tronc != 0)
		n = ft_putstr_tronc(str, tronc, display);
	else
	{
		if (display == 1)
			ft_putstr(str);
		n = ft_strlen(str);
	}
	return (n);
}
