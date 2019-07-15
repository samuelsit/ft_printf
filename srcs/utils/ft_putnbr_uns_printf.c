#include "../../includes/ft_printf.h"

int ft_putnbr_uns_printf(unsigned int nb, int display)
{
	int len;

	len = 0;
	if (nb / 10)
		ft_putnbr_uns_printf(nb / 10, display);
	len++;
	if (display == 1)
		ft_putchar(nb % 10 + '0');
	return (len);
}
