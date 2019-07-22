#include "../includes/ft_printf.h"

int		tri_h_ft(char c)
{
	int		i;
	int		j;
	char	*flag;

	flag = "dioxX";
	i = 24;
	j = 0;
	while (flag[j] != c && flag[i] != '\0')
		j++;
	return (i + j);
}

int		tri_diese_ft(char c)
{
	int		i;
	int		j;
	char	*flag;

	flag = "oxX";
	i = 21;
	j = 0;
	while (flag[j] != c && flag[i] != '\0')
		j++;
	return (i + j);
}

int		tri_longlong_ft(char c)
{
	int		i;
	int		j;
	char	*flag;

	flag = "diox";
	i = 17;
	j = 0;
	while (flag[j] != c && flag[i] != '\0')
		j++;
	return (i + j);
}

int		tri_long_ft(char c)
{
	int		i;
	int		j;
	char	*flag;

	flag = "dioxu";
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

	flag = "discoxXpuSbZ";
	i = 0;
	while (flag[i] != c && flag[i] != '\0')
		i++;
	return (i);
}
