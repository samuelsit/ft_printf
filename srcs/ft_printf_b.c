#include "../includes/ft_printf.h"

int ft_printf_b(va_list ap)
{
	int nb;

	nb = va_arg(ap, int);
	ft_putnbr_base(nb, "01");
	return (0);
}
