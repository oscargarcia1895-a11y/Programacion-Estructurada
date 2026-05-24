#include <stdio.h>
#include <windows.h>
#include <string.h>

void Mostrar_Tablero(int Tablero[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (Tablero[i][j] == -1) {
                printf("[X]");
            }
            else {
                printf("[ ]");
            }

        }
        printf("\n");
    }
    printf("\n");
}

void Crear_Tablero(int Tablero[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            Tablero[i][j] = 0;
        }
    }
}

int Poner_Barco(int Tablero[5][5], char barco_grande[]) {

    int origen_x_barco;
    int fila_barco;

    printf("Columna de origen [X] del %s: ", barco_grande);
    scanf("%d", &origen_x_barco);

    if (origen_x_barco < 0) {origen_x_barco *= -1;}
    if (origen_x_barco > 3) {origen_x_barco = 3;}

    printf("Fila [Y] del %s: ", barco_grande);
    scanf("%d", &fila_barco);

    if (fila_barco < 0) {fila_barco *= -1;}
    if (fila_barco > 4) {fila_barco = 4;}

    int coordenadas_x_barco[2] = {origen_x_barco, origen_x_barco + 1};

    for (int x = 0; x < 2; x++) {

        if (Tablero[fila_barco][coordenadas_x_barco[x]] != 0) {

            printf("No puede estar encima del otro barco\n");

            if (x > 0) {
                Tablero[fila_barco][coordenadas_x_barco[x] - 1] = 0;
            }

            return 0;
        }

        Tablero[fila_barco][coordenadas_x_barco[x]] = 1;
    }

    return 1;
}

void Configurar_Tablero(int Tablero[5][5], int Posicion_Bote[2], char barco_grande[], char barco_pequeno[]) {

    int X;
    int Y;

    printf("Columna [Posicion X] del %s: ", barco_pequeno);
    scanf("%d", &X);

    printf("Fila [Posicion Y] del %s: ", barco_pequeno);
    scanf("%d", &Y);

    if (X < 0) {X *= -1;}
    if (X > 4) {X = 4;}

    if (Y < 0) {Y *= -1;}
    if (Y > 4) {Y = 4;}

    Tablero[X][Y] = 1;

    Posicion_Bote[0] = X;
    Posicion_Bote[1] = Y;

    while (1) {

        int exito = Poner_Barco(Tablero, barco_grande);

        if (exito == 1) {break;}

    }
}

void Atacar_Tablero(int Tablero[5][5], int Posicion_Bote[2], char jugador[], char barco_grande[], char barco_pequeno[]) {

    int X;
    int Y;

    printf("Columna [Coordenada X] a atacar: ");
    scanf("%d", &X);

    printf("Fila [Coordenada Y] a atacar: ");
    scanf("%d", &Y);

    if (X < 0) {X *= -1;}
    if (Y < 0) {Y *= -1;}

    if (X > 4) {X = 4;}
    if (Y > 4) {Y = 4;}

    if (Tablero[X][Y] == 1) {

        Tablero[X][Y] = -1;

        if (Posicion_Bote[0] == X && Posicion_Bote[1] == Y) {

            printf("\n%s impactó un %s\n", jugador, barco_pequeno);

        }
        else {

            printf("\n%s impactó un %s\n", jugador, barco_grande);

            int old_X = X;

            if (X > 0 && X < 4) {

                if ((Tablero[X-1][Y] == -1 || Tablero[X+1][Y] == -1) && (old_X != Posicion_Bote[0] || Y != Posicion_Bote[1])) {

                    printf("¡El %s fue hundido!\n", barco_grande);

                }
            }
        }
    }

    else if (Tablero[X][Y] == -1) {

        printf("\nYa está hundido ese barco\n");

    }
    else {

        printf("\n¡No hay ningun barco enemigo ahí!\n");

    }
}

int Estado_Tablero(int Tablero[5][5]) {

    int Barcos_Hundidos = 0;

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            if (Tablero[i][j] == -1) {

                Barcos_Hundidos += 1;

            }
        }
    }

    return Barcos_Hundidos;
}

void Juego(int Tablero_1[5][5], int Tablero_2[5][5]) {

    char jugador1[30];
    char jugador2[30];

    printf("Nombre del Jugador 1: ");
    scanf("%s", jugador1);

    printf("Nombre del Jugador 2: ");
    scanf("%s", jugador2);

    char barco_grande[10] = "Fragata";
    char barco_pequeno[10] = "Submarino";

    int Posicion_Bote_1[2];
    int Posicion_Bote_2[2];

    int game = 1;
    int jugar_de_nuevo;

    while (game) {

        Crear_Tablero(Tablero_1);
        Crear_Tablero(Tablero_2);

        printf("Configurar Tablero de %s:\n", jugador1);
        Configurar_Tablero(Tablero_1, Posicion_Bote_1, barco_grande, barco_pequeno);

        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

        printf("Configurar Tablero de %s:\n", jugador2);
        Configurar_Tablero(Tablero_2, Posicion_Bote_2, barco_grande, barco_pequeno);

        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

        int Barcos_Hundidos_Tablero_1;
        int Barcos_Hundidos_Tablero_2;

        int Ganador = 0;

        for (int turno = 1; turno <= 10; turno++) {

            printf("Turno de %s\n", jugador1);
            Atacar_Tablero(Tablero_2, Posicion_Bote_2, jugador1, barco_grande, barco_pequeno);
            Mostrar_Tablero(Tablero_2);

            Barcos_Hundidos_Tablero_2 = Estado_Tablero(Tablero_2);

            if (Barcos_Hundidos_Tablero_2 >= 3) {

                Ganador = 1;
                break;
            }

            printf("Turno de %s\n", jugador2);
            Atacar_Tablero(Tablero_1, Posicion_Bote_1, jugador2, barco_grande, barco_pequeno);
            Mostrar_Tablero(Tablero_1);

            Barcos_Hundidos_Tablero_1 = Estado_Tablero(Tablero_1);

            if (Barcos_Hundidos_Tablero_1 >= 3) {

                Ganador = 2;
                break;
            }
        }

        printf("Tablero 1:\n");
        Mostrar_Tablero(Tablero_1);

        printf("Tablero 2:\n");
        Mostrar_Tablero(Tablero_2);

        if (Ganador == 1) {

            printf("¡%s ganó la partida!\n", jugador1);

        }
        else if (Ganador == 2) {

            printf("¡%s ganó la partida!\n", jugador2);

        }
        else {

            printf("Nadie ganó\n");

        }

        printf("\n¿Jugar de nuevo?\nSí[1] No[0]: ");
        scanf("%d", &jugar_de_nuevo);

        if (jugar_de_nuevo == 0) {

            game = 0;

        }
    }

    printf("\nFin del juego\n");
}

int main() {

    SetConsoleOutputCP(65001);

    int Tablero_1[5][5];
    int Tablero_2[5][5];

    Juego(Tablero_1, Tablero_2);

    return 0;
}