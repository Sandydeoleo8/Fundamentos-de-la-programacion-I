#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cad[100];
    int i = 0;
    char c;
    int cnt = 0;
    printf("\nIngrese cadena de caracteres: ");
    gets(cad);
    cad[6] = '\0';
    printf("\n%s", cad);

    c = cad[i];


    while (!(c == '\0'))
    {
        c = cad[i];

        if(c == 'a' || c == 'A')
        {
            cnt++;
        }
        i++;
    }

    printf("\nCantidad de A =: %d", cnt);

    for(i = 0; i < 100; i++)
    {
        if(cad[i] == '0')
        {
            printf("\n$");
        }
        else
        {
            printf("\n%c", cad[i]);
        }
    }
}

//Este programa busca seis datos en una cadena de 100 caracteres, imprimiendo las veces que salga (a) ya sea mayuscula o minuscula.
