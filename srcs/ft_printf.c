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

void	if_nomod(const char *str, int *i, int *len)
{
	if (str[*i] != '%')
	{
		ft_putchar(str[*i]);
		(*len)++;
		(*i)++;
	}
}

void	if_mod(const char *str, int *i, int *len, va_list ap)
{
	int n;
	va_list aq;
	int	(*tab_ft[NB_OPTIONS])(va_list ap, int display);
	int nbspace;
	int lenmod;

	lenmod = 0;
	nbspace = 0;
	tab(tab_ft);
	n = 0;
	if (str[*i] == '%')
	{
		(*i)++;
		while (str[*i] == 32)
			(*i)++;
		if (str[*i] == '%')
		{
			ft_putchar('%');
			(*len)++;
			(*i)++;
		}
		else if (str[*i] == 'l' && str[*i + 1] > 32)
		{
			n = tri_long_ft(str[*i + 1]);
			*len += tab_ft[n](ap, 1);
			*i += 2;
		}
		else if ((str[*i] >= 'a' && str[*i] <= 'z') || (str[*i] >= 'A' && str[*i] <= 'Z'))
		{
			n = tri_ft(str[*i]);
			*len += tab_ft[n](ap, 1);
			(*i)++;
		}
		else if (str[*i] >= '0' && str[*i] <= '9')
		{
			nbspace = ft_atoi_printf(&str[*i]);
			*len += nbspace;
			while (str[*i] >= '0' && str[*i] <= '9')
				(*i)++;
			if ((str[*i] >= 'a' && str[*i] <= 'z') || (str[*i] >= 'A' && str[*i] <= 'Z'))
			{
				n = tri_ft(str[*i]);
				va_copy(aq, ap);
				lenmod = tab_ft[n](ap, 0);
				putspace(nbspace - lenmod);
				lenmod = tab_ft[n](aq, 1);
			}
			if (str[*i] == '%')
			{
				putspace(nbspace - 1);
				ft_putchar('%');
			}
			(*i)++;
		}
		else if (str[*i] == '+')
		{
			(*i)++;
			nbspace = ft_atoi_printf(&str[*i]);
			*len += nbspace;
			while (str[*i] >= '0' && str[*i] <= '9')
				(*i)++;
			if ((str[*i] >= 'a' && str[*i] <= 'z') || (str[*i] >= 'A' && str[*i] <= 'Z'))
			{
				n = tri_ft(str[*i]);
				va_copy(aq, ap);
				lenmod = tab_ft[n](ap, 0) + 1;
				putspace(nbspace - lenmod);
				ft_putchar('+');
				lenmod = tab_ft[n](aq, 1);
			}
			if (str[*i] == '%')
			{
				putspace(nbspace - 1);
				ft_putchar('%');
			}
			(*i)++;
		}
		else if (str[*i] == '-')
		{
			(*i)++;
			nbspace = ft_atoi_printf(&str[*i]);
			*len += nbspace;
			while (str[*i] >= '0' && str[*i] <= '9')
				(*i)++;
			if ((str[*i] >= 'a' && str[*i] <= 'z') || (str[*i] >= 'A' && str[*i] <= 'Z'))
			{
				n = tri_ft(str[*i]);
				lenmod = tab_ft[n](ap, 1);
				putspace(nbspace - lenmod);
			}
			if (str[*i] == '%')
			{
				ft_putchar('%');
				putspace(nbspace - 1);
			}
			(*i)++;
		}
	}
	va_end(aq);
}

int		print(const char *str, va_list ap)
{
	int	i;
	int len;

	len = 0;
	i = 0;
	while (str[i])
	{
		if_nomod(str, &i, &len);
		if_mod(str, &i, &len, ap);
	}
	return (len);
}

int		ft_printf(const char *str, ...)
{
	int len;
	va_list	ap;

	va_start(ap, str);
	len = print(str, ap);
	va_end(ap);
	return (len);
}
