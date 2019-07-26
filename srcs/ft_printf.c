#include "../includes/ft_printf.h"

int		putnchar_flag(int nb, char c)
{
	int i;

	i = 0;
	while (i < nb)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

int		is_arg_neg(const char *str, int *i, va_list ap)
{
	va_list aq;
	int nb;

	va_copy(aq, ap);
	nb = va_arg(aq, int);
	if (nb < 0)
		return (1);
	else
		return (0);
}

int 	do_flag(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc))
{
	int len;
	int j;

	len = 0;
	j = *i;
	if (str[*i] == 'l')
	{
		if (str[*i + 1] == 'l')
			len = flag_longlong(str, i, ap, tab_ft);
		else
			len = flag_long(str, i, ap, tab_ft);
	}
	else if (str[*i] == 'h')
		len = flag_h(str, i, ap, tab_ft);
	else if (str[*i] == '.')
		len = flag_dot(str, i, ap, tab_ft);
	else if (str[*i] == '#')
		len = flag_diese(str, i, ap, tab_ft);
	else if (str[*i] == '%')
		len = flag_mod(i);
	else if (str[*i] >= '0' && str[*i] <= '9')
	{
		while (str[j] >= '0' && str[j] <= '9')
			j++;
		if (str[j] == '.')
			len = flag_dot(str, i, ap, tab_ft);
		else
			len = flag_nb(str, i, ap, tab_ft);
	}
	else if (str[*i] == '+')
		len = flag_more(str, i, ap, tab_ft);
	else if (str[*i] == '-')
		len = flag_less(str, i, ap, tab_ft);
	else if ((str[*i] >= 'a' && str[*i] <= 'z') || (str[*i] >= 'A' && str[*i] <= 'Z'))
		len = flag_letter(str, i, ap, tab_ft);
	else
		(*i)++;
	return (len);
}

int		if_nomod(const char *str, int *i)
{
	ft_putchar(str[*i]);
	(*i)++;
	return (1);
}

int		if_mod(const char *str, int *i, va_list ap)
{
	int	(*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc);
	int len;
	int space_d;

	space_d = 0;
	len = 0;
	tab(tab_ft);
	(*i)++;
	while (str[*i] == ' ')
		(*i)++;
	if (!is_arg_neg(str, i, ap))
	{
		if (str[*i - 1] == ' ' && str[*i] == 'd')
		{
			ft_putchar(' ');
			space_d = 1;
		}
	}
	len = do_flag(str, i, ap, tab_ft);
	return (space_d == 1 ? len + 1 : len);
}

int		print(const char *str, va_list ap)
{
	int	i;
	int len;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			len += if_nomod(str, &i);
		else
			len += if_mod(str, &i, ap);
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
