#include "../includes/ft_printf.h"

int		flag_mod(int *i)
{
	ft_putchar('%');
	(*i)++;
	return (1);
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
	while (str[*i] == 'l')
		(*i)++;
	n = tri_longlong_ft(str[*i]);
	len += tab_ft[n](ap, 1, NO_TRONC);
	(*i)++;
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
	is_zero = 0;
	(*i)++;
	nbspace = ft_atoi_printf(&str[*i]);
//	printf("str[*i]=%s; nbspace=%d\n", &str[*i], nbspace);
	len = nbspace;
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
		//printf("nbspace = %d, lenmod = %d\n", nbspace, lenmod);
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
	int argz;
	char sign;
	va_list aq;
	va_list az;

	n = 0;
	nbspace = 0;
	lenmod = 0;
	len = 0;
	argz = 0;
	nbspace = ft_atoi_printf(&str[*i]);
	len += nbspace;
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] == '+')
		sign = '+';
	if (str[*i] == '-')
		sign = '-';
	while (str[*i] == '+' || str[*i] == '-')
		(*i)++;
	while (str[*i] == ' ')
		(*i)++;
	if ((str[*i] >= 'a' && str[*i] <= 'z') || (str[*i] >= 'A' && str[*i] <= 'Z'))
	{
		n = tri_ft(str[*i]);
		va_copy(aq, ap);
		va_copy(az, ap);
		lenmod = tab_ft[n](ap, 0, NO_TRONC) + 1;
		putnchar_flag(nbspace - lenmod, ' ');
		argz = va_arg(az, int);
		if (argz >= 0 && sign == '+')
		{
			ft_putchar('+');
			len++;
		}
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
	va_end(az);
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
	int space;
	va_list aq;
	va_list az;
	int lenmod;

	space = 0;
	lenmod = 0;
	if (str[*i] >= '0' && str[*i] <= '9')
	{
		space = ft_atoi_printf(&str[*i]);
		while (str[*i] >= '0' && str[*i] <= '9')
			(*i)++;
		len = space;
	}
	(*i)++;
	tronc = ft_atoi_printf(&str[*i]);
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	if (str[*i] == '%')
		return (flag_mod(i));
	if ((str[*i] >= 'a' && str[*i] <= 'z') || (str[*i] >= 'A' && str[*i] <= 'Z'))
	{
		n = tri_ft(str[*i]);
		if (n != 2 && n != 3 && n != 7)
		{
			va_copy(az, ap);
			lenmod = va_arg(az, int);
			if (lenmod == 0)
			{
				while ((str[*i] >= 'a' && str[*i] <= 'z') || (str[*i] >= 'A' && str[*i] <= 'Z'))
					(*i)++;
				return (0);
			}
		}
		va_copy(aq, ap);
		lenmod = tab_ft[n](ap, 0, tronc);
		if (space > lenmod)
		{
			putnchar_flag(space - lenmod, ' ');
			lenmod = tab_ft[n](aq, 1, tronc);
		}
		else
			len = tab_ft[n](aq, 1, tronc);
	}
	(*i)++;
	va_end(aq);
	va_end(az);
	return (len);
}
