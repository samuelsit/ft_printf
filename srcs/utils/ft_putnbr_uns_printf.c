#include "../../includes/ft_printf.h"

int ft_putnbr_uns_printf(unsigned int nb, int display)
{
	unsigned int res;
	int len;

	len = 0;
	res = 0;
	if (nb < 0)
	{
		res = 4294967296 + nb;
		ft_putnbr_uns_printf(res, display);
		return (0);
	}
	if (nb / 10)
		ft_putnbr_uns_printf(nb / 10, display);
	len++;
	if (display == 1)
		ft_putchar(nb % 10 + '0');
	return (len);
}
