#include <stdio.h>

int main()
{
    float temp1, temp2;
    float temp[24];
    int dummy;

    printf("Dirección de memoria de 2 flotantes: &temp1: %i\n&temp2: %i\n", &temp1, &temp2);
    printf("Dirección de temp: %i\n", temp);
    printf("Dirección de temp[23]: %i\n", &temp[23]);
    printf("Dirección de &dummy: %i", &dummy);
    return 0;
}
