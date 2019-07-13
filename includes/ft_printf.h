#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define NB_OPTIONS 12

int				ft_atoi_printf(const char *str);
size_t	ft_strlen(const char *s);
int	ft_putnbr_printf(int n, int display);
int	ft_putnbr_uns_printf(unsigned int nb, int display);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
int ft_putnbr_base_printf(long long nbr, char const *base, int display);
int	ft_printf(char const *str, ...);
int ft_printf_l(va_list ap, int display);
int	ft_printf_b(va_list ap, int display);
int	ft_printf_c(va_list ap, int display);
int	ft_printf_d(va_list ap, int display);
int	ft_printf_i(va_list ap, int display);
int	ft_printf_o(va_list ap, int display);
int	ft_printf_p(va_list ap, int display);
int	ft_printf_smaj(va_list ap, int display);
int	ft_printf_s(va_list ap, int display);
int	ft_printf_u(va_list ap, int display);
int	ft_printf_xmaj(va_list ap, int display);
int	ft_printf_x(va_list ap, int display);

#endif
