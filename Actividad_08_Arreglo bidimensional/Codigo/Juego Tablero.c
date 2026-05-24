#include <stdio.h>
#include <windows.h>

void Mostrar_Tablero(int Tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("[%d]", Tablero[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Crear_Tablero(int Tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
           Tablero[i][j] = 0;
        }
    }
}

int Poner_Barco(int Tablero[3][3]) {
    int origen_x_barco; int fila_barco;
    printf("Columna de origen [X] del Barco grande: ");
    scanf("%d", &origen_x_barco);
    if (origen_x_barco < 0) {origen_x_barco *= -1;}
    if (origen_x_barco > 1) {origen_x_barco = 1;}
    printf("Fila [Y] del Barco grande: ");
    scanf("%d", &fila_barco);
    int coordenadas_x_barco[2] = {origen_x_barco, origen_x_barco + 1};
    for (int x = 0; x < 2; x++) {
        if (Tablero[fila_barco][coordenadas_x_barco[x]] != 0) {
            printf("No puede estar encima del bote pequeño\n");
            if (x > 0) {Tablero[fila_barco][coordenadas_x_barco[x] - 1] = 0;}
            return 0;
        }
        Tablero[fila_barco][coordenadas_x_barco[x]] = 1;
    }
    return 1;
}

void Configurar_Tablero(int Tablero[3][3], int Posicion_Bote[2]) {
    int X; int Y;
    printf("Columna [Posicion X] del Bote pequeño: ");
    scanf("%d", &X);
    printf("Fila [Posicion Y] del Bote pequeño: ");
    scanf("%d", &Y);
    if (X < 0) {X *= -1;}
    if (X > 2) {X = 2;}
    if (Y < 0) {Y *= -1;}
    if (Y > 2) {Y = 2;}
    Tablero[X][Y] = 1;
    Posicion_Bote[0] = X; Posicion_Bote[1] = Y;
    while (1) {
        int exito = Poner_Barco(Tablero);
        if (exito == 1) {break;}
    }
}

void Atacar_Tablero(int Tablero[3][3], int Posicion_Bote[2]) {
    int X; int Y;
    printf("Columna [Coordenada X] a atacar: ");
    scanf("%d", &X);
    printf("Fila [Coordenada Y] a atacar: ");
    scanf("%d", &Y);
    if (X < 0) {X *= -1;}
    if (Y < 0) {Y *= -1;}
    if (X > 2) {X = 2;}
    if (Y > 2) {Y = 2;}
    if (Tablero[X][Y] == 1) {
        Tablero[X][Y] = -1;
        if (Posicion_Bote[0] == X && Posicion_Bote[1] == Y) {
            printf("\n¡Has hundido al bote pequeño!\n");
        }
        else {
            printf("\n¡Has dañado el barco grande!\n");
            int old_X = X;
            if (X == 0 || X == 2) {X = 1;}
            if ((Tablero[X-1][Y] == -1 || Tablero[X+1][Y] == -1) && (old_X != Posicion_Bote[0] || Y != Posicion_Bote[1])) {
                printf("¡Has hundido al barco grande!\n");
            }
        }
    }
    else if (Tablero[X][Y] == -1) {printf("\nYa está hundido ese barco\n");}
    else {printf("\n¡No hay ningun barco enemigo ahí!\n");}
}

int Estado_Tablero(int Tablero[3][3]) {
    int Barcos_Hundidos = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Tablero[i][j] == -1) {Barcos_Hundidos += 1;}
        }
    }
    return Barcos_Hundidos;
}

void Juego(int Tablero_1[3][3], int Tablero_2[3][3]) {
    int Posicion_Bote_1[2]; int Posicion_Bote_2[2];
    int game = 1; int jugar_de_nuevo;
    while (game) {
        Crear_Tablero(Tablero_1); Crear_Tablero(Tablero_2);
        printf("Configurar Tablero 1:\n");
        Configurar_Tablero(Tablero_1, Posicion_Bote_1);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("Configurar Tablero 2:\n"); //Se supone que cada jugador no puede ver ni saber las posiciones del tablero del otro
        Configurar_Tablero(Tablero_2, Posicion_Bote_2); //Puse esos espacios para que no se vea cómo el otro jugador configuró su tablero
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        int Barcos_Hundidos_Tablero_1; int Barcos_Hundidos_Tablero_2;
        int Ganador = 0;
        for (int turno = 1; turno <= 5; turno++) {
                printf("Turno del jugador 1: \n");
                Atacar_Tablero(Tablero_2, Posicion_Bote_2);
                Barcos_Hundidos_Tablero_2 = Estado_Tablero(Tablero_2);
                if (Barcos_Hundidos_Tablero_2 >= 3) {Ganador = 1; break;}
                printf("Turno del jugador 2: \n");
                Atacar_Tablero(Tablero_1, Posicion_Bote_1);
                Barcos_Hundidos_Tablero_1 = Estado_Tablero(Tablero_1);
                if (Barcos_Hundidos_Tablero_1 >= 3) {Ganador = 2; break;}
        }
        printf("Tablero 1:\n");
        Mostrar_Tablero(Tablero_1);
        printf("Tablero 2:\n");
        Mostrar_Tablero(Tablero_2);
        if (Ganador == 1) {printf("¡El jugador 1 gana!\n");}
        else if (Ganador == 2) {printf("¡El jugador 2 gana!\n");}
        else {printf("Nadie ganó\n");}
        printf("\n¿Jugar de nuevo?\nSí[1] No[0]: ");
        scanf("%d", &jugar_de_nuevo);
        if (jugar_de_nuevo == 0) {game = 0;}
    }
    printf("\nFin del juego\n");
}

int main() {
    SetConsoleOutputCP(65001);
    int Tablero_1[3][3]; int Tablero_2[3][3];
    Juego(Tablero_1, Tablero_2);
    return 0;
}