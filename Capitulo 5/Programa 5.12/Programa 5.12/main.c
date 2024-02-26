#include <stdio.h>

//Ordenacion por insercion directa.

const int max = 100;

void lectura(int *, int);
void ordena(int *, int);            //prototipo de funciones.
void imprime(int*, int);

void main(void)
{
    int tam, vec[max];
    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &tam);
    }
    while (tam>max || tam<1);      //Se verifica que el tamano del arreglo sea correcto.
    lectura(vec, tam);
    ordena(vec, tam);
    imprime(vec, tam);
}

void lectura(int a[], int t)
//La funcion lectura se utiliza para leer un arreglo unidimencional de t elemntos de tipo entero.
{
    int i;
    for (i = 0; i < t; i++)
    {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

void imprime(int a[], int t)
//Esta funcion se utiliza para escribir un arreglo unidimencional ordenado de t elementos de tipo enteroo.
{
    int i;
    for (i = 0; i < t; i++)
        printf("\na[%d]: %d", i, a[i]);
}

void ordena(int a[], int t)
//La funcion ordena utiliza el metodo de insercion directa para ordenar los elementos del arreglo unidimencional a.
{
    int aux, l, i;
    for (i = 1; i < t; i++)
    {
        aux = a[i];
        l = i - 1;
        while ((l >= 0) && (aux < a[l]))
        {
            a[l + 1] = a[l];
            l--;
        }
        a[l + 1] = aux;
    }
}
