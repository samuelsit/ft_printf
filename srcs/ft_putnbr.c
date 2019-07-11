#include "../includes/ft_printf.h"

int	ft_putnbr(int n)
{
	int unit;
	int len;

	len = 0;
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			len = 11;
			ft_putchar('2');
			n = -147483648;
		}
		n = n * (-1);
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + 48);
		len++;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		unit = n % 10;
		len++;
		ft_putchar(unit + 48);
	}
	return (len);
}
