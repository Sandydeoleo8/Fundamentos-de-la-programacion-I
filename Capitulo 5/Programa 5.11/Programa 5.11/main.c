#include <stdio.h>

// Busqueda binaria.

const int max = 100;

void lectura(int, int);         //Prototipo de funciones.
int binaria(int *, int, int);

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
    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", ele);
    res = binaria(vec, tam, ele);   //Se llama a la funcion que busca en el arreglo.

    if(res)
        //Si res tiene un valor verdadero -diferente de 0-, se escribe la posicion en la que se encontro el elemento.
        printf("\nEl elemento se encuentra en la posicion: %d", res);
    else
        printf("\nEl elemento no se encuentra en el arreglo.");
}

void lectura(int a[], int t)
// La funcion lectura se utliza para leer un arreglo unidimencional de t elemntos de tipo entero.
{
    int i;
    for(i = 0; i < t; i++)
    {
        printf("Ingrese el elemento %d: ", i+1);
        scanf("%d", &a[i]);
    }
}

int binaria(int a[], int t, int e)
//Esta funcion se utiliza para realizar una busqueda binaria del elemento e en el arreglo unidimencional a de t elementos. Si se encuentra el elemento, la funcion regresa la posicion correspondiente. En caso contrario, regresa o.
{
    int ele, izq = 0, cen, der = t-1, ban = 0;
    while ((izq <= der) && (!ban))
    {
        cen = (izq + der) / 2;
        if (e == a[cen])
            ban = cen;
        else
            if (e > a[cen])
            izq = cen + 1;
        else
        der = cen -1;
    }
    return(ban);
}
