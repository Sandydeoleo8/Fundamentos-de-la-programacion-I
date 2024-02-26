#include <stdio.h>

/* Busqueda secuencial en arreglos desordenados. */

const int max = 100;

void lectura(int, int);         //Prototipos de funciones.
int busca(int *, int, int);

void main(void)
{
    int res, ele, tam, vec[max];
    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &tam);
    }
    while (tam>max || tam<1);   //Se verifica que el tamano del arreglo sea correcto.
    lectura(vec, tam);
    printf("Ingrese el elemento a buscar: ");
    scanf("%d", &ele);
    res = busca(vec, tam, ele); //Se llama a la funcion que busca en el arreglo.
    if (res)
        // Si res tiene un valor verdadero -diferente de 0-, se escribe la posicion en la que se encontro el elemento.
        printf("El elemento se encuentra en la posicion %d", res);
    else
        printf("\nEl elemento no se encuentra en el aarreglo");
}

void lectura(int a[], int t)
//La lectura se utiliza para leer un arreglo unidimencional de t elementos de tipo entero.
{
    int i;
    for (i=0; i<t; i++)
    {
        printf("Ingrese el elemento %d: ", i+1);
        scanf("%d", &a[i]);
    }
}

int busca (int a[], int t, int k)
//Esta funcion localiza en el arreglo un elemento determinado. Si el elemento es encontrado, regresa la posicion correspondiente. En caso contrario, regresa 0.
{
    int i = 0, ban = 0, res;
    while (i < t && !ban)
        if (a[i] == k)
        ban++;
    else
        i++;
    if (ban)
        res = i + 1;
    //Se asigna i+1 dado que las posiciones en el arreglo comienzan desde cero.
    else
        res = ban;
    return (res);
}
