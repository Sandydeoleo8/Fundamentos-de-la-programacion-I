#include <stdio.h>

/* Univversidad.
El Programa, al recibir informacion sobre el numero de alumnos que han ingresado a sus ocho diferentes carreras en los dos semestres lectivos de los ultimos cinco anos, obtiene informacion util para el departamento de escolar. */

const int f = 8, c = 2, p = 5;
//Se declaran constantes para la filas, la columna y la profundidad.
void lectura(int [][c][p], int, int, int);
void funcion1(int [][c][p], int, int, int);
void funcion2(int [][c][p], int, int, int);
void funcion3(int [][c][p], int, int, int);
//Prototipos de funcios. Cada prototipo de funcion corresponde a uno de los incisos.

void main(void)
{
    int uni[f][c][p];
    lectura(uni, f, c, p);
    funcion1(uni, f, c, p);
    funcion2(uni, f, c, p);
    funcion3(uni, f, c, p);
    //Se coloca el 6 como parametro ya que es la clave de la ingenieria en computacion.
}

void lectura(int a[][c][p], int fi, int co, int pr)
//La funcion lectura se utiliza para leer un arreglo tridimencional de tipo entero de f1 filas, co columnas y pr profuncidad. Observa que al ser trimensional se necesita tres ciclos para recorrer el arreglo.
{
    int k, i, j;
    for (k = 0; k < pr; k++)
        for (i = 0; i < fi; i++)
            for (j = 0; j < co; j++)
    {
        printf("Ano: %d\tCarretera: %d\tSemestre: %d ", k+1, i+1, j+1);
        scanf("%d", &a[i][j][k]);
    }
}

void funcion1(int a[][c][p], int fi, int co, int pr)
//Esta funcion se utiliza para determinar el ano en el que ingreso al mayor numero de alumnos a la universidad. Observa que el primer ciclo externo corresponde a los anos.
{
    int k, i, j, may = 0, ao = -1, sum;
    for (k = 0; k < pr; k++)
        //Por cada ano se suma el ingreso de los dos semestres de las ocho carreras.
    {
        sum = 0;
        for (i = 0; i < fi; i++)
            for (j = 0; j < co; j++)
            sum += a[i][j][k];
        if(sum > may)
        {
            may = sum;
            ao = k;
        }
    }
    printf("\n\nAno con mayor ingreso de alumnos: %d    Alumnos: %d", ao + 1, may);
}

void funcion2(int a[][c][p], int fi, int co, int pr)
//Esta funcion se utiliza para determinar la carrera que recibio el mayor numero de alumnos el ultimo ano. Observa que no se utiliza un ciclo para los planos de la profundidad, ya que es un dato (pr).
{
    int i, j, may = 0, car = -1, sum;
    for (i = 0; i < fi; i++)
    {
        sum = 0;
        for (j = 0; j < co; j++)
            sum += a[i][j][pr-1];
        if (sum > may)
        {
            may = sum;
            car = i;
        }
    }
    printf("\n\nCarrera con mayor numero de alumnos: %d Alumnos: %d", car + 1, may);
}

void funcion3(int a[][c][p], int fi, int co, int pr)
//Esta funcion se utiliza para determinar el ano en el que la carrera ingenieria en computacion recibio el mayor numero de alumnos. Observa que no se utiliza un ciclo para trabajar con las filas, ya que es un dato (fi).
{
    int k, j, may = 0, ao = -1, sum;
    for (k = 0; k < pr; k++)
    {
        sum = 0;
        for (j = 0; j < co; j++)
            sum += a[fi-1][j][k];
        if (sum > may)
        {
            may = sum;
            ao = k;
        }
    }
    printf("\n\nAno con mayor ingreso de alumnos: %d Alumnos: %d", ao + 1, may);
}
