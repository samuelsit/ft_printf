#include "../includes/ft_printf.h"

int convert_base(long long nbr, char const *base, int len, int *i)
{
	if ((nbr / len) != 0)
		convert_base(nbr / len, base, len, i);
	(*i)++;
	ft_putchar(base[nbr % len]);
	return (0);
}

int ft_putnbr_base(long long nbr, char const *base)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= - 1;
		ft_putchar('-');
	}
	i += convert_base(nbr, base, len, &i);
	return (i);
}
