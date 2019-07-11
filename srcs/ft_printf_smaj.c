#include "../includes/ft_printf.h"

int ft_printf_smaj(va_list ap)
{
	char *str;
	int i;
	int len;

	len = 0;
	i = 0;
	str = va_arg(ap, char *);
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
		{
			len++;
			ft_putchar('\\');
			if (str[i] < 8)
				ft_putstr("00");
			else
				ft_putstr("0");
			ft_putnbr_base(str[i], "01234567");
		}
		else
			ft_putchar(str[i]);
		i++;
		len++;
	}
	return (len);
}
