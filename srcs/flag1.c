#include "../includes/ft_printf.h"

int		flag_mod(int *i)
{
	int len;

	len = 0;
	ft_putchar('%');
	len++;
	(*i)++;
	return (len);
}

int		flag(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display))
{
	int n;
	int len;

	n = 0;
	len = 0;
	n = tri_ft(str[*i]);
	len = tab_ft[n](ap, 1);
	(*i)++;
	return (len);
}

int		flag_long(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display))
{
	int n;
	int len;

	n = 0;
	len = 0;
	n = tri_long_ft(str[*i + 1]);
	len += tab_ft[n](ap, 1);
	*i += 2;
	return (len);
}

int		flag_nb(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display))
{
	int n;
	int nbspace;
	va_list aq;
	int len;
	int lenmod;

	n = 0;
	len = 0;
	nbspace = 0;
	lenmod = 0;
	nbspace = ft_atoi_printf(&str[*i]);
	len += nbspace;
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
	va_end(aq);
	return (len);
}

int		flag_more(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display))
{
	int n;
	int nbspace;
	int lenmod;
	int len;
	va_list aq;

	n = 0;
	nbspace = 0;
	lenmod = 0;
	len = 0;
	(*i)++;
	nbspace = ft_atoi_printf(&str[*i]);
	len += nbspace;
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
	va_end(aq);
	return (len);
}

int		flag_less(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display))
{
	int n;
	int nbspace;
	int lenmod;
	int len;
	va_list aq;

	n = 0;
	nbspace = 0;
	lenmod = 0;
	len = 0;
	(*i)++;
	nbspace = ft_atoi_printf(&str[*i]);
	len += nbspace;
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
	va_end(aq);
	return (len);
}
