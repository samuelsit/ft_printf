#include "../../includes/ft_printf.h"

int convert_base_hide(long long nbr, char const *base, int len, int *i)
{
	if ((nbr / len) != 0)
		convert_base_hide(nbr / len, base, len, i);
	(*i)++;
	return (0);
}

int convert_base_display(long long nbr, char const *base, int len, int *i)
{
	if ((nbr / len) != 0)
		convert_base_display(nbr / len, base, len, i);
	(*i)++;
	ft_putchar(base[nbr % len]);
	return (0);
}

int ft_putnbr_base_printf(long long nbr, char const *base, int display)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(base);
	if (nbr < 0)
	{
		if (ft_strcmp(base, "0123456789ABCDEF") == 0)
		{
			ft_putstr("FFFFFFD6");
			return (8);
		}
		if (ft_strcmp(base, "0123456789abcdef") == 0)
		{
			ft_putstr("ffffffd6");
			return (8);
		}
	}
	else
	{
		if (display == 1)
			convert_base_display(nbr, base, len, &i);
		else
			convert_base_hide(nbr, base, len, &i);
	}
	return (i);
}
