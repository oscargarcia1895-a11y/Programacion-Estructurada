#include <stdio.h>

void capturar(int v[], int n);
void mostrar(int v[], int n);
int filtrar(int origen[], int destino[], int n);

int main()
{
    int v[6];
    int destino[6];

    capturar(v, 6);
    mostrar(v, 6);
    printf("La cantidad de elementos del nuevo arreglo es %d", filtrar(v, destino, 6));

    return 0;
}

void capturar(int v[], int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("Dame un numero: ");
        scanf("%d", &v[i]);
    }
}

void mostrar(int v[], int n)
{
    int i;

    printf("El arreglo original es: ");

    for(i=0;i<n;i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int filtrar(int origen[], int destino[], int n)
{
    int i;
    int j = 0;
    FILE *f;
    f = fopen("resultado.txt", "w");

    printf("El arreglo filtrado es: ");

    for(i=0;i<n;i++)
    {
        if(origen[i] % 2 != 0 && origen[i] % 3 != 0 && origen[i] <= 10)
        {
            destino[j] = origen[i];
            printf("%d ", destino[j]);
            fprintf(f, "%d ", destino[j]);
            j++;
        }
    }
    printf("\n");
    fclose(f);
    return j;
}