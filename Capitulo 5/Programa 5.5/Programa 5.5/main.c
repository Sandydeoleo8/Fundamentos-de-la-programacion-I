#include <stdio.h>

/* Fecuencia de calificaciones.
El programa, al recibir como datos las calificaciones de un grupo de 50 alumnos, obtiene la frecuencia de cada una de las calificaciones y ademas escribe cual es la frecuencia mas alta. */

const int tam = 50;

void lectura(int *, int);
void frecuencia(int , int, int , int);            //Prototipo de funciones
void impresion(int *, int);
void mayor(int *, int);

void main(void)
{
    int cal[tam], fre[6] = {0};                 //Declaracion de los arreglos
    lectura(cal, tam);                          //Se llama a la funcion lectura.
    frecuencia(cal, tam, fre, 6);
    //Se llama a la funcion frecuencia, se pasan ambos arreglos.
    printf("\nFrecuencia de calificaciones\n");
    impresion(fre, 6);
    mayor(fre, 6);
}

void lectura(int vec[], int t)
//La funcion lectura se utiliza para leer el arreglo de calificaciones.
{
    int i;
    for (i = 0; i < t; i++)
{
    printf("Ingrese la calificacion -0:5- del alumno %d: ", i+1);
    scanf("%d", &vec[i]);
}
}

void impresion(int vec[], int t)
//La funcion impresion se utiliza para imprimir el arreglo de frecuancias.
{
    int i;
    for (i = 0; i < t; i++)
        printf("\nvec[%d]: %d", i, vec[i]);
}

void frecuencia(int a[], int p, int b[], int t)
//Esta funcion calcula la frecuencia de calificaciones.
{
    int i;
    for (i = 0; i < p; i++)
        if((a[i] >= 0 ) && (a[i] < 6))              //Se valida que la calificacion sea coorecta.
    b[a[i]]++;                                      //Observa la forma de almacenar e incrementar las frecuencias.
} // Esta es la llave que faltaba

void mayor(int*x, int t)
//Esta funcion obtiene la primera ocurrencia de la frecuencia mas alta.
{
    int i, mfre = 0, mval = x[0];
    for (i = 1; i < t; i++)
        if(mval < x[i])
    {
        mfre = i;
        mval = x[i];
    }

    printf("\n\nMayor frecuencia de calificaciones: %d \tValor: %d", mfre, mval);
}

