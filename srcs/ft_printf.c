#include "../includes/ft_printf.h"

int		putspace(int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int		ft_printf(const char *str, ...)
{
	int nbspace;
	int lenmod;
	int	n;
	int len;
	int	i;
	int	(*tab_ft[NB_OPTIONS])(va_list ap, int display);
	va_list	ap;
	va_list aq;

	va_start(ap, str);
	n = 0;
	lenmod = 0;
	nbspace = 0;
	len = 0;
	i = 0;
	tab(tab_ft);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			len++;
			i++;
		}
		if (str[i] == '%')
		{
			i++;
			while (str[i] == 32)
				i++;
			if (str[i] == '%')
			{
				ft_putchar('%');
				len++;
				i++;
			}
			else if (str[i] == 'l' && str[i + 1] > 32)
			{
				n = tri_long_ft(str[i + 1]);
				len += tab_ft[n](ap, 1);
				i += 2;
			}
			else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			{
				n = tri_ft(str[i]);
				len += tab_ft[n](ap, 1);
				i++;
			}
			else if (str[i] >= '0' && str[i] <= '9')
			{
				nbspace = ft_atoi_printf(&str[i]);
				len += nbspace;
				while (str[i] >= '0' && str[i] <= '9')
					i++;
				if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
				{
					n = tri_ft(str[i]);
					va_copy(aq, ap);
					lenmod = tab_ft[n](ap, 0);
					putspace(nbspace - lenmod);
					lenmod = tab_ft[n](aq, 1);
				}
				if (str[i] == '%')
				{
					putspace(nbspace - 1);
					ft_putchar('%');
				}
				i++;
			}
			else if (str[i] == '+')
			{
				i++;
				nbspace = ft_atoi_printf(&str[i]);
				len += nbspace;
				while (str[i] >= '0' && str[i] <= '9')
					i++;
				if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
				{
					n = tri_ft(str[i]);
					va_copy(aq, ap);
					lenmod = tab_ft[n](ap, 0) + 1;
					putspace(nbspace - lenmod);
					ft_putchar('+');
					lenmod = tab_ft[n](aq, 1);
				}
				if (str[i] == '%')
				{
					putspace(nbspace - 1);
					ft_putchar('%');
				}
				i++;
			}
			else if (str[i] == '-')
			{
				i++;
				nbspace = ft_atoi_printf(&str[i]);
				len += nbspace;
				while (str[i] >= '0' && str[i] <= '9')
					i++;
				if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
				{
					n = tri_ft(str[i]);
					lenmod = tab_ft[n](ap, 1);
					putspace(nbspace - lenmod);
				}
				if (str[i] == '%')
				{
					ft_putchar('%');
					putspace(nbspace - 1);
				}
				i++;
			}
		}
	}
	va_end(ap);
	va_end(aq);
	return (len);
}
