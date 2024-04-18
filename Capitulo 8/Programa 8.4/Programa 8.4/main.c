#include <stdio.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nombre[30];
    float cal[5];
} alumno;

void lectura(alumno[], int);
void f1(alumno *, int);
void f2(alumno *, int);
void f3(alumno *, int);

int main(void)
{
    alumno arre[50];
    int tam;
    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &tam);
    } while (tam > 50 || tam < 1);
    lectura(arre, tam);
    f1(arre, tam);
    f2(arre, tam);
    f3(arre, tam);
    return 0;
}

void lectura(alumno a[], int t)
{
    int i, j;
    for (i = 0; i < t; i++)
    {
        printf("\nIngrese los datos del alumno %d", i + 1);
        printf("\nIngrese la matricula del alumno: ");
        scanf("%d", &a[i].matricula);
        fflush(stdin);
        printf("Ingrese el nombre del alumno: ");
        fgets(a[i].nombre, 30, stdin);
        for (j = 0; j < 5; j++)
        {
            printf("\tIngrese la calificacion %d del alumno %d: ", j + 1, i + 1);
            scanf("%f", &a[i].cal[j]);
        }
    }
}

void f1(alumno a[], int t)
{
    int i, j;
    float sum, pro;
    for (i = 0; i < t; i++)
    {
        printf("\nMatricula del alumno: %d", a[i].matricula);
        sum = 0.0;
        for (j = 0; j < 5; j++)
            sum = sum + a[i].cal[j];
        pro = sum / 5;
        printf("\t\tPromedio: %.2f", pro);
    }
}

void f2(alumno a[], int t)
{
    int i;
    printf("\nAlumnos con calificacion en la tercera materia > 9");
    for (i = 0; i < t; i++)
        if (a[i].cal[2] > 9)
            printf("\nMatricula del alumno: %d", a[i].matricula);
}

void f3(alumno a[], int t)
{
    int i;
    float pro, sum = 0.0;
    for (i = 0; i < t; i++)
        sum = sum + a[i].cal[3];
    pro = sum / t;
    printf("\n\nPromedio de la materia 4: %.2f", pro);
}
