#include "../includes/ft_printf.h"

int ft_printf_p(va_list ap)
{
	long long adr;
	int len;

	len = 2;
	adr = va_arg(ap, long long);
	ft_putstr("0x");
	len += ft_putnbr_base(adr, "0123456789abcdef");
	return (len);
}
