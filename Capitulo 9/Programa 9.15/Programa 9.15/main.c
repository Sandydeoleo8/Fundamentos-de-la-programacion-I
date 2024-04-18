#include <stdio.h>
#include <ctype.h>

//Letras minuscula y mayusculas.
//El rpograma, al recibir como dato un archivo formado por cadenas de caracteres, dtermina el numero de letras mayusculas y minusculas que hay en el archivo.

void minymay(FILE *);           //Prototipo de funcion.

void main(void)
{
    FILE *ap;
    if((ap=fopen ("arc.txt", "r")) != NULL)
    {
        minymay(ap);
        fclose(ap);
    }
    else
        printf("No se puede abrir el archivo");
}

void minymay(FILE *ap1)
//Esta funcion se utiliza para leer cadenas de caracteres de un archivo y contar el numero de letras minusculas y mayusculas que existen en el archivo.
{
    char cad[30];
    int i, mi = 0, ma = 0;
    while (!feof(ap1))
    {
        fgets(cad, 30, ap1);
        //Se utiliza la funcion fgets() para leer cadenas de caracteres del archivo.
        i = 0;
        while (cad[i] != '\0')
        {
            if (islower(cad[i]))
                mi++;
            else
                if (isupper(cad[i]))
                ma++;
            i++;
        }
    }
    printf("\n\nNumero de letras minusculas: %d", mi);
    printf("\n\nNumero de letras mayusculas: %d", ma);
}
