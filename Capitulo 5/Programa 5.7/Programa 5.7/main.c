#include <stdio.h>

/* Arreglo sin elementos repetidos.
El programa, al recibir como dato un arreglo unidimencional desordenado de elementos, obtiene como salida ese mismo arreglo pero sin los elementos repetidos. */

void lectura(int *, int);           //Prototipo de funciones.
void imprime(int *, int);
void Elimina(int *, int);
//Observa que en el prototipo de elimina, el segundo parametro es por referencia. Esto, porqueel tamano del arreglo puede disminuir.

void main(void)
{
    int tam, arre[100];
    //Se escribe in do-while para verificar que el tamano del arreglo que se ingresa sea correcto.
    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &tam);
    }

while (tam > 100 || tam < 1);
lectura (arre, tam);
elimina (arre, &tam);
//Observa que el tamano del arreglo se pasa por referencia.
imprime(arre, tam);
}

void lectura(int a[], int t)
//La funcion lectura se utiliza para leer un arreglo unidimencional de t elementos de tipo entero.
{
    printf("\n");
    int i;
    for (i=0; i<t; i++)
    {
        printf("Ingrese el elemento %d: ", i+1);
        scanf("%d", &a[i]);
    }
}

void imprime(int a[], int t)
//La funcion imprime se utiliza para escribir un arreglo unidimencional, sin repeticiones, de t elementos de tipo enetero.
{
    int i;
    for (i=0; i<t; i++)
        printf("\na[%d]: %d", i, a[i]);
}

void elimina(int a[], int *t)
//Esta funcion se utiliza para eliminar los elementos repetidos de un arreglo unidimencional de t elementos de tipo entero.
{
    int i = 0, k, l;
    while (i < (*t-1))
    {
        k = i + 1;
        while (k <= (*t-1))
        {
            if (a[i] == a[k])
            {
                for (l = k; l < (*t-1); l++)
                    a[l] = a[l+1];
                *t = *t - 1;
            }
            else
                k++;
        }
        i++;
    }
}
