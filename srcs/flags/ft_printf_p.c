#include "../../includes/ft_printf.h"

int ft_printf_p(va_list ap, int display)
{
	long long adr;
	int len;

	len = 2;
	adr = va_arg(ap, long long);
	if (display == 1)
		ft_putstr("0x");
	len += ft_putnbr_base_printf(adr, "0123456789abcdef", display);
	return (len);
}
