#include <stdio.h>

/* Primos.
El programa almacena en un arreglo unidimencional los primero 100 numero primos. */

const int tam = 100;

void imprime(int, int);         //Prototipos de funciones.
void primo(int, int *);

void main(void)
{
    int p[tam] = {1,2};
    int fla, j = 2, pri = 3;
    while (j <= tam)
    {
        fla = 1;
        primo(pri, &fla);       //Se llama a a la funcion que determina si pri es primo.
        if (fla)                //Si fla es 1, entonces pri es primo.
        {
            p[j] = pri;
            j++;
        }
        pri += 2;
    }
    imprime(p, tam);
}

void primo(int a, int *b)
//Esta funcion determina se a es primo, en cuyo caso el valor de *b no se altera.
{
    int di = 3;
    while (*b && (di < (a / 2)))
    {
        if ((a % di) == 0)
            *b = 0;
        di++;
    }
}

void imprime(int primos[], int t)
//Esta funcion imprime el arreglo unidimencional de numeros primos.
{
    int i;
    for (i=0; i<t; i++)
        printf("\nPrimos[%d]: %d", i, primos[i]);
}
