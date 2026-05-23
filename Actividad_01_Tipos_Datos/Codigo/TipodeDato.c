#include <stdio.h>

void main(){

    int i = 555;
    unsigned int ui = 777;
    short int si = -3000;
    unsigned short int usi = 60000;
    long int li = 123456;
    unsigned long int uli = 654321;
    long long int lli = 9999999;
    unsigned long long int ulli = 8888888;
    char c = 'A';
    signed char sc = -50;
    unsigned char uc = 200;
    float f = 3.14f;
    double d = 2.718281828;

    printf("El valor de i es igual a: %i y su direccion es: %d\n", i, &i);
    printf("El valor de ui es igual a: %u y su direccion es: %d\n", ui, &ui);
    printf("El valor de si es igual a: %i y su direccion es: %d\n", si, &si);
    printf("El valor de usi es igual a: %u y su direccion es: %d\n", usi, &usi);
    printf("El valor de li es igual a: %ld y su direccion es: %d\n", li, &li);
    printf("El valor de uli es igual a: %lu y su direccion es: %d\n", uli, &uli);
    printf("El valor de lli es igual a: %lld y su direccion es: %d\n", lli, &lli);
    printf("El valor de ulli es igual a: %llu y su direccion es: %d\n", ulli, &ulli);
    printf("El valor de c es igual a: %c y su direccion es: %d\n", c, &c);
    printf("El valor de sc es igual a: %d y su direccion es: %d\n", sc, &sc);
    printf("El valor de uc es igual a: %u y su direccion es: %d\n", uc, &uc);
    printf("El valor de f es igual a: %f y su direccion es: %d\n", f, &f);
    printf("El valor de d es igual a: %lf y su direccion es: %d\n", d, &d);


}