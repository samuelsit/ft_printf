#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
    int real = printf("p%f\n",542.123);
    int mine = ft_printf("m%f\n",542.123);

    printf("real = %d\nmine = %d\n", real, mine);
    return (0);
}
