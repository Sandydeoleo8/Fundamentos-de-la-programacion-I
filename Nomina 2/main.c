#include  <stdio.h>
/*Nomina
El programa, al recibir los salarios de 15 profesores, obtien el total de la nomina de la universidad.

I: variable de tipo entero
SAL y NOM: variable de tipo real. */

void main(void)
{
    int I;
    float SAL, NOM;

    for (I=1,  NOM = 0; I <= 5; I++)
    {
        printf("*\Ingrese el salario del profesor%d:\t", I);
        scanf("%f", &SAL);
        NOM = NOM + SAL;
    }
    printf("\nEl total de la nomina es: %.2f", NOM);
}
