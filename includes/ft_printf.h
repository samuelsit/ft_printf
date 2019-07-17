#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define NB_OPTIONS 15
# define NO_TRONC   99999999

int				ft_atoi_printf(const char *str);
int	len_nbr(long long n);
size_t	ft_strlen(const char *s);
int	ft_putnbr_printf(int n, int display);
int	ft_putnbr_uns_printf(unsigned int nb, int display, int *len);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
int		ft_putstr_tronc(char const *s, int tronc);
int ft_putnbr_base_printf(long long nbr, char const *base, int display);
int	ft_putnbr_printf_float(double n, int display);
int ft_printf_lx(va_list ap, int display, int tronc);
int ft_printf_lo(va_list ap, int display, int tronc);
int ft_printf_ld(va_list ap, int display, int tronc);
int	ft_printf_b(va_list ap, int display, int tronc);
int	ft_printf_c(va_list ap, int display, int tronc);
int	ft_printf_d(va_list ap, int display, int tronc);
int	ft_printf_o(va_list ap, int display, int tronc);
int	ft_printf_p(va_list ap, int display, int tronc);
int	ft_printf_smaj(va_list ap, int display, int tronc);
int	ft_printf_s(va_list ap, int display, int tronc);
int	ft_printf_u(va_list ap, int display, int tronc);
int	ft_printf_xmaj(va_list ap, int display, int tronc);
int	ft_printf_x(va_list ap, int display, int tronc);
int	ft_printf(char const *str, ...);
int		tri_long_ft(char c);
int		tri_ft(char c);
void	tab(int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc));
int	    flag_mod(int *i);
int		flag_less(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc));
int		flag_more(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc));
int		flag_nb(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc));
int		flag_long(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc));
int		flag_letter(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc));
int		flag_dot(const char *str, int *i, va_list ap, int (*tab_ft[NB_OPTIONS])(va_list ap, int display, int tronc));
int		putnchar_flag(int nb, char c);

#endif
