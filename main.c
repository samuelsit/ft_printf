#include <stdio.h>
#include "includes/ft_printf.h"

int	main(int ac, char **av)
{
  int	ret[2];
  char	*str = "astek";
  char	stre[] = {'a', 's', 10, 'e', 'k', 0};

  int n = printf("ft = %+5% end\n");
  int n1 = ft_printf("my = %+5% end\n");


  printf("ft = %d, my = %d\n", n, n1);
  ft_printf("my = %d\n", n1);

  return(0);
}
