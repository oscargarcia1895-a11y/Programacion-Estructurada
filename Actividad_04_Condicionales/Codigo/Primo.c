#include <stdio.h>

int main(){

    int numero;
    int r1;
    int r2;
    int r3;

    printf("Dame un numero: ");
    scanf("%d", &numero);

    r1 = numero % 1;
    r2 = numero % 2;
    r3 = numero % numero;

    if((r1 == 0) && (r2 != 0) && (r3 == 0) || (numero == 2)){

        printf("El numero es primo");

    } else if((r1 == 0) && (r2 == 0) && (r3 == 0))
    {
        printf("El numero no es primo");
    }

    return 0;
}
