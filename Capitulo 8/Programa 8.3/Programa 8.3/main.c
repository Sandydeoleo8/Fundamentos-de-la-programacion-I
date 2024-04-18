#include <stdio.h>
#include <string.h>

//Estructura
//El programa muestra la manera en que se declara una variable anidada, asi comoo la forma de acceso a los campos de las variables o apuntadores de tipo estructura, tanto para lectura como para escritura. Se utiliza ademas una funcion que recibe como parametro un apuntador de tipo estructura.

typedef struct          //Declaracion de la estructura domicilio utilizando un typedef.
{
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
}
domicilio;

struct empleado         //Declaracion de la estructura ananida empleado.

{
    char nombre[20];
    char departamento[20];
    float sueldo;
        domicilio direccion;            //Direccion es un campo de tipo estructura domicilio de la estructura empleado.

};

void lectura(struct empleado *a)
//Funcion que permite leer los campos de un apuntador de tipo estructura empleado.

{
    printf(" \n Ingrese el nombre del empleado: ");
    gets(a->nombre);
    fflush(stdin);
    printf("Ingrese el departamento de la empresa: ");
    gets(a->departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &a->sueldo);
    fflush(stdin);
    printf("—-Ingrese la dirección del empleado—-");
    printf("\n \t calle: ");
    gets(a->direccion.calle);
    printf("\t número: ");
    scanf("%d", &a->direccion.numero);
    printf("\t código postal: ");
    scanf("%d", &a->direccion.cp);
    fflush(stdin);
    printf("\t localidad: ");
    gets(a->direccion.localidad);
}

void main(void)
{
    struct empleado e0 = {"arturo", "compras", 15500.75, "san jeronimo", 120, 3490, "toluca"};
    struct empleado *e1, *e2, e3, e4;
    //Se declaran diferentes variables y apuntadores de la estructura empleado para que el lector pueda apreciar tambien las diferentes formas en que los campos reciben valores.

    //En el programa principal se leen los campos de una variable, e3, y un apuntador de tipo estructura, *e1.
    e1 = new(struct empleado);
    printf("\nIngrese el nombre del empleado 1: ");
    scanf("%s", &(*e1).nombre);
    fflush(stdin);
    printf("Ingrese el departamento de la empresa: ");
    gets(e1->departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e1->sueldo);
    printf("—-Ingrese la dirección del empleado—-");
    printf("\n \t calle: ");
    fflush(stdin);
    gets(e1->direccion, calle);
    printf("\t número: ");
    scanf("%d", &e1->direccion.numero);
    printf("\t código postal: ");
    scanf("%d", &e1->direccion.cp);
    printf("\t localidad: ");
    fflush(stdin);
    gets(e1->direccion.localidad);

    printf("\n Ingrese el nombre del empleado 3: ");
    scanf("%s", &e3.nombre);
    fflush(stdin);
    printf("Ingrese el departamento de la empresa: ");
    gets(e3.departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e3.sueldo);
    printf("—-Ingrese la dirección del empleado—-");
    printf("\n \t calle: ");
    fflush(stdin);
    gets(e3.direccion.calle);
    printf("\t número: ");
    scanf("%d", &e3.direccion.numero);
    printf("\t código postal: ");
    scanf("%d", &e3.direccion.cp);
    printf("\t localidad: ");
    fflush(stdin);
    gets(e3.direccion.localidad);

    //En la funcion lectura se leen los campos de una variable, e4, y un apuntador de tipo estructura, *e2.
    e2 = new (struct empleado);
    lectura(e2);

    lectura(&e4);

    printf("\n Datos del empleado 1 \n");
    printf("%s \t %s \t %.2f \t %s \t %d \t %d \t %s", e1->nombre, e1->departamento, e1->sueldo, e1->direccion.calle, e1->direccion.numero, e1->direccion.cp, e1->direccion.localidad);

    printf("\n Datos del empleado 4 \n");
    printf("%s \t %s \t %.2f \t %s \t %d \t %d \t %s", e4.nombre, e4.departamento, e4.sueldo, e4.direccion.calle, e4.direccion.numero, e4.direccion.cp, e4.direccion.localidad);

}
