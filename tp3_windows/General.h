#ifndef GENERAL_H_
#define GENERAL_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_FRASE 100

int g_PedirEntero(char[TAM_FRASE]);
float g_PedirFlotante(char[TAM_FRASE]);
char g_PedirCaracter(char[TAM_FRASE]);
void g_PedirCadena(char[TAM_FRASE], char[]);

int g_ValidarEntero(char[TAM_FRASE], char[TAM_FRASE], int, int);
float g_ValidarFlotante(char[TAM_FRASE], char[TAM_FRASE], int, int);

int g_GenerarId(int, int);

void g_MayusculaMinuscula(char[]);

void g_MensajeRetorno(int, char[TAM_FRASE], char[TAM_FRASE]);

#endif /* GENERAL_H_ */
