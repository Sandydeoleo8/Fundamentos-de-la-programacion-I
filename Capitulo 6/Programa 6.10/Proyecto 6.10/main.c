#include <stdio.h>

/* Cuadrado magico.
El programa genera un cuadrado magico sigiendo los criterios eneunciados anteriormente. */

const int max = 50;

void cuadrado(int[][max], int);
void imprime(int [][max], int);         //Prototipo de funciones.

void main(void)
{
    int cma[max][max], tam;
    do
    {
        printf("Ingrese el tamano impar de la matriz: ");
        scanf("%d", &tam);
    }
    while ((tam > max || tam < 1) && (tam % 2));
    //Se verifica el tamano del arreglo y el orden (impar) del mismo.
    cuadrado(cma, tam);
    imprime(cma, tam);
}

void cuadrado(int a[][max], int n)
//Esta funcion se utiliza para formar el cuadrado magico.
{
    int i = 1, fil = 0, col = n / 2, num = n * n;
    while (i <= num)
    {
        a[fil][col] = i;
        if (i%n != 0)
        {
            fil = (fil - 1 + n) % n;
            col = (col + 1) % n;
        }
        else
            fil++;
        i++;
    }
}

void imprime(int a[][max], int n)
//Esta funcion se utiliza para escribir en cuadrado magico.
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        printf("\nElemento %d %d: %d", i + 1, j + 1, a[i][j]);
}
