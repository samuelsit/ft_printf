#include "../../includes/ft_printf.h"

int ft_printf_ld_display(long int n)
{
	int len;

	len = 0;
    if (n < 0) {
        ft_putchar('-');
        len++;
        n = -n;
    }
    len++;
    if (n / 10)
        ft_printf_ld_display(n / 10);
    ft_putchar(n % 10 + '0');
    return (len);
}

int ft_printf_ld_hide(long int n)
{
	int len;

	len = 0;
    if (n < 0) {
        len++;
        n = -n;
    }
    len++;
    if (n / 10)
        ft_printf_ld_hide(n / 10);
    return (len);
}

int lennb(long int n)
{
    int i;

    i = 0;
    while (n)
    {
        n /= 10;
        i++;
    }
    return (i);
}

int ft_printf_ld(va_list ap, int display, int tronc)
{
    int len;
    long int n;

    len = 0;
    n = 0;
    n = va_arg(ap, long int);
    len = lennb(n);
    if (display == 1)
        ft_printf_ld_display(n);
    else
        ft_printf_ld_hide(n);
    if (n >= 0)
		return (len);
	else
		return (len + 1);
    return (len);
}
