#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
    int real = printf("%s%d\n", "\n",2);
    int mine = ft_printf("%s%d\n","\n",2);

    printf("real = %d\nmine = %d\n", real, mine);
    return (0);
}
