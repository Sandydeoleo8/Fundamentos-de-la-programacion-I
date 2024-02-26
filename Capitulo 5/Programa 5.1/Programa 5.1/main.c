#include <stdio.h>
#define CANT 5

/* Cuenta-numeros.
El programa, al recibir como datos un arreglo unidimencional de tipo entero y un numero entero, determina cuantas veces se encuentra el numero de arreglos. */

void main(void)
{
    int I, NUM, CUE = 0;
    int ARRE[CANT];
    for (I=0; I<CANT; I++)
    {
        printf("Ingrese el elemento %d del arreglo: ", I+1);
        scanf("%d", &ARRE[I]);          // Lectura -asignacion- del arreglo.
    }
    printf("\n\nIngrese el numero que se va a buscar: ");
    scanf("%d", &NUM);
    for (I=0; I<CANT; I++)
        if (ARRE[I] == NUM)             // Comparacion del numero con los elementos del arreglo.
        CUE++;
}
