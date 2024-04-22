#include <stdio.h>          //Declaracion de bibliotecas
#include <math.h>

float interes;          //Declaracion de variables globales.
float capital;          //Declaracion de variables globales.
int periodo;           //Declaracion de variables globales.

//Funciones para calcular los parametros del prestamo.
float pagomensual(float capital, int periodo)
{
    float interesmensual = interes / 12 / 100;            //Para calcular el interes mensual debemos dividir el interes por 12 y luego por 100.
    float cuota = (capital * interesmensual) / (1 - pow(1 + interesmensual, - periodo));          //Para calcular la cuota utlizamos la formula de amortizacion de prestamos la cual es (1 + interes)^periodo * interes / (1 + interes)^periodo - 1.
    return cuota;           //Devuelve el valor a cuota.
}

void guardarArchivo(float interesguardado, float capitalguardado, int periodoguardado)          //Se declara la funcion guardarArchivo que toma tres parametros, interesguardado, capitalguardado y periodo guardado.
{
    FILE *archivo;          //Se declara un puntero tipo FILE que tiene por nombre archivo.
    archivo = fopen("archivo_prestamo.txt", "w");           //En esta linea se abre el archivo en modo escritura.
    if (archivo == NULL)            //En esta linea se verifica si el archivo se abrio correctamente.
    {
        printf("No se pudo abrir el archivo");          //Se imprime un mensaje en cual indica que no se abrio el archivo correctamente.
        return;
    }
    fprintf(archivo, "%.2f %.2f %d", interesguardado, capitalguardado, periodoguardado);            //Esta linea imprime los valores de los parametros en el archivo.
    fclose(archivo);            //Se cierra el archivo.
    printf("Archivo guardado");         //Se imprime un mensaje indicando que el archivo se guardo.
}

void cargarArchivo()            //Se declara la variable cargarArchivo.
{
    FILE *archivo;          //Se declara un puntero tipo FILE que lleva por nombre archivo.
    archivo = fopen("archivo_prestamo.txt", "r");           //Se abre el archivo en modo lectura.
    if(archivo == NULL)         //Se verifica si el archivo se abre correctamente.
    {
        printf("No se puedo abrir el archivo");         //Se imprime un mensaje el cual indica que el archivo no se pudo abrir
    }
    fscanf(archivo, "%f, %f, %d", &capital, &interes, &periodo);            //Imprime los valores desde archivo y los almacena en las variables capital, interes, periodo.
    fclose(archivo);            //Se cierra el archivo.
    printf("Archivo de prestamo cargado");          //Se imrpime un mensaje el cual indica que el archivo se cargo correctamente.
}

int main ()
{
    int opcion = 0;         //Se declara la variable en opcion y se inicializa en 0 para controlar el bucle while.
    while (opcion != 3)         //Se inicia un bucle while el cual se ejecuta mientras la opcion sea diferente de 3.
    {
        printf("Menu:\n");          //Imprime el menu del programa y las otras cuatro que sigues despues de esto indican las opciones disponibles que tiene el usuario.
        printf("0. salir del programa.\n");
        printf("1. cambiar valores del prestamo.\n");
        printf("2. calcular prestamo.\n");
        printf("3. guardar archivo.\n");
        scanf("%d", &opcion);           //Lee la entrada del usuario y guarda la variable opcion, lo que permite seleccionar una opcion del menu.

        switch(opcion)          //Inicializa una estructura de control de fujo, que evalua la variable opcion.
        {
        case 0:         //Indica que esta linea se ejecutara cuando se ingrese 0 como opcion.
            printf("Saliendo del programa...\n");           //Imprime un mensaje el cual indica el final del programa.
            return 0;
        case 1:         //Indica que esta lines se ejecutara cuando se ingrese 1 como opcion.
            printf("Ingrese el capital: ");         //Se utiliza print y scanf para imprimir y leer los valores del capital.
            scanf("%f", &capital);

            printf("Ingrese periodos mensuales: ");         //Se utiliza print y scanf para imprimir y leer los valores de periodo.
            scanf("%i", &periodo);

            printf("Ingrese el interes del prestamo: ");                    //Se utliza print y scanf para imprimir y leer los valores de interes.
            scanf("%f", &interes);
            break;          //Rompe el bucle del case 1 y continua ejecutando el programa.
        case 2:         //Indica que esta lines se ejecutara cuando se ingrese 2 como opcion.
            {
                float cuota_mensual = pagomensual(capital, periodo);            //Se llama la funcion pagomensual pasando capital y periodo como argumentos. Esta calcula la cuota mensual y devuelve ese valor a la variable cuota_mensual.
                printf("La cuota mensual sera de: %.2f", cuota_mensual);            //Utilizamos esta funcion para imprimir cuota_mensual con 2 decimales.
                printf("\n\n");

                float capital_restante = capital;           //Declaramos la variable capital_restante y la igualamos a capital para representar el monto inicial del prestamo.
                for (int mes = 1; mes <= periodo; mes++)            //Se inicia un bucle para cada mes, se inicia en uno y se le suma uno mientras sea menor o igual al periodo.
                {
                    float interes_mensual =  (capital_restante * (interes / 12 / 100));         //Se declara la variable interes_mensual y iguala a la operacion resultante del capital restante por en interes / 12 / 100.
                    float cuota_mensual_ = pagomensual(capital_restante, periodo - mes + 1);            //Se declara la variable cuota_mensual y se iguala a pagomensual que toma como parametros capital_restante y periodo - mes + 1.
                    float resto_mensual = (capital_restante - cuota_mensual_);          //Se declara la variable resto_mensual y se iguala a la operacion resultante de capital_restante - cuota_mensual.

                    printf("\n%-2d\t %-10.2f\t\t %-10.2f\t\t %-10.2f\t\t", mes, cuota_mensual, interes_mensual, resto_mensual);          //Esta funcion imprime los valores restantes de las operaciones anteriores, desde la linea que inicia el bucle hasta la liinea que termina.
                    capital_restante -= cuota_mensual_;         //Actualiza el valor de capital_restante, preparandolo para ser calculado el siguiente mes.
                }
            printf("\n\n");
        }
            break;          //Rompe el bucle del case 2 y continua ejecutando el programa.
        case 3:         //Indica que esta lines se ejecutara cuando se ingrese 2 como opcion.
            guardarArchivo(interes, capital, periodo);          //Esta linea llama la funcion guardarrArchivo y le pasa los valores de interes, capital y periodo como argumentos.
            break;          //Rompe el bucle del case 3 y continua ejecutando el programa.
        default:            //Esta linea se ejecuta cuando se ingresa un valor que no esta en el menu.
            printf("Ingresa una opcion valida.");           //Se imprime este mensaje indicando que ha ingresado una opcion invalida.
            break;          //Rompe el bucle y continua ejecutando el programa.
    }
}
return 0;           //Indica que la funcion main ha finalizado correctamente.
}
