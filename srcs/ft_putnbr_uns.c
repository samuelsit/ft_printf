#include "../includes/ft_printf.h"

int ft_putnbr_uns(unsigned int nb)
{
	unsigned int res;
	int len;

	len = 0;
	res = 0;
	if (nb < 0)
	{
		res = 4294967296 + nb;
		ft_putnbr_uns(res);
		return (0);
	}
	if (nb / 10)
		ft_putnbr_uns(nb / 10);
	len++;
	ft_putchar(nb % 10 + '0');
	return (len);
}
