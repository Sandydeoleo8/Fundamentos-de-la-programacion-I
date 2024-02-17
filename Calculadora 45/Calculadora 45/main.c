#include <stdio.h>
#include <stdlib.h>
#define SALIR 0
#define SUM 1
#define RES 2
#define DIV 3
#define MUL 4
float Rest(float,float); //declaracion de funcion
int main()
{
    int menu = 0;
    float num1;
    float num2;
    float result;
    printf("CALCULADORA 45\n");

    do
    {
        printf("\n\n1-SUMA\n2-RESTA\n3-DIVICION\n4-MULTIPLICACION\n0-SALIR\n:");
        scanf("%d",&menu);

        if(menu == SUM)
        {
            printf("\nIngresar sumando 1:");
            scanf("%f", &num1);
            printf("\nIngresar suamndo 2:");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("\nLa suma de %f + %f = %f", num1,num2,result);
        }else if(menu == RES)
        {
        printf("\nIngresar Sustraendo:");
        scanf("%f", &num1);
        printf("\nIngresar Minuendo:");
        scanf("%f", num2);
        result = Rest(num1,num2);
        printf("\nLa resta de %f - %f = %f", num1,num2,result);

        }else if(menu == DIV)
        {

        }
}
