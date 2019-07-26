#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
    int mine = ft_printf("%llX\n", 4294967296);
    int real = printf("%llX\n", 4294967296);

    printf("real = %d, mine = %d\n", real, mine);
    return (0);
}
