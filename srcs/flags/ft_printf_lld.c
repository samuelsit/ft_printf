#include "../../includes/ft_printf.h"

int ft_printf_lld_display(unsigned long long int n)
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
        ft_printf_lld_display(n / 10);
    ft_putchar(n % 10 + '0');
    return (len);
}

int ft_printf_lld_hide(unsigned long long int n)
{
	int len;

	len = 0;
    if (n < 0) {
        len++;
        n = -n;
    }
    len++;
    if (n / 10)
        ft_printf_lld_hide(n / 10);
    return (len);
}

int ft_printf_lld(va_list ap, int display, int tronc)
{
    int len;
    unsigned long long n;

    len = 0;
    n = 0;
    n = va_arg(ap, long long);
    len = len_nbr(n);
    if (display == 1)
        ft_printf_lld_display(n);
    else
        ft_printf_lld_hide(n);
    if (n >= 0)
		return (len);
	else
		return (len + 1);
    return (len);
}
