#include <stdio.h>

int main(){

    int numero;
    int r;

    printf("Dame un numero: ");
    scanf("%d", &numero);

    r = numero % 2;

    if(r == 0)
    {

        printf("El numero es par");

    } else
    {
        printf("El numero no es par");

    }

    return 0;

}
