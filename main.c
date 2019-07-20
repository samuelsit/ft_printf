#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
    int real = printf("%llx", 4294967296);
    printf("\n");
    int mine = ft_printf("%llx", 4294967296);
    printf("\n");

    printf("real =%d mine =%d\n", real, mine);
    return (0);
}
