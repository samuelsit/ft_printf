#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
    int mine = ft_printf("%#8x\n", 42);
    int real = printf("%#8x\n", 42);

    printf("real = %d, mine = %d\n", real, mine);
    return (0);
}
