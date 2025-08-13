#include <stdio.h>
#include "demo.h"

int main()
{
    printf("hoho");
    int a = 10, b = 20, c, d, e, f, g;
    c = sum(a, b);
    d = square(a);
    e = product(a, b);
    f = diff(b, a);
    g = division(b, a);
    printf("sum is: %d\n", c);
    printf("square is: %d\n", d);
    printf("product is: %d\n", e);
    printf("diff is: %d\n", f);
    printf("division is: %d\n", g);

    return 0;
}