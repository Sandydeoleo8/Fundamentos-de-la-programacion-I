#include <stdio.h>
/* Escuela.
El programa, al recibir como dato un archivo de acceso directo que contiene
informaci�n de los alumnos de una escuela, genera informaci�n estad�stica
importante. */
typedef struct /* Declaraci�n de la estructura matcal. */
{
    char materia[20];
    int calificacion;
} matcal;

typedef struct /* Declaraci�n de la estructura alumno. */
{
    int matricula;
    char nombre[20];
    matcal cal[5];
    /* Observa que un campo de esta estructura es a su vez estructura. */
} alumno;

/* Prototipos de funciones */
void F1(FILE *);
void F2(FILE *);
float F3(FILE *);

void main(void)
{
    float pro;
    FILE *ap;
    if ((ap = fopen("esc.dat", "rb")) != NULL)
    {
        F1(ap);
        F2(ap);
        pro = F3(ap);
        printf("\n\nPROMEDIO GENERAL MATERIA 4: %f", pro);
    }
    else
        printf("\nEl archivo no se puede abrir");
    fclose(ap);
}

void F1(FILE *ap)
/* La funci�n escribe la matr�cula y el promedio general de cada alumno. */
{
    alumno alu;
    int j;
    float sum, pro;
    printf("\nMATR�CULA y PROMEDIOS");
    while (fread(&alu, sizeof(alumno), 1, ap))
    {
        printf("\nMatr�cula: %d", alu.matricula);
        sum = 0.0;
        for (j = 0; j < 5; j++)
            sum += alu.cal[j].calificacion;
        pro = sum / 5;
        printf("\tPromedio: %f", pro);
    }
}

void F2(FILE *ap)
/* La funci�n escribe la matr�cula de los alumnos cuya calificaci�n en la
tercera materia es mayor a 9. */
{
    alumno alu;
    rewind(ap);
    printf("\n\nALUMNOS CON CALIFICACI�N > 9 EN MATERIA 3");
    while (fread(&alu, sizeof(alumno), 1, ap))
    {
        if (alu.cal[2].calificacion > 9)
            printf("\nMatr�cula del alumno: %d", alu.matricula);
    }
}

float F3(FILE *ap)
/* Esta funci�n obtiene el promedio general de la materia 4. */
{
    alumno alu;
    int i = 0;
    float sum = 0, pro;
    rewind(ap);
    while (fread(&alu, sizeof(alumno), 1, ap))
    {
        i++;
        sum += alu.cal[3].calificacion;
    }
    pro = (float)sum / i;
    return pro;
}
