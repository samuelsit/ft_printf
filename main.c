#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
    int real = printf("%s", NULL);
    printf("\n");
    int mine = ft_printf("%s", NULL);
    printf("\n");

    printf("real =%d mine =%d\n", real, mine);
    return (0);
}
