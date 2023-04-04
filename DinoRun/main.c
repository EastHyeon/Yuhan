#include <stdio.h>
#include "game.h"

int main()
{
    int a = 1;
    int b = 2;

    int c = add(a, b);
    int d = sub(a, b);

    printf("%d %d\n", c, d);

    return 0;
}