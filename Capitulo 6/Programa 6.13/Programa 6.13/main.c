#include <stdio.h>

/* Empresa textil.
El programa, al recibir un arreglo tridimensional que contiene informacion sobre las ventas mensuales de tres departamentos en los ultimos ocho anos, genera informacion estadistica valiosa para la empresa. */

const int mes = 12;
const int dep = 3;
const int ano = 8;

void lectura(float [mes][dep][ano], int, int, int);
void funcion1(float [mes][dep][ano], int, int, int);
void funcion2(float [mes][dep][ano], int, int, int);            //Prototipo de funciones.
void funcion3(float [mes][dep][ano], int, int, int);

void main(void)
{
    float pro[mes][dep][ano];
    lectura(pro, mes, dep, ano);
    funcion1(pro, mes, dep, ano);
    funcion2(pro, mes, dep, ano);
    funcion3(pro, mes, dep, ano);
}

void lectura(float a[][dep][ano], int f, int c, int p)
//La funcion lectura se utiliza para leer un arreglo tridimencional de tipo real de f filas, c columnas y p planos de profundidad.
{
    int k, i, j;
    for (k=0; k<p; k++)
        for (i=0; i<f; i++)
        for (j=0; j<c; j++)
    {
        printf("Ano: %d\tMes %d\tDepartamento: %d ", k+1, i+1, j+1);
        scanf("%f", &a[i][j][k]);
    }
}

    void funcion1(float a[][dep][ano], int f, int c, int p)
    //Esta funcion se utiliza para obtener las ventas totales de la empresa en el segundo ano.
    {
        int i, j;
        float sum = 0.0;
        for (i=0; i<f; i++)
            for (j=0; j<c; j++)
            sum += a[i][j][p-1];
        printf("\n\nVentas totales de la empresa en el segundo ano: %.2f", sum);
    }

    void funcion2(float a[][dep][ano], int f, int c, int p)
    //Esta funcion se utiliza para obtener el departamento que tuvo las mayores ventas en el ultimo ano. Genera ademas el importe de las ventas.
    {
        int i, j;
        float sum1 = 0, sum2 = 0, sum3 = 0;
        for (i=0; i<f; i++)
            for (j=0; j<c; j++)
            switch (j+1)
        {
            case 1: sum1 += a[i][j][p-1];
                break;
            case 2: sum1 += a[i][j][p-1];
                break;
            case 3: sum1 += a[i][j][p-1];
                break;
        }
        if (sum1 > sum2)
            if (sum1 > sum3)
        {
            printf("\n\nDepartamento con mayores ventas en el ultimo ano: Hilos");
            printf("Ventas: %.2f", sum1);
        }
        else
        {
            printf("\n\nDepartamento con matores ventas en el ultimo ano: Licra");
            printf("Ventas:%.2f", sum3);
        }
        else
            if (sum2 > sum3)
        {
            printf("\n\nDepartamento con matores ventas en el ultimo ano: Licra");
            printf("Ventas:%.2f", sum2);
        }
        else
        {
            printf("\n\nDepartamento con matores ventas en el ultimo ano: Licra");
            printf("Ventas:%.2f", sum3);
        }
    }

    void funcion3(float a[][dep][ano], int f, int c, int p)
    //Esta funcion se utiliza para obtener el departamento, mes y ano con la mayor venta. Escribe tambien el monto de las ventas.
    {
        int k, i, j, de, me, an;
        float ven = -1.0;
        for (k=0; k<p; k++)
            for (i=0; i<f; i++)
            for (j=0; j<c; j++)
            if (a[i][j][k] > ven)
        {
            ven = a[i][j][k];
            de = j;
            me = i;
            an = k;
        }
        printf("\n\nDepartamento: %d\tMes: %d\tAno: %d", de+1, me+1, an+1);
        printf("\tVentas: %.2f", ven);
    }
