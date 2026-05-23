#include <stdio.h>

void main()
{

    //Ejercicio 1:
    int a = 3;
    int b = 4;
    int c = a++ + --b;
    printf("%d %d %d\n", a, b, c);
    /////En "a" da como resultado 3 debido a que tiene un postfijo por lo que incrementa después además de que solo se declara como valor en c,
    //asimismo la b tiene un prefijo de decremoento pero solo se declara como valor en c es por eso que no se refleja al imprimir excepto en c y c es igual a 6 por que el valor a se matiene igual y el de b se resta por un debido al prefijo de decremento
    //Ejercicio 2:
    int x = 10;
    int y =3;
    printf("%d\n", x + y * 2);
    printf("%d\n", (x + y) * 2);
    //////El valor de la primera operación es 16 debido a que se sigue la jerarquía multiplicando el valor de "y" por 2 y después sumando el valor de "x", el segundo valor sigue la misma lógica haciendo primero lo del paréntesis y despúes multiplicando por 2
    //Ejercicio 3:
    int i = 5;
    printf("%d\n", i++);
    printf("%d\n", ++i);
    /////En el primero sale 5 debido a que aún no se refleja el valor añadido denido al postfijo de incremento, después sí se le aumenta a 6 y por último al utilizar el prefijo de incremento se sube a 7 directamente
    //Ejercicio 4:
    a = 5, b = 2;
    float r = a / b;
    printf("%.2f\n", r);
    /////Sale 2 debido a que son dos variables que alojan enteros por lo que aunque el resultado esté en decimales o flotantes te saldrá 2 porque son enteros y no flotantes entonces nunca te dará decimal y los dos decimales que te da son por el "%.2f"
    //Ejercicio 5
    x = 5, y = 3;
    if(x>y)
    {
        printf("x es mayor");
    }
    else
    {
        printf( "y es mayor");
        printf("fin");
    }
    /////Le faltaba los corchetes tanto al bloque verdadero de if como al falso
}
