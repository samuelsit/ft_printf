#include "../includes/ft_printf.h"

int ft_printf_smaj(va_list ap, int display)
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
			if (display == 1)
			{
				len++;
				ft_putchar('\\');
				if (str[i] < 8)
				{
					ft_putstr("00");
					len += 2;
				}
				else
				{
					ft_putchar('0');
					len++;
				}
			}
			len += ft_putnbr_base_printf(str[i], "01234567", display);
		}
		else
		{
			if (display == 1)
				ft_putchar(str[i]);
		}
		i++;
		len++;
	}
	return (len);
}
