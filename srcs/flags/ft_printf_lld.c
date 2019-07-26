#include "../../includes/ft_printf.h"

int ft_printf_lld_display(long long int n)
{
	int len;

	len = 0;
    len++;
    if (n / 10)
        ft_printf_lld_display(n / 10);
    ft_putchar(n % 10 + '0');
    return (len);
}

int ft_printf_lld_hide(long long int n)
{
	int len;

	len = 0;
    len++;
    if (n / 10)
        ft_printf_lld_hide(n / 10);
    return (len);
}

int ft_printf_lld(va_list ap, int display, int tronc)
{
    int len;
    long long int n;

    len = 0;
    n = (long long int)va_arg(ap, long long int);
    len = len_nbr(n);
    if (display == 1)
        ft_printf_lld_display(n);
    else
        ft_printf_lld_hide(n);
    return (len);
}
