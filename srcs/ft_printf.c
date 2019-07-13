#include "../includes/ft_printf.h"

int		tri_long_ft(char c)
{
	int		i;
	int		j;
	char	*flag;

	flag = "dio";
	i = 11;
	j = 0;
	while (flag[j] != c && flag[i] != '\0')
		j++;
	return (i + j);
}

int		tri_ft(char c)
{
	int		i;
	char	*flag;

	flag = "discoxXpuSb";
	i = 0;
	while (flag[i] != c && flag[i] != '\0')
		i++;
	return (i);
}

static void	tab(int (*tab_ft[NB_OPTIONS])(va_list ap, int display))
{
	tab_ft[0] = &ft_printf_d;
	tab_ft[1] = &ft_printf_d;
	tab_ft[2] = &ft_printf_s;
	tab_ft[3] = &ft_printf_c;
	tab_ft[4] = &ft_printf_o;
	tab_ft[5] = &ft_printf_x;
	tab_ft[6] = &ft_printf_xmaj;
	tab_ft[7] = &ft_printf_p;
	tab_ft[8] = &ft_printf_u;
	tab_ft[9] = &ft_printf_smaj;
	tab_ft[10] = &ft_printf_b;
	tab_ft[11] = &ft_printf_ld;
	tab_ft[12] = &ft_printf_ld;
	tab_ft[13] = &ft_printf_lo;
}

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

#include <stdio.h>

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
