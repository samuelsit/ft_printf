#include "../includes/ft_printf.h"

int		tri_ft(char c)
{
	int	i = 0;
	char	*str;

	str = "discoxXpuSb";
	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (84);
	return (i);
}

static void	tab(int (*tab_ft[NB_OPTIONS])(va_list ap))
{
	tab_ft[0] = &ft_printf_d;
	tab_ft[1] = &ft_printf_i;
	tab_ft[2] = &ft_printf_s;
	tab_ft[3] = &ft_printf_c;
	tab_ft[4] = &ft_printf_o;
	tab_ft[5] = &ft_printf_x;
	tab_ft[6] = &ft_printf_xmaj;
	tab_ft[7] = &ft_printf_p;
	tab_ft[8] = &ft_printf_u;
	tab_ft[9] = &ft_printf_smaj;
	tab_ft[10] = &ft_printf_b;
}

int		ft_printf(char const *str, ...)
{
	int	n;
	int	i;
	int	(*tab_ft[NB_OPTIONS])(va_list ap);
	va_list	ap;

	va_start(ap, str);
	n = 0;
	i = 0;
	tab(tab_ft);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i]);
		else if (str[i + 1] == '%')
		{
			i++;
			ft_putchar('%');
		}
		else
		{
			i++;
			n = tri_ft(str[i]);
			tab_ft[n](ap);
		}
		i++;
	}
	va_end(ap);
	return (n);
}
