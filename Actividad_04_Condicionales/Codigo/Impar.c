#include <stdio.h>

int main(){

    int numero;
    int r;

    printf("Dame un numero: ");
    scanf("%d", &numero);

    r = numero % 2;

    if(r != 0)
    {

        printf("El numero es impar");

    } else
    {
        printf("El numero no es impar");

    }

    return 0;

}