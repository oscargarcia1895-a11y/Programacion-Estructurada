#include <stdio.h>

int main(){

    int N;
    float cal;
    float suma = 0;
    int opcion;
    float promedio = 0;
    do{
        printf("1. Calculo de promedio\n");
        printf("2. Salir\n");
        scanf("%d", &opcion);

        if(opcion == 1){

            printf("Ingrese la cantidad de materias: \n");
            scanf("%d", &N);
            if(N > 0){

                suma = 0;

                for(int i=1; i <= N; i++){

                do{
                    printf("Dame la calificacion: \n");
                    scanf("%f", &cal);

                    if(cal < 0 || cal > 100){
                        printf("Calificacion invalida.\n");
                    }

                }while(cal < 0 || cal >100);
                suma = suma + cal;
            }

            promedio = suma / N;
            printf("El promedio es igual a %.2f\n", promedio);

                if(promedio >= 60){
                    printf("Aprobado\n");
                } else {
                    printf("Reprobado\n");
                }

            } else {

                printf("Cantidad invalida\n");

            }
            } else {

                printf("Invalido\n");

            }

        }while(opcion != 2);
    return 0;
    }

