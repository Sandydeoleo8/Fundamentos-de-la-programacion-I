#include <stdio.h>
#include <stdlib.h>

int main()
{​​​​​

    double *ptrd;// variable tipo puntero
    int *num;
    int a[20];
    /*
    num = &a[0];
    *num = 10;
    num += 10;//matematica de puntero
    *num = 20;

    *num +=10;
    for(int i = 0;i < 20;i++)
    {​​​​​
      printf("\nValor de a[%d]=%d",i,a[i]);
    }​​​​​
*/


    double d1 = 18.0;
    int int1 = 97;
    printf("\nValor de d1 = %lf",d1);
    ptrd = &d1;//& operador de direccion
    *ptrd = 125.5;//* operador de in direccion

    printf("\nValor de d1 = %lf",d1);
    printf("\nValor de d1 = %lf",*ptrd);

    printf("\nDireccion de d1: %p",&d1);
    //un puntero es un numero entero a 64 bits

    printf("\n Dimencion de d1:%d",sizeof(d1));
    printf("\n Dimencion de a[20]:%d",sizeof(a));
    printf("\n Dimencion de a[1]:%d",sizeof(*a));
    printf("\n Dimencion de int:%d",sizeof(int1));

    return 0;
}​​​​​
