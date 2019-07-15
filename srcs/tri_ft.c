#include "../includes/ft_printf.h"

int		tri_long_ft(char c)
{
	int		i;
	int		j;
	char	*flag;

	flag = "diox";
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

void	tab(int (*tab_ft[NB_OPTIONS])(va_list ap, int display))
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
	tab_ft[14] = &ft_printf_lx;
}
