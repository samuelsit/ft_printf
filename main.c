#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
    int real = printf("%04x\n",542);
    int mine = ft_printf("%04x\n",542);

    printf("real = %d\nmine = %d\n", real, mine);
    return (0);
}
