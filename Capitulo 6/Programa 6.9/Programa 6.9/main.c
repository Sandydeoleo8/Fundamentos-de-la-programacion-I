#include <stdio.h>

/* Asigna.
El programa, al recibir un arreglo bidimencional ceadrado, asigna elementos en funcion del modulo (residuo) a un arreglo unidimensional. */

void lectura(int [][10], int);
void calcula(int [][10], float [], int;
float mod0(int [][10], int, int);
float mod1(int [][10], int);                 //Prototipo de funciones.
float mod2(int [][10], int, int);
void imprime(float [10], int);

void main(void)
{
    int mat[10][10], tam;
    float vec[10];
    do
    {
        printf("Ingrese el tamano de la matriz: ");
        scanf("%d", &tam);
    }
    while (tam > 10 || tam < 1);
    lectura(mat, tam);
    calcula(mat, vec, tam);
    imprime(vec, tam);
}

void lectura (int a[][10], int n)
//La funcion lectura se utiliza para leer un arreglo bidimensional cuadrado de tipo entero.
{
    int i, j;
    for (i =0; i < n; i++)
        for (j - 0; j < n; j++)
    {
        printf("Ingrese el elemento %d %d: ", i + 1,j + 1);
        scanf("%d", &a[i][j]);
    }
}

void calcula(int [][10], float b[], int n)
//Esta funciion se utiliza tanto para calcular el modulo entre el indice del arreglounidimensional y 3, como para llamar a las funciones correspondientes para resolver el problema.
{
    int i;
    for (i = 0; i < n; i++)
        switch (i%3)
    {
        case 1: b[i] = mod1 (a,i);
        break;
        case 2: b[i] = mod2 (a, i, n);
        break;
        default; b[i] = mod0 (a, i, n);
        break;
    }
}

float mod0(int a[][10], int k, int m)
//Esta funcion calcula el cociente entre una productoria y una sumatoria.
{
    int i;
    float pro = 1.0, sum = 0.0;
    for (i =0; i < m; i++)
    {
        pro *= a[i][k];
        sum += a[i][k];
    }
    return (pro / sum);
}


float mod1(int a[][10], int n)
//Esta funcion obtiene el resultado de una sumatoria.
{
    int i;
    float sum = 0.0;
    for (i = 0; i < n; i++)
        sum += a[n][i];
    return (sum);
}

float mod2(int a[][10], int n, int m)
//Esta funcion obtiene el resultado de la productoria.
{
    int i;
    float pro = 1.0;
    for ( i = n; i < m; i++)
        pro *= a[i][n];
    return (pro);
}

void imprime(float b[], int n)
//Esta funcion se utiliza para escribir un arreglo bidimensional de tipo real de n elementos.
{
    int i;
    for (i = 0; i < n; i++)
        printf("\nElemento %d: %.2f ", i, b[i]);
}
