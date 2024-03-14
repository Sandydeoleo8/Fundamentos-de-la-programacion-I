#include <stdio.h>

/*Casa de bolsa.
El programa, al recibir como datos los precios mensuales de las acciones de sus cinco fondos de inversion, ademas del precio de las acciones al 31 de diciembre del 2003, genera informacion estadistica importante para la empresa. */

void lecturam(float, [][12], int, int);
void lecturav(float *, int);
void f1(float[][12], int, int, float *, float *);           //Prototipo de funciones.
void f2(float[][12],int, int);
void f3(float *, int);
