#include "../../includes/ft_printf.h"

int	ft_putnbr_f_hide(double n)
{
    int cpt;
    int value;
    char buffer[32];
	int len;

	len = 0;
	cpt = 0;
    while (cpt++ < 5)
        n *= 10.0;
    if(n < 0.0)
    {
		len++;
        n = 0.0 - n;
    }
    value = (int)(n += 0.5);
    cpt = 0;
    while(value)
    {
        buffer[cpt++] = ((value % 10) + '0');
        value = value / 10;
        if(cpt == 5)
            buffer[cpt++] = '.';
    }
    while(cpt--)
		len++;
	return (len);
}

int	ft_putnbr_f_display(double n)
{
    int cpt;
    int value;
    char buffer[32];
	int len;

	len = 0;
	cpt = 0;
    while (cpt++ < 5)
        n *= 10.0;
    if(n < 0.0)
    {
        ft_putchar('-');
		len++;
        n = 0.0 - n;
    }
    value = (int)(n += 0.5);
    cpt = 0;
    while(value)
    {
        buffer[cpt++] = ((value % 10) + '0');
        value = value / 10;
        if(cpt == 5)
            buffer[cpt++] = '.';
    }
    while(cpt--)
	{
        ft_putchar(buffer[cpt]);
		len++;
	}
	return (len);
}

int	ft_putnbr_printf_float(double n, int display)
{
	int len;

	len = 0;
	if (display == 1)
		len = ft_putnbr_f_display(n);
	else
		len = ft_putnbr_f_hide(n);
	return (len);
}
