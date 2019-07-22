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

int		flag_letter(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc))
{
	int n;
	int len;

	n = 0;
	len = 0;
	n = tri_ft(str[*i]);
	len = tab_ft[n](ap, 1, NO_TRONC);
	(*i)++;
	return (len);
}

int		flag_h(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc))
{
	int n;
	int len;

	len = 0;
	n = tri_h_ft(str[*i + 1]);
	len += tab_ft[n](ap, 1, NO_TRONC);
	*i += 2;
	return (len);
}

int		flag_long(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc))
{
	int n;
	int len;

	len = 0;
	n = tri_long_ft(str[*i + 1]);
	len += tab_ft[n](ap, 1, NO_TRONC);
	*i += 2;
	return (len);
}

int		flag_longlong(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc))
{
	int n;
	int len;

	n = 0;
	len = 0;
	n = tri_longlong_ft(str[*i + 2]);
	len += tab_ft[n](ap, 1, NO_TRONC);
	*i += 3;
	return (len);
}

int		flag_diese(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc))
{
	int n;
	int nbspace;
	va_list aq;
	int len;
	int lenmod;
	int is_zero;

	n = 0;
	len = 0;
	nbspace = 0;
	lenmod = 0;
	nbspace = ft_atoi_printf(&str[*i]);
	len = nbspace;
	is_zero = 0;
	(*i)++;
	if (str[*i] == '0')
		is_zero = 1;
	while (str[*i] == ' ')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	if ((str[*i] >= 'a' && str[*i] <= 'z') || (str[*i] >= 'A' && str[*i] <= 'Z'))
	{
		n = tri_diese_ft(str[*i]);
		va_copy(aq, ap);
		lenmod = tab_ft[n](ap, 0, NO_TRONC);
		if (is_zero == 1)
			putnchar_flag(nbspace - lenmod, '0');
		else
			putnchar_flag(nbspace - lenmod, ' ');
		if (nbspace > lenmod)
			lenmod = tab_ft[n](aq, 1, NO_TRONC);
		else
			len = tab_ft[n](aq, 1, NO_TRONC);
	}
	(*i)++;
	va_end(aq);
	return (len);
}

int		flag_nb(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc))
{
	int n;
	int nbspace;
	va_list aq;
	int len;
	int lenmod;
	int is_zero;

	n = 0;
	len = 0;
	nbspace = 0;
	lenmod = 0;
	nbspace = ft_atoi_printf(&str[*i]);
	len += nbspace;
	is_zero = 0;
	if (str[*i] == '0')
		is_zero = 1;
	while (str[*i] == ' ')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	if ((str[*i] >= 'a' && str[*i] <= 'z') || (str[*i] >= 'A' && str[*i] <= 'Z'))
	{
		n = tri_ft(str[*i]);
		va_copy(aq, ap);
		lenmod = tab_ft[n](ap, 0, NO_TRONC);
		if (is_zero == 1)
			putnchar_flag(nbspace - lenmod, '0');
		else
			putnchar_flag(nbspace - lenmod, ' ');
		if (nbspace > lenmod)
			lenmod = tab_ft[n](aq, 1, NO_TRONC);
		else
			len = tab_ft[n](aq, 1, NO_TRONC);
	}
	if (str[*i] == '%')
	{
		putnchar_flag(nbspace - 1, ' ');
		ft_putchar('%');
	}
	(*i)++;
	va_end(aq);
	return (len);
}

int		flag_more(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc))
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
		while (str[*i] == 32)
			(*i)++;
	if ((str[*i] >= 'a' && str[*i] <= 'z') || (str[*i] >= 'A' && str[*i] <= 'Z'))
	{

		n = tri_ft(str[*i]);
		va_copy(aq, ap);
		lenmod = tab_ft[n](ap, 0, NO_TRONC) + 1;
		putnchar_flag(nbspace - lenmod, ' ');
		ft_putchar('+');
		len++;
		if (nbspace > lenmod)
			lenmod = tab_ft[n](aq, 1, NO_TRONC);
		else
			len += tab_ft[n](aq, 1, NO_TRONC);
	}
	if (str[*i] == '%')
	{
		putnchar_flag(nbspace - 1, ' ');
		ft_putchar('%');
	}
	(*i)++;
	va_end(aq);
	return (len);
}

int		flag_less(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc))
{
	int n;
	int nbspace;
	int lenmod;
	int len;
	va_list aq;

	n = 0;
	lenmod = 0;
	(*i)++;
	nbspace = ft_atoi_printf(&str[*i]);
	len = nbspace;
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	if ((str[*i] >= 'a' && str[*i] <= 'z') || (str[*i] >= 'A' && str[*i] <= 'Z'))
	{
		n = tri_ft(str[*i]);
		va_copy(aq, ap);
		lenmod = tab_ft[n](ap, 0, NO_TRONC);
		if (nbspace > lenmod)
			lenmod = tab_ft[n](aq, 1, NO_TRONC);
		else
			len = tab_ft[n](aq, 1, NO_TRONC);
		putnchar_flag(nbspace - lenmod, ' ');
	}
	if (str[*i] == '%')
	{
		ft_putchar('%');
		putnchar_flag(nbspace - 1, ' ');
	}
	(*i)++;
	va_end(aq);
	return (len);
}

int		flag_dot(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc))
{
	int n;
	int tronc;
	int len;

	tronc = ft_atoi_printf(&str[*i + 1]);
	*i += len_nbr(tronc) + 1;
	if (str[*i] == '%')
	{
		ft_putchar('%');
		return (1);
	}
	n = tri_ft(str[*i]);
	len = tab_ft[n](ap, 1, tronc);
	(*i)++;
	return (len);
}
