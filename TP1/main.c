/*******************************************************************
*Programa: - Calculadora ­
*
*Objetivo:  El ingreso de dos operandos. Calcular y mostrar los siguientes calculos:
            SUMA, RESTA, DIVISION, MULTIPLICACION Y FACTORIAL.
            unOperando
            otroOperando

*
*Version: 0.1
*Fecha: 17/ 04/ 2021
*Autor: Rodriguez, Agustin Roman
*Division: 1c.
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


int main()
{
    float operandoUno;
    float operandoDos;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    long int resultadoFactorialUno;
    long int resultadoFactorialDos;
    int opcion;
    int banderaOperandos;

    banderaOperandos = 0;

    do{
        opcion = MenuOpciones(banderaOperandos, operandoUno ,operandoDos);
        switch(opcion)
        {
            case 1:
                operandoUno = PedirNumero();
            break;
            case 2:
                operandoDos = PedirNumero();
                banderaOperandos = 1;
            break;
            case 3:
                resultadoSuma = SumarOperandos(operandoUno, operandoDos);
                resultadoResta = RestarOperandos(operandoUno, operandoDos);
                resultadoDivision = DividirOperandos(operandoUno, operandoDos);
                resultadoMultiplicacion = MultiplicarOperandos(operandoUno, operandoDos);
                resultadoFactorialUno = FactorialOperando(operandoUno);
                resultadoFactorialDos = FactorialOperando(operandoDos);
            break;
            case 4:
                MostrarSuma(resultadoSuma);
                MostrarResta(resultadoResta);
                MostrarDivision(resultadoDivision);
                MostrarMultiplicacion(resultadoMultiplicacion);
                MostrarFactorial(resultadoFactorialUno, resultadoFactorialDos);
            break;
            case 5:
                printf("...ADIOS...");
            break;
        }
    }while(opcion!=5);


    return 0;
}




