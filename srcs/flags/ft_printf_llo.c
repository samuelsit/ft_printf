#include "../../includes/ft_printf.h"

int ft_printf_llo(va_list ap, int display, int tronc)
{
	long long int nb;
	int len;

	len = 0;
	nb = (long long int)va_arg(ap, long long int);
	len = ft_putnbr_base_printf(nb, "01234567", display);
    return (len);

}
