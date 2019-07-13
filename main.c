#include <stdio.h>
#include "includes/ft_printf.h"

int	main(int ac, char **av)
{
  int n = printf("ft = %lo end\n", 2147483648);
  int n1 = ft_printf("my = %lo end\n", 2147483648);


  printf("ft = %d, my = %d\n", n, n1);

  return(0);
}
