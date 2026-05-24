#include <stdio.h>

void rellenar(int v[3][3]);
void mostrar(int v[3][3]);
int sumar_diagonal(int v[3][3]);


int main()
{
    int v[3][3] = {{1,2,3}, {1,2,3}};

    rellenar(v);
    mostrar(v);
    printf("El resultado de la suma es %d", sumar_diagonal(v));

    return 0;

}

void rellenar(int v[3][3])
{
    int i, j;

    for(i = 0; i<3; i++)
    {
        for(j= 0; j<3; j++)
        {
            scanf("%d", &v[i][j]);
        }
    }
}

void mostrar(int v[3][3])
{
    int i, j;
    FILE *f;
    f = fopen("tablero.txt", "a");

    for(i = 0; i<3; i++)
    {
        for(j= 0; j<3; j++)
        {
            printf("%d", v[i][j]);
            fprintf(f, "%d ", v[i][j]);
        }
        printf("\n");
        fprintf(f, "\n");
    }
    fclose(f);
}

int sumar_diagonal(int v[3][3])
{
    int i, j, suma = 0;

    for(i = 0; i<3; i++)
    {
        for(j= 0; j<3; j++)
        {
            if(i == j)
            {
                suma = suma + v[i][j];
            }
        }
    }
    return suma;
}