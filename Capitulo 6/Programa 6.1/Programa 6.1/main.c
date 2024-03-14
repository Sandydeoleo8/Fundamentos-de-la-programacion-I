#include <stdio.h>

/* Diagonal.
El programa al recibir como dato una matriz de tipo entero, escribe la diagonal principal. */

const int tam = 10;

void lectura(int [][tam], int);         //Prototipo de funciones.
void imprime (int[][tam], int);
//Observa que siempre es necesario declarar el numero de columnas, si no lo haces, el compilador marcara un error de sintaxis.

void main(void)
{
    int mat[tam][tam];
    lectura(mat, mat);
    imprime(mat, mat);
}

void lectura(int a[][tam], int f)
//La funcion lectura se utiliza para leer un arreglo bidimencional. Observa que solo se debe pasar como parametro el numero de filas ya que la matriz es cuadrada.
{
    int i, j;
    for (i = 0; i < f; i++)
        for (j = 0; j < f; j++)
    {
        printf("Ingrese el numero %d %d: ", i + 1, j + 1);
        scanf("%d", &a[i][j]);
    }
}

void imprime(int a[][tam], int f)
//La funcion imprime se utiliza para escribir un arreglo bidimencional cuadrado de f filas y columnas.
{
    int i, j;
    for (i = 0; i < f; i++)
        for (j = 0; j < f; j++)
            if (i == j)
                printf("\nDiagonal %d %d: %d ", i, j, a[i][j]);
}
