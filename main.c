#include <stdio.h>
#include "includes/ft_printf.h"

int	main(int ac, char **av)
{
  int	ret[2];
  char	*str = "astek";
  char	stre[] = {'a', 's', 10, 'e', 'k', 0};

  int n = printf("ft = %10x end\n", 42);
  int n1 = ft_printf("my = %10x end\n", 42);


  printf("ft = %d\n", n);
  ft_printf("my = %d\n", n1);

  return(0);
}
