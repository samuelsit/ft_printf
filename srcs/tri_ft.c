#include "../includes/ft_printf.h"

int		tri_long_ft(char c)
{
	int		i;
	int		j;
	char	*flag;

	flag = "diox";
	i = 12;
	j = 0;
	while (flag[j] != c && flag[i] != '\0')
		j++;
	return (i + j);
}

int		tri_ft(char c)
{
	int		i;
	char	*flag;

	flag = "discoxXpuSbf";
	i = 0;
	while (flag[i] != c && flag[i] != '\0')
		i++;
	return (i);
}
