#include <stdio.h>

/* Simetrico.
El programa, al recibir como dato un arreglo bidimencional cuadrado, determina si el mismo es simetrico. */

const int max = 10;

void lectura(int [][max], int);         //Prototipos de funciones.
int simetrico(int [][max], int);

void main(void)
{
    int mat[max][max], n, res;
    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &n);
    }
    while (n > max || n < 1);           //Se verifica que el tamano del arreglo sea valido.
    lectura (mat, n);
    res = simetrico(mat, n);
    if(res)
        printf("\nEl arreglo bidimensional es simetrico");
    else
        printf("\nEl arreglo bidimensional no es simetrico");
}

void lectura(int a[][max], int t)
//La funcion lectura se utiliza para leer un arreglo bidimensional cuadrado de tipo entero de t filas y t columnas.
{
    int i, j;
    for (i = 0; i < t; i++)
        for(j = 0; j < t; j++)
    {
        printf("Fila: %d\tColumna: %d", i + 1, j + 1);
        scanf("%d", &a[i][j]);
    }
}

int simetrico(int a[][max], int t)
//La funcion simetricose utiliza para determinar si el arreglo bidimensional cuadrado es simetrico. Si es simetrico regresa 1, en caso contrario, 0. Observa que en el segundo ciclo solamente se recorre la matriz triangular inferior, sin la diagonal principal.
{
    int i = 0, j, f =1;
    while ((i < t) && f)
    {
        j = 0;
        while ((j < i) && f)
            if (a[i][j] = a[j][i])
            j++;
        else
            f = 0;
        i++;
    }
    return (f);
}
