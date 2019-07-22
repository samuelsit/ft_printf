#include "../includes/ft_printf.h"

void	tab(int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc))
{

//%[a-z]||[A-Z]
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
	tab_ft[11] = &ft_printf_zmaj;

//%l
	tab_ft[12] = &ft_printf_ld;
	tab_ft[13] = &ft_printf_ld;
	tab_ft[14] = &ft_printf_lo;
	tab_ft[15] = &ft_printf_lx;
	tab_ft[16] = &ft_printf_lu;

//%ll
	tab_ft[17] = &ft_printf_lld;
	tab_ft[18] = &ft_printf_lld;
	tab_ft[19] = &ft_printf_llo;
	tab_ft[20] = &ft_printf_llx;

//%#
	tab_ft[21] = &ft_printf_dieseo;
	tab_ft[22] = &ft_printf_diesex;
	tab_ft[23] = &ft_printf_diesexmaj;

//%h
	tab_ft[24] = &ft_printf_hd;
	tab_ft[25] = &ft_printf_hd;
	tab_ft[26] = &ft_printf_ho;
	tab_ft[27] = &ft_printf_hx;
	tab_ft[28] = &ft_printf_hxmaj;
}
