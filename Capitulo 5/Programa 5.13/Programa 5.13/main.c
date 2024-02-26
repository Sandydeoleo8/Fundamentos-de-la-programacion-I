#include <stdio.h>

//Ordenacion por seleccion directa.

const int max = 100;

void lectura(int *, int);
void ordena(int *, int);            //Prototipo de funciones.
void imprime(int *, int);

void main(void)
{
    int tam, vec[max];
    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &tam);
    }
    while (tam>max || tam<1);       //Se verifica que el tamano del arreglo sea correcto.
    lectura(vec, tam);
    ordena(vec, tam);
    imprime(vec, tam);
}

void lectura(int a[], int t)
//La funcion lectura se utiliza para escribir un arreglo unidimencional ordenado de t elementos de tipo entero.
{
    int i;
    for (i = 0; i < t; i++)
    {
        printf("Ingrese el numero de elemento %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

void imprime(int a[], int t)
//Esta funcion se utiliza para escribir un arreglo unidimencional ordenado de t elementos de tipo entero.
{
    int i;
    for (i = 0; i < t; i++)
        printf("\na[%d]: %d", i, a[i]);
}

void ordena(int a[], int t)
//La funcion ordena utiliza el metodo de seleccion directa para ordenar los elementos del arreglo unidimencional a.
{
    int i, j, men, l;
    for (i = 0; i < (t-1); i++)
    {
        men = a[i];
        l = i;
        for (j = (i + 1); j < t; j++)
            if (a[j] < men)
        {
            men = a[j];
            l = j;
        }
        a[l] = a[i];
        a[i] = men;
    }
}
