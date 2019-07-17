#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
    int real = printf("cool %u salut ca va\n", 4294967295);
    int mine = ft_printf("cool %u salut ca va\n", 4294967295);

    printf("real =%d mine =%d\n", real, mine);
    return (0);
}
