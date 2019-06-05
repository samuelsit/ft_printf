#include "../includes/ft_printf.h"

int convert_base(long long nbr, char const *base, int len)
{
	if ((nbr / len) != 0)
		convert_base(nbr / len, base, len);
	ft_putchar(base[nbr % len]);
	return (0);
}

int ft_putnbr_base(long long nbr, char const *base)
{
	int len;

	len = ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= - 1;
		ft_putchar('-');
	}
	convert_base(nbr, base, len);
	return (0);
}
