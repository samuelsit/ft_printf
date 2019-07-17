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

int 	do_flag(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc))
{
	int len;

	len = 0;
	if (str[*i] == 'l' && str[*i + 1] > 32)
		len = flag_long(str, i, ap, tab_ft);
	else if (str[*i] == '.')
		len = flag_dot(str, i, ap, tab_ft);
	else if (str[*i] == '%')
		len = flag_mod(i);
	else if (str[*i] >= '0' && str[*i] <= '9')
		len = flag_nb(str, i, ap, tab_ft);
	else if (str[*i] == '+')
		len = flag_more(str, i, ap, tab_ft);
	else if (str[*i] == '-')
		len = flag_less(str, i, ap, tab_ft);
	else if ((str[*i] >= 'a' && str[*i] <= 'z') || (str[*i] >= 'A' && str[*i] <= 'Z'))
		len = flag_letter(str, i, ap, tab_ft);
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

	len = 0;
	tab(tab_ft);
	(*i)++;
	while (str[*i] == 32)
		(*i)++;
	len = do_flag(str, i, ap, tab_ft);
	return (len);
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
