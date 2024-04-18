#include <stdio.h>

//Este programa convierte las letras mayusculas a minusculas.

//Las letras son variables de tipo entero.

void main(void)
{
    char letra;
    printf("Ingrese una letra");
    scanf("%c" &letra);
    if(letra >= 'A' && letra <= 'Z')
    letra = letra;
    printf("La letra es mayuscula");

}
