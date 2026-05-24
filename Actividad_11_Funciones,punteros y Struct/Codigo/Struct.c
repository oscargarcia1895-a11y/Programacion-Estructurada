#include <stdio.h>

struct alumne
{
    char nombre[20];
    float calificacion;
    int Edad;
    int Act_Real;
    int Derecho;
};

int main()
{
    struct alumne pepe;
    struct alumne grupo[3];

    printf("Nombre: ");
    fgets(pepe.nombre, 20,stdin);

    printf("Edad: ");
    scanf("%d", &pepe.Edad);

    printf("Promedio: ");
    scanf("%f", &pepe.calificacion);

    getchar();

    printf("El nombre es %s", pepe.nombre);
    printf("La edad es %d", pepe.Edad);
    printf("El promedio es es %f", pepe.calificacion);

    for(int i = 0; i<3; i++)
    {
        printf("Dame el nombre: ");
        fgets(grupo[i].nombre, 20, stdin);
    }

    for(int i = 0; i<3; i++)
    {
        printf("Dame la edad: ");
        scanf("%d", &grupo[i].Edad);
    }

    for(int i = 0; i<3; i++)
    {
        printf("Dame el promedio: ");
        scanf("%d", &grupo[i].calificacion);
    }

    return 0;
}
