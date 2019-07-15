#include "../../includes/ft_printf.h"

int	ft_putnbr_hide(int n)
{
	int len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_putnbr_display(int n)
{
	int unit;
	int len;

	len = ft_putnbr_hide(n);
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			n = -147483648;
		}
		n = n * (-1);
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48);
	if (n >= 10)
	{
		ft_putnbr_display(n / 10);
		unit = n % 10;
		ft_putchar(unit + 48);
	}
	return (len);
}

int	ft_putnbr_printf(int n, int display)
{
	int len;

	len = 0;
	if (display == 1)
		len = ft_putnbr_display(n);
	else
		len = ft_putnbr_hide(n);
	return (len);
}
