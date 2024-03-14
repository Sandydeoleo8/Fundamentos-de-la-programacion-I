#include <stdio.h>

/* Suma matrices.
El programa, al recibir como datos dos arreglos bidimencionales del mismo tamano, calcula la suma de ambos y la almacena en un tercer arreglo bidimencional. */

const int max = 50;

//Prototipo de funciones.
void lectura(int [][max], int, int);
void suma(int[][max], int[][max], int, int);
void imprime(int[][max], int, int);

void main(void)
{
    int ma[max][max], mb[max][max], mc[max][max];
    //Declaracion de los tres arreglos.
    int fil, col;
    do
    {
        printf("Ingrese el numero de filas de los arreglos: ");
        scanf("%d", &fil);
    }
    while (fil > max || fil < 1);
    //Se verfica que el numero de filas sea correcto.
    do
    {
        printf("Ingrese el numero de columnas de los arreglos: ");
        scanf("%d", &col);
    }
    while (col > max || col < 1);
    //Se verifica que el numero de columnas sea correcto.
    printf("\nLectura del arreglo ma\n");
    lectura(ma, fil, col);
    printf("\nLectura del arreglo mb\n");
    lectura(mb, fil, col);
    Suma(ma, mb, mc, fil, col);
    printf("\nImpresion del arreglo mc\n");
    imprime
    (mc, fil, col);
}

void lectura(int a[][max], int f, int c)
//La funcion lectura se utiliza para leer un arreglo bidimencional entero de f filas y c columnas.
{
    int i, j;
    for (i = 0; i < f; i++)
        for (j = 0; j < c; j++)
    {
        printf("Ingrese el elemento %d %d: ", i + 1, j + 1);
        scanf("%d", &a[i][j]);
    }
}

void Suma(int m1[][max], int m2[][max], int m3[][max], int f, int c)
//La funcion suma se utiliza para sumar los arreglos y almacenar el resultadoen un tercer arreglo bidimencional.
{
    int i, j;
    for (i = 0; i < f; i++)
        for (j = 0; j < c; j++)
        m3[i][j] = m1[i][j] + m2[i][j];
}

void imprime(int a[][max], int f, int c)
//La funcion imrpime se utiliza para escribir un arreglo bidimencional de tipo entero de f filas y c columnas.
{
    int i, j;
    for (i = 0; i < f; i++)
        for (j = 0; j < c; j++)
        printf("\nElemento %d %d: %d ", i, j, a[i][j]);
}
