#include <stdio.h>

// Busqueda secuencial en arreglos ordenados en forma creciente.

const int max = 100;

void lectura(int, int);             // prototipos de funciones.
int buscar(int *, int, int);

void main(void)
{
    int res, ele, tam, vec[max];
    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &tam);
    }
    while (tam > max || tam < 1);
    //Se verifica que el tamano del arreglo sea correcto.
    lectura(vec, tam);
    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ele);
    res = buscar(vec, tam, ele);        //Se llama a la funcion que busca en el arreglo.

    if(res)
        //Si res tiene un valor verdadero -diferente de 0-, se escribe la posicion en la que se encontro al elemento.
        printf("\\nEl elemento se encuentra en la posicion: %d", res);
    else
        printf("\nEl elemento no se encuentra en el arreglo");
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

int buscar(int a[], int t, int e)
//Esta funcion se utiliza para localizar el elemento e en el arreglo unidimencional a. Si se encuentra, la funcion regresa la posicion correspondiente. Enn caso contrario regresa a 0.
{
    int res, i = 0, ban = 0;
    while ((i < t) && (e > a[i]) && !ban)
        //Observa que se incorpora una nueva condicion.
        if (a[i] == e)
        ban++;
    else
        i++;
    if (ban)
        res = i + 1;
    //Se asigana i + 1 dado que las posiciones en el arreglo comienzan desde cero.
    else
        res = ban;
    return (res);
}
