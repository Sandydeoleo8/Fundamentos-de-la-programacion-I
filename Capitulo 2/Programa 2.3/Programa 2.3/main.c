#include <stdio.h>
/* Promedio curso.
El programa, al recibir como dato el promediode un alumno en un curso universitario, escribe aprovado si su promedio es mayor o igual a 6, o reprobado en caso contrario.

PRO: variable de tipo real. */

void main(void)
{
    float PRO;
    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &PRO);
    if (PRO >= 6.0)
        printf("\nAprovado");
    else
        printf("\nReprobado");
}
