#include <stdio.h>

/* Intercambia.
El programa intercambia las columnas de un arreglo bidimensional. Los elementos de la primera columna se intercambian con los de la ultima, los de la segunda con los de la penultima, y asi sucesivamente. */

const int max = 50;

void lectura(float [][max], int, int);
void intercambia(float [][max], int, int);          //Prototipo de funciones.
void imprime(float [][max], int, int);

void main(void)
{
    int f, c;
    float mat[max][max];
    do
    {
        printf("Ingrese el numero de filas: ");
        scanf("%d", &f);
    }
    while (f > max || f < 1);                       //Se verifica que el numero de filas sea correcto.
    do
    {
        printf("Ingrese el numero de columnas: ");
        scanf("%d", &c);
    }
    while (c > max || c < 1);                       //Se verifica que el numero de columnas sea correcto.
    lectura(mat, f, c);
    intercambia(mat, f, c);
    imprime(mat, f, c);
}

void lectura(float a[][max], int f, int c)
//La funcion lectura se utiliza para leer un arreglo bidimensional de tipo real de f filas y c columnas.
{
    int i, j;
    for (i = 0; j < f; i++)
        for (j = 0; j < c; j++)
    {
        printf("Ingrese el elemento %d %d: ", i+1, j+1);
        scanf("%f", &a[i][j]);
    }
}

void intercambia(float a[][max], int f, int c)
//Esta funcion se utiliza para intercambiar las columnas del arreglo bidimensional. Observa que el indice correspondiente a las columnas solo se mueve hasta la mitad del arreglo.
{
    int i, j;
    float aux;
    //Observa que en esta funcion el indice i se utiliza para las columnas, y el indice j para las filas.
    for (i = 0; i < (c /2); i++)
        for (j = 0; j < f; j++)
    {
        aux = a[j][i];
        a[j][i] = a[j][c-i-1];
        a[j][c-i-1] = aux;
    }
}

void imprime(float a[][max], int f, int c)
//La funcion imprime se utiliza para escribir un arreglo bidimencional de tipo real de f dilas y c columnas.
{
    int i, j;
    for (i = 0; i < f; i++)
        for (j = 0; j < c; j++)
        printf("\nElemento %d %d: %5.2f", i+1, j+1, a[i][j]);
}
