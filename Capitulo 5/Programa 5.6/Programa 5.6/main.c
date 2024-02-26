#include <stdio.h>
#include <math.h>

/* Suma-cuadrados.
El programa calcula la suma del cuadrado de los elementos de un arreglo unidimencional de 100 elementos de tipo real. */

const int max = 10;
//max se utiliza para reservar el espacio maximo que podra ocupar el arreglo.

void lectura(float *, int);         //Prototipos de funciones.
double suma(float *, int);

void main(void)
{
    float vec[max];
    double res;
    lectura(vec, max);
    res = suma(vec, max);
    //Se llama a la funcion suma y se almacena el resultado en la variable res.
    printf("\n\nSuma del arreglo: %.21f", res);
}

void lectura(float a[], int t)
//La funcion lectura se utiliza para leer un arreglo unidimencional de t elementos de tipo real.
{
    int i;
    for (i=0; i<t; i++)
    {
        printf("Ingrese el elemento %d: ", i+1);
        scanf("%f", &a[i]);
    }
}

double suma(float a[], int t)
//La funcion suma se utiliza para calcular la suma del cuadrado de los componentes de un arreglo unidimencional de t elementos de tipo real.
{
    int i;
    double aux = 0.0;
    for (i=0; i<t; i++)
        aux += pow(a[i], 2);
    return(aux);

}
