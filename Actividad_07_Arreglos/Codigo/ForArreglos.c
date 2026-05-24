#include <stdio.h>

int main()
{
    int N = 4;
    float temp[N];

    for(int i=0; i < N; i++)
    {
        printf("Dame la temperatura: ");
        scanf("%f", &temp[i]);
    }
    for(int i=0; i < N; i++)
    {
        printf("%f\n", temp[i]);

    }
    return 0;
}
