#include <stdio.h>

/* Trspuesta.
El programa calcula la traspuesta de una matriz. */

const int max = 50;

void lectura(int [][max], int, int);
void traspuesta(int [][max], int [][max], int, int);            //Prototipo de funciones.
void imprime(int[][max], int, int);

void main(void)
{
    int mat[max][max], tra[max][max];
    int fil, col;
    do
    {
        printf("Ingrese el numero de filas de la matriz: ");
        scanf("%d", &col);
    }
    while (col > max || col < 1);
    //Se verifica que el numero de columnas sea correcto.
    lectura (mat, fil, col);
    traspuesta(mat, tra, fil, col);
    imprime(tra, col, fil);
}

void lectura(int a[][max], int f, int c)
//Esta funcion se utiliza para una matriz de tipo entero de f filas y c columnas.
{
    int i, j;
    for (i = 0; i < f; i++)
        for (j = 0; j < c; j++)
    {
        printf("Ingrese el elemento %d %d: ", i+1, j+1);
        scanf("%d", &a[i][j]);
    }
}

void traspuesta(int m1[][max], int m2[][max], int f, int c)
//Esta funcion se utiliza para calcular la traspuesta.
{
    int i, j;
    for (i = 0; i < f; i++)
        for (j = 0; j < c; j++)
        m2[j][i] = m1[i][j];
}

void imprime(int a[][max], int f, int c)
//Esta funcion se utiliza para escribir una matriz de tipo entero de f filas y c columnas -en este caso la traspuesta.
{
    int i, j;
    for (i = 0; i < f; i++)
        for (j = 0; j < c; j++)
        printf("\nElemento %d %d %d ", i+1, j+1, a[i][j]);
}
