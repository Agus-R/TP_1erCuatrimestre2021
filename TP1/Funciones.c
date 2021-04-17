#include "Funciones.h"

/**
*\brief Muestra el menu de opciones.
*\param Recibe una bandera y dos numeros enteros.
*\return Devuelve la opcion seleccionada.
*
*/
int MenuOpciones(int bandera, int unNumero, int otroNumero)
{
    int respuesta;

    if(bandera == 0)
    {
        printf("|1| INGRESAR PRIMER OPERANDO.\n");
        printf("|2| INGRESAR SEGUNDO OPERANDO.\n");
        printf("|3| REALIZAR OPERACIONES.\n");
        printf("|4| MOSTRAR OPERACIONES.\n");
        printf("|5| SALIR.\n");
        printf("Elija una opcion: ");
        scanf("%d", &respuesta);
    }else
    {
        printf("\n|1| MODIFICAR PRIMER OPERANDO.  | %d |\n", unNumero);
        printf("|2| MODIFICAR SEGUNDO OPERANDO. | %d |\n", otroNumero);
        printf("|3| REALIZAR OPERACIONES.\n");
        printf("|4| MOSTRAR OPERACIONES.\n");
        printf("|5| SALIR.\n");
        printf("Elija una opcion: ");
        scanf("%d", &respuesta);
    }


    return respuesta;
}

/**
*\brief Pide y guarda un numero.
*\param Void.
*\return Devuelve numero ingresado.
*
*/
float PedirNumero()
{
    float numero;

    printf("Ingrese operando: ");
    scanf("%f", &numero);

    return numero;
}

/**
*\brief Realiza una suma de dos valores.
*\param Recibe dos numeros flotantes.
*\return Retorna un resultado flotante.
*
*/
float SumarOperandos(float unNumero, float otroNumero)
{
    float suma;

    suma = unNumero + otroNumero;

    return suma;
}

/**
*\brief Realiza la resta de dos valores.
*\param Recibe dos numeros flotantes.
*\return Retorna un resultado flotante.
*
*/
float RestarOperandos(float unNumero, float otroNumero)
{
    float resta;

    resta = unNumero - otroNumero;

    return resta;
}

/**
*\brief Realiza la division de dos numeros.
*\param Recibe dos numeros flotantes.
*\return Retorna un resultado flotante.
*
*/
float DividirOperandos(float unNumero, float otroNumero)
{
    float division;

    if(unNumero == 0 || otroNumero == 0)
    {
        division = 0;
    }
    else
    {
        division = unNumero/otroNumero;
    }

    return division;
}

/**
*\brief Realiza la multiplicacion de dos numeros.
*\param Recibe dos numeros flotantes.
*\return Retorna un resultado flotante.
*
*/
float MultiplicarOperandos(float unNumero, float otroNumero)
{
    float multiplicacion;

    multiplicacion = unNumero * otroNumero;

    return multiplicacion;
}

/**
*\brief Realiza el factorial de un numero natural.
*\param Recibe un numeros flotantes.
*\return Retorna un resultado entero.
*
*/
long int FactorialOperando(float unNumero)
{
    int factorial;

    if(unNumero < 0)
    {
        factorial = -1;
    }else
    {
        if(unNumero == 0)
        {
            factorial = 1;
        }else
        {
            factorial = (int)unNumero * FactorialOperando(unNumero-1);
        }
    }

    return factorial;
}

/**
*\brief Se encarga de mostrar un resultado.
*\param Recibe un numeros flotante.
*\return Void.
*
*/
void MostrarSuma(float resultado)
{
    printf("\nEl resultado de | A+B | es: %f.\n", resultado);
}

/**
*\brief Se encarga de mostrar un resultado.
*\param Recibe un numeros flotante.
*\return Void.
*
*/
void MostrarResta(float resultado)
{
    printf("El resultado de | A-B | es: %f.\n", resultado);
}

/**
*\brief Se encarga de mostrar un resultado.
*\param Recibe un numeros flotante.
*\return Void.
*
*/
void MostrarDivision(float resultado)
{
    if(resultado == 0)
    {
        printf("No se pudo dividir. Operando/s igual a 0.\n");
    }else
    {
        printf("El resultado de | A/B | es: %f.\n", resultado);
    }
}

/**
*\brief Se encarga de mostrar un resultado.
*\param Recibe un numeros flotante.
*\return Void.
*
*/
void MostrarMultiplicacion(float resultado)
{
    printf("El resultado de | A*B | es: %f.\n", resultado);
}

/**
*\brief Se encarga de mostrar un resultado.
*\param Recibe dos numeros enteros.
*\return Void.
*
*/
void MostrarFactorial(long int resultadoA, long int resultadoB)
{
    if(resultadoA == -1 )
    {
        printf("No se pudo calcular factorial de | A |. Operando negativo.\n");
    }else
    {
        printf("El factorial de |A|: %d.\n", resultadoA);
    }


    if(resultadoB == -1)
    {
        printf("No se pudo calcular factorial de | B |. Operando negativo.\n");
    }else
    {
        printf("El factorial de |B|: %d.\n", resultadoB);
    }
}
