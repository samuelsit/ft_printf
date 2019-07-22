#include "../../includes/ft_printf.h"

int ft_printf_hd(va_list ap, int display, int tronc)
{
	short int nb;
	int len;

	len = 0;
	nb = (short int)va_arg(ap, int);
	if (tronc != NO_TRONC && tronc != 0)
	{
		len = len_nbr(nb);
		putnchar_flag(tronc - len, '0');
		len = tronc;
		ft_putnbr_printf(nb, display);
	}
	else
	{
		len = ft_putnbr_printf(nb, display);
		if (nb < 0)
			len++;
	}
	return (len);
}
