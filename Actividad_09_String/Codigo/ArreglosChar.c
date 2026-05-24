#include <stdio.h>
#include <string.h>

int main()
{

    char Alumno1[16]="Antonio"; //1.Crea un arreglo de 16 caracteres que se inicializa con "Antonio"
    char Alumno2[16]; //2.Crea un arreglo de 16 carcateres
    char Lista[15][16]; //3.Crea un arreglo bidimensional capaz de guaradar 15 nombres de 16 caracteres
    char nombre[20]="Oscar"; //7.Crea un arreglo de 20 caracteres que se incializa con "Oscar"
    char apellido[20]="Ocegueda"; //7.Crea un arreglo  de 20 caracteres que se inicializa con "Ocegueda"
    char a[20]; //8.Crea una cadena de 20 caracteres
    char b[20]; //8.Crea una cadena de 20 caracteres
    char jugador[20]; //9.Crea una cadena de 20 caracteres
    int longitud; //5.Crea una variable tipo entero donde se guarda la longitud del arreglo

    printf("%s\n", Alumno1); //1.Imprime la cadena completa

    printf("Dame tu nombre: "); //2.Muestra "Dame tu nombre en la pantalla"
    //scanf("%s", Alumno2);

    fgets(Alumno2, sizeof(Alumno2), stdin); //2.fgets permite leer las cadenas con espacios, "sizeof" evita desbordamiento y stdin indica qwue se leerá desde el teclado
    printf("%s", Alumno2); //2.Imprime la cadena con espacios almacenada en "Alumno2"

    for(int i=0; i < 3; i++){ //3.Ciclo for que recorre el arreglo bidimensional
       printf("Dame el nombre: "); //3.Imprime "Dame tu nombre" en pantalla
       fgets(Lista[i], sizeof(Lista [i]), stdin); //3.Captura cada nombre en una posición del arreglo
    }

    for(int i=0; i < 3; i++){ //4.Ciclo que recorre el arreglo bidimensional
        printf("%s\n", Lista[i]); //4.Imprime los nombres en pantalla
    }
    for(int i=0; i < 3; i++){ //5.Ciclo que recorre el arreglo bidimensional
        longitud = strlen(Lista[i]); //5.La función strlen cuenta los caracteres de la cadena (En caso del fgets también el salto de línea), y se alamacena en la variable longitud
        printf("La longitud de %s es de %d\n", Lista[i], longitud); //5.Imprime en pantalla las palabras y su longitud
    }

    strcpy(Lista[0], "Ana"); //6.Copia texto a la posición 0 del arreglo
    strcpy(Lista[1], "Luis"); //6.Copia texto a la posición 1 del arreglo
    strcpy(Lista[2], "Carlos"); //6.Copia texto en la posición 2 del arreglo

    for(int i=0; i < 3; i++){ //6.Ciclo que recorre el arreglo bidimensional
        printf("%s\n", Lista[i]); //6.Imprime los nuevos nombre que se copiaron con strcpy
    }

    strcat(nombre, apellido); //7.Concatena la cadena nombre con apellido y lo almacena en la cadena nombre
    printf("%s\n", nombre); //7.Muestra la cadena concatenada

    printf("Dame la primer palabra: "); //8.Muestra "Dame la primer palabra" en pantalla
    fgets(a, sizeof(a), stdin); //8.Captura la primer palabra

    printf("Dame la segunda palabra: "); //8.Muestra "Dame la segunda palabra" en pantalla
    fgets(b, sizeof(b), stdin); //8.Captura la segunda palabra

    if(strcmp(a, b) == 0){ //8.Compara las cadenas con strcmp, si regresa un valor igual a 0 son iguales, y si es mayor o menor a 0 son diferentes con ayuda del if
        printf("Las cadenas son iguales\n"); //8.Ciclo verdadero o es igual a cero, imprime que las cadenas son iguales
    } else{ //8. Bloque falso
        printf("Las cadenas son diferentes\n"); //8.Imprime que las cadenas son diferentes cuando difiere de 0
    }

    printf("Nombre del jugador: "); //9.Imprime "Nombre de jugador" en pantalla
    fgets(jugador, sizeof(jugador), stdin); //9.Almacena el nombre en la cadena

    printf("Bienvenido %s", jugador); //9.Muestra Bienvenido junto al nombre almacenado en jugador

    printf("Turno de %s", jugador); //9.Muestra Turno junto al nombre del jugador, permite personalizar el juego de batalla naval

    char barco[10] = "Fragata"; //10. Crea una cadena de 10 caracteres que se inicializa con Fragata, el tipo de barco

    printf("Impactaste un %s", barco); //10.Imprime "Impactaste cuando aciertas"

    return 0;
}