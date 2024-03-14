#include <stdio.h>

/* Fabrica de lacteos.
El programa, al recibir como datos las ventas mensuales de diferentes productos, obtiene informacion estadistica valiosa para la empresa. */

void lectura1(int [15][12]);
void lectura2(float, int);
void funcion1(int [][12], int, int, float *, float *);          //Prototipo de funciones.
void funcion2(float *, int);
void funcion3(float *, int);

void main(void)
{
    int fab[15][12] = {0};                                      //I=nicializacion en 0 del arreglo fab.
    float cos[15], ven[15];
    lectura1(fab);
    lectura2(cos, 15);
    funcion1(fab, 15, 12, cos, ven);
    funcion2(ven, 15);
    funcion3(ven, 15);
}

void lectura1(int a[][12])
//Esta funcion se utiliza para almacenar en el arreglo bidimensional las diferentes transacciones que representan las ventas de los diferentes productos. El fin de datos esta dado por -1.
{
    int mes, pro, can;
    printf("\nIngrese mes, tipo de producto y cantidad vendida: ");
    scanf("%d %d %d", &mes, &pro, &can);
    while (mes!= -1 && pro!= -1 && can!= -1)
    {
        a[mes - 1][pro - 1] += can;
        printf("Ingrese mes, tipo de producto y cantidad vendida: ");
        scanf("%d %d %d", &mes, &pro, &can);
    }
}

void lectura2(float a[], int n)
//Esta funcion se utiliza para leer los precios de venta de los diferentes productos.
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Ingrese costo del producto %d: ", i+1);
        scanf("%f", &a[i]);
    }
}

void funcion1(int a[][12], int f, int c, float v1[], float v2[])
//Esta funcion se utiliza para calcular el monto anual de cada uno de los productos. Observa que el resultado se almacena en un arreglo unidimensional que se utilizara posteriormente.
{
    int i, j, sum;
    printf("\n");
    for (i =0; i < f; i++)
    {
        sum = 0;
        for (j = 0; j < c; j++)
            sum += a[i][j];
        v2[i] = v1[i] * sum;
        printf("\nTotal de ventas del producto %d: %8.2f", i+1, v2[i]);
    }
}

void funcion2(float a[], int c)
//Esta funcion se utiliza para calcular el monto total de ventas de la fabrica.
{
    int i;
    float sum =0.0;
    for (i = 0; i < c; i++)
        sum += a[i];
    printf("\n\nTotal de ventas de la fabrica: %.2f", sum);
}

void funcion3(float a[], int c)
//Esta funcion se utiliza para obtener el tipo de producto que mas se ha vendido y el monto de las ventas de dicho producto.
{
    int i, tpr = 0;
    float ven = a[0];
    for (i = 1; i < c; i++)
        if (ven = a[i])
    {
        tpr = i;
        ven = a[i];
    }
    printf("\n\nTipo de producto mas vendido: %d \t Ventas: %.2f", tpr + 1, ven);
}
