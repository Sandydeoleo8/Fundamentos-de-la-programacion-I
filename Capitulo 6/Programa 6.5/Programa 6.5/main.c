#include <stdio.h>

/* Alumnos.
El programa, al recibir un arreglo bidimensional que contiene informacion sobre calificaciones de alumnos en cuatro materias diferentes, obtiene resultados estadisticos. */

const int max = 50;
const int exa = 4;

void lectura(float [max][exa], int);
void funcion1(float [max][exa], int);           //Prototipo de funciones.
void funcion2(float [max][exa], int);

void main(void)
{
    int nal;
    float alu[max][exa];
    do
    {
        printf("Ingrese el numero de alumnos del grupo: ");
        scanf("%d", &nal);
        //Se verifica que el numero de alumnos del grupo sea valido.
    }
    while (nal > max || nal < 1);
    lectura(alu, nal);
    funcion1(alu, max);
    funcion2(alu, max);
}

void lectura(float a[][exa], int n)
//La funcion lectura se utiliza para leer un arreglo bidimensional de tipo real de n filas y exa  columnas.
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < exa; j++)
    {
        printf("Ingresa la calificacion %d del alumno %d: ", j+i, i+1);
        scanf("%f", &a[i][j]);
    }
}

void funcion1(float a[][exa], int t)
//Esta funcion se utilza para obtener el promedio de cada estudiante.
{
    int i, j;
    float sum, pro;
    for (i = 0; i < t; i++)
    {
        sum = 0;
        for (j = 0; j < exa; j++)
            sum += a[i][j];
        pro = sum / exa;
        printf("\nEl promedio del alumno %d es: %5.2f", i+1, pro);
    }
}

void funcion2(float a[][exa], int t)
//Esta funcion se utiliza para obtener el promedio de cada examen, asi como tambien el examen que obtuvo el periodo mas alto.
{
    int i, j, may;
    float sum, pro, mpro = 0;
    printf("\n");
    for(j = 0; j < exa; j++)
    {
        sum = 0;
        for (i = 0; i < t; i++)
            sum += a[i][j];
        pro = sum / t;
        if (pro > mpro)
        {
            mpro = pro;
            may = j;
        }
        printf("\nEl promedio delexamen %d es: %f", j+1, pro);
    }
    printf("\n\nEl examen con mayor promedio es: %d \t Promedio: %5.2f", may+1, mpro);
}
