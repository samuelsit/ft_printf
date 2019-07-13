#include <stdio.h>
#include "includes/ft_printf.h"

int	main(int ac, char **av)
{
  int	ret[2];
  char	*str = "astek";
  char	stre[] = {'a', 's', 10, 'e', 'k', 0};

  int n = printf("ft = %ld %ld end\n", 1234566667890987, 1234566667890987);
  int n1 = ft_printf("my = %ld %ld end\n", 1234566667890987, 1234566667890987);


  printf("ft = %d, my = %d\n", n, n1);

  return(0);
}
