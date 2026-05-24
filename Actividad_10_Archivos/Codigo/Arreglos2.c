#include <stdio.h>

int main()
{

    char Matriz[4][20];
    int Numero[5];
    char ArregloC[5];

    for(int i=0; i<4; i++)
    {

        printf("Dame tu nombre: ");
        fgets(Matriz[i], sizeof(Matriz[i]), stdin);

    }

    for(int i=0; i<4; i++)
    {

        printf("%s", Matriz[i]);

    }

    printf("%d\n", &Numero[0]);
    printf("%d\n", &Numero[1]);
    printf("%d\n", &Numero[2]);
    printf("%d\n", &Numero[3]);
    printf("%d\n", &Numero[4]);
    printf("%d\n", Numero);
    printf("%s\n", Matriz);
    printf("%d\n", &ArregloC[0]);
    printf("%d\n", &ArregloC[1]);
    printf("%d\n", &ArregloC[2]);
    printf("%d\n", &ArregloC[3]);
    printf("%d\n", &ArregloC[4]);
    printf("%d\n", ArregloC);
    printf("%s\n", ArregloC);
    printf("%d\n", ArregloC[5]);

    for(int i=0; i<4; i++)
    {

         printf("%d\n", &Matriz[i]);

    }


    for(int i=0; i<4; i++)
    {
        printf("Dame el numero: ");
        scanf("%i", &Numero[i]);

    }

    for(int i=0; i<4; i++)
    {
        printf("%d = ", &Numero[i]);
        printf("%i", Numero[i]);
        printf("\n");
    }

return 0;
}