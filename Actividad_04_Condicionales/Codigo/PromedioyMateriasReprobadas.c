#include <stdio.h>

int main(){

    float promedio;
    int materiasreprobadas;

    printf("Dame el promedio del aspirante: ");
    scanf("%f", &promedio);

    printf("Dame el numero de materias reprobadas: ");
    scanf("%d", &materiasreprobadas);

    if((promedio >= 8.5) && (materiasreprobadas == 0)){

        printf("El aspirante fue seleccionado para la beca");

    } else {

        printf("El aspirante no fue seleccionado para la beca");

    }
    return 0;
}
