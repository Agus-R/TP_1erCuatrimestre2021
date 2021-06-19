#include "General.h"

int g_PedirEntero(char frase[])
{
    int entero;

    printf("%s", frase);
    scanf("%d", &entero);

    return entero;
}

float g_PedirFlotante(char frase[])
{
    float flotante;

    printf("%s", frase);
    scanf("%f", &flotante);

    return flotante;
}

char g_PedirCaracter(char frase[])
{
    char caracter;

    printf("%s", frase);
    fflush(stdin);
    scanf("%c", &caracter);

    return caracter;
}

void g_PedirCadena(char frase[], char cadena[])
{
    printf("%s", frase);
    fflush(stdin);
    scanf("%[^\n]", cadena);
}

int g_ValidarEntero(char frase[], char fraseError[], int parametroUno, int parametroDos)
{
    int numero;
    numero = g_PedirEntero(frase);
    while(!(numero >= parametroUno && numero <= parametroDos))
    {
        numero = g_PedirEntero(fraseError);
    }

    return numero;
}

float g_ValidarFlotante(char frase[], char fraseError[], int parametroUno, int parametroDos)
{
    float numero;
    numero = g_PedirFlotante(frase);
    while(!(numero > parametroUno && numero < parametroDos))
    {
        numero = g_PedirFlotante(fraseError);
    }

    return numero;
}

int g_GenerarId(int numero, int indice)
{
    int id;

    if(numero==0)
    {
        id = indice;
    }else{
        id = indice + numero;
    }

    return id;
}

void g_MayusculaMinuscula(char cadena[])
{
    int i;
    int size;

    size = strlen(cadena);

    for(i=0; i<size; i++)
    {
        if(i == 0)
        {
            cadena[i] = toupper(cadena[i]);
        }else
        {
            if(cadena[i] == ' ')
            {
                i++;
                cadena[i] = toupper(cadena[i]);
            }else
            {
                cadena[i] = tolower(cadena[i]);
            }
        }
    }
}

void g_MensajeRetorno(int index, char mensaje[], char mensajeError[])
{
    if(index != -1)
    {
        printf("\n%s\n", mensaje);
    }else
    {
        printf("\n%s\n", mensajeError);
    }
}
