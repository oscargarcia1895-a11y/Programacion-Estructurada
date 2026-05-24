#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int tablero[5][5];
    int i=0;
    int j=0;
    char nombre[20] = "Juanito";
    FILE *archivo;
    archivo = fopen("tablero.txt", "w");

    for(i=0; i<5; i++){
        for(j=0; j<5; j++)
        {
            tablero[i][j] = '~';
        }
    }

    tablero[1][2] = 'B';
    tablero[3][4] = 'X';
    tablero[2][1] = '0';

    for(i=0; i<5; i++){
        for(j=0; j<5; j++)
        {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }

    fprintf(archivo, "Oscar\n");
    fprintf(archivo, "%s\n", nombre);
    for(i=0; i<5; i++){
        for(j=0; j<5; j++)
        {
            fprintf(archivo, "%c ", tablero[i][j]);
        }
        fprintf(archivo, "\n");
    }
    fprintf(archivo, "Oscar\n");
    fprintf(archivo, "%s\n", nombre);
    fclose(archivo);

    archivo = fopen("tablero.txt", "r");

    char buscar[100];

    for(i=0; fgets(buscar, sizeof buscar, archivo) != NULL; i++)
    {
        buscar[strcspn(buscar, "\n")]  = '\0';
        if(strcmp(buscar, nombre) == 0)
        {

            printf("El nombre es %s\n", nombre);

        }
    }
    fclose(archivo);

return 0;
}