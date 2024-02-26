#include <stdio.h>
#include <math.h>

/*Estadistico.
El programa, al recibir como dato un arreglo unidimencional de enteros que contiene calificaciones, calcula la medida, la varianza, la desviacion estandar y la moda. */

const int max = 100;

void lectura(int *, int);
float media(int *, int);
float varianza(int *, int, float);          //Prototipos de funciones.
float desviacion(float);
void frecuencia(int *, int, int *);
int moda(int *, int);

void main(void)
{
    int tam, mod, alu[max], fre[11] = {0};
    float med, var, des;
    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &tam);
    }
    while (tam > max || tam < 1);
        //Se verifica que el tamano del arreglo sea correcto.
        lectura(alu, tam);
        med = media(alu, tam);
        var = varianza(alu, tam, med);
        des = desviacion(var);
        frecuencia(alu, tam, fre);
        mod = moda(fre, 11);
        printf("\nMedia     %.2f", med);
        printf("\nVarianza  %.2f", var);
        printf("\nDesviacion    %.2f", des);
        printf("\nModa      %d", mod);
}

void lectura(int a[], int t)
//La funcion lectura se utiliza para leer un arreglo unidimencional de t elementos de tipo entero.
{
    int i;
    for (i = 0; i < t; i++)
    {
        printf("Ingrese el elemento %d: ", i+1);
        scanf("%d", &a[i]);
    }
}

float media(int a[], int t)
//Esta funcion se utiliza para calcular la medida.
{
    int i;
    float sum = 0.0;
    for (i = 0; i < t; i++)
        sum += a[i];
    return (sum / t);
}

float varianza(int a[], int t, float m)
//Esta funcion se utiliza para calcular la varianza.
{
    int i;
    float sum= 0.0;
    for (i = 0; i < t; i++)
        sum += pow ((a[i] - m), 2);
    return (sum / t);
}

float desviacion(float v)
//Esta funcion se utiliza para calcular la desviacion estandar.
{
    return (sqrt(v));
}

void frecuencia(int a[], int p, int b[])
//Esta funcion se utiliza para calcular la frecuencia de calificaciones.
{
    int i;
    for (i = 0; i < p; i++)
        b[a[i]]++;
}

int moda(int a[], int t)
//Esta funcion se utiliza para calcular la moda.
{
    int i, mod = 0, val = a[0];
    for (i = 1; i < t; i++)
        if (mod < a[i])
    {
        mod = i;
        val = a[i];
    }
    return(mod);
}
