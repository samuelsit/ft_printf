#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define NB_OPTIONS 11

size_t	ft_strlen(const char *s);
void	ft_putnbr(int n);
int	ft_putnbr_uns(unsigned int nb);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
int	ft_putnbr_base(long long nb, char const *base);
int	ft_printf(char const *str, ...);
int	ft_printf_b(va_list ap);
int	ft_printf_c(va_list ap);
int	ft_printf_d(va_list ap);
int	ft_printf_i(va_list ap);
int	ft_printf_o(va_list ap);
int	ft_printf_p(va_list ap);
int	ft_printf_smaj(va_list ap);
int	ft_printf_s(va_list ap);
int	ft_printf_u(va_list ap);
int	ft_printf_xmaj(va_list ap);
int	ft_printf_x(va_list ap);

#endif
