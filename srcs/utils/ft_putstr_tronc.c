#include "../../includes/ft_printf.h"

int		ft_putstr_tronc(char const *s, int tronc, int display)
{
	int i;

	i = 0;
	while (i <= tronc - 1)
	{
		if (display == 1)
			ft_putchar(s[i]);
		i++;
	}
	return(i);
}
