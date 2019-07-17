#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
    int real = printf("cool %.0d salut ca va\n", 42);
    int mine = ft_printf("cool %.0d salut ca va\n", 42);

    printf("real =%d mine =%d\n", real, mine);
    return (0);
}
