#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
    int real = printf("cool %.2s salut ca va\n", "okisncenin");
    int mine = ft_printf("cool %.2s salut ca va\n", "okisncenin");

    printf("real =%d mine =%d\n", real, mine);
    return (0);
}
