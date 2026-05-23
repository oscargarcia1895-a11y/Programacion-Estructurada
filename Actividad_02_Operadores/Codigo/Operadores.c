#include <stdio.h>

int main()
{
    int a = 3;
    int b = 4;
    int c = a++ + --b;

    printf("%d %d %d", a, b, c); //a=3, b=4, c=6

    int x = 10;
    int y = 3;

    printf("%d\n %d\n", x + y * 2, (x + y) * 2); //16 y 26


    return 0;

}