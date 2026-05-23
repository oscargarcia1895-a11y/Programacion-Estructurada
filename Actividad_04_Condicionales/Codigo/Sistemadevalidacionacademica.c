#include <stdio.h>

int main(){

    int Edad;
    float Promedio;
    int materiasreprobadas;

    printf("Edad del aspirante: ");
    scanf("%d", &Edad);

    printf("Promedio del aspirante: ");
    scanf("%f", &Promedio);

    printf("Materias reprobadas del aspirante: ");
    scanf("%d", &materiasreprobadas);

    if((Promedio >= 9) && (materiasreprobadas == 0) && (Edad >= 18))
    {

        printf("Fuiste seleccionado para la beca");

    } else if(Edad < 18){

        printf("No eres mayor de edad");

    } else if(materiasreprobadas <= 2)
    {

        printf("Puedes reinscribirte la siguiente vez");

    } else if(materiasreprobadas > 3)
    {

        printf("Situacion del aspirante critica");

    }

    return 0;

}
