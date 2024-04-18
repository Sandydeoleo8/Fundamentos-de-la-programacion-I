#include <stdio.h>
#include <string.h>

//Escuela
//El programa genera informacion importante de los alumnos de una escuela.

typedef struct          //Declaracion de la estructura matpro.
{
    char mat[20];       //Materia.
    int pro;            //Promedio.
}matpro;

typedef struct          //Declaracion de la estructura alumno.
{
    int matri;          //Matricula.
    char nom[20];       //Nombre del alumno.
    matpro cal[5];          //Observa que cal es un arreglo unidimencional de tipo estructura matpro -la estructura definida en primer termino.
} alumno;

void Lectura(alumno *, int);
void f1(alumno*, int);
void f2(alumno*, int);          //Prototipo de funciones.
void f3(alumno*, int);

void main(void)
{
    alumno alu[50];             //alu es un arreglo unidimencional de tipo alumno.
    int tam;
    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &tam);
    }
    while (tam > 50 || tam < 1);            //Se verifica que el tamano del arreglo sea correcto.
    Lectura(alu, tam);
    f1(alu, tam);
    f2(alu, tam);
    f3(alu, tam);
}

void Lectura(alumno a[], int t)
//Esta funcion se utiliza para leer la informavion de un arreglo unidimencional de tipo estructura alumno de t elementos.
{
    int i, j;
    for (i=0; i<t; i++)
    {
        printf("\nIngrese los datos del alumno %d", i+1);
        printf("\nIngrese la matricula del alumno: ");
        scanf("%d", &a[i].matri);
        fflush(stdin);
        printf("Ingrese el nombre del alumno: ");
        gets(a[i].nom);
        for (j-0; j<5; j++)
        {
            printf("\tMateria %d: ", j+1);
            fflush(stdin);
            gets(a[i].nom);
            for (j=0; j<5; j++)
            {
                printf("\tMateria %d: ", j+1);
                fflush(stdin);
                gets(a[i].cal[j].mat);
                printf("\tPromedio %d ",j+1);
                scanf("%d". &a[i].cal[j].pro);
            }
        }
    }

    void f1(alumno a[], int t)
    //Esta funcion se utiliza para obtener la matricula y el promedio general de cada alumno cuya calificacion en la tercera materia es mayor a 9.
    {
        int i, j;
        float sum;
        for (i=0; i<t; i++)
        {
            printf("\nMatricula del alumno: %d", a[i].matri);
            sum = 0.0;
            for (j=0; j<5; j++)
                sum = sum + a[i].cal[j].pro;
            sum = sum / 5;
            printf("\tPromedio: %.2f", sum);
        }
    }

    void f2(alumno a[], int t)
    //Esta funcion se utiliza para obtener las matriculas de los alumnos cuya calificacion en la tercera materia es mayor a 9.
    int i;
    printf("\nAlumnos con calificacion mayor a 9 en la tercera materia");
    for (i=0; i<t; i++)
        if (a[i].cal[2].pro > 9)
        printf("\nMatricula del alumno: %d", a[i].matri);
}

void f3(alumno a[], int t)
//Esta funcion se utiliza para obtener el promedio general de la cuarta materia.
{
    int i;
    float sum 0.0;
    for (i=0; i<t; i++)
        sum = sum + a[i].cal[3].pro;
    sum = sum / t;
    printf("\n\nPromedio de la cuarta materia: %.2f", sum);
}
