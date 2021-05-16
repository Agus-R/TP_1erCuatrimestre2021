#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_FRASE 100
#define OCUPADO 1
#define VACIO 0

int g_MostrarOpciones();

int g_PedirEntero(char[TAM_FRASE]);
float g_PedirFlotante(char[TAM_FRASE]);
char g_PedirCaracter(char[TAM_FRASE]);
void g_PedirCadena(char[TAM_FRASE], char[]);

int g_ValidarEntero(char[TAM_FRASE], char[TAM_FRASE], int, int, int);
float g_ValidarFlotante(char[TAM_FRASE], char[TAM_FRASE], float, int, int);

int g_GenerarId(int, int);

void g_MayusculaMinuscula(char[]);

void g_MensajeRetorno(int, char[TAM_FRASE], char[TAM_FRASE]);
void g_MensajeBaja(int, char[TAM_FRASE], char[TAM_FRASE]);
void g_MensajePromedio(float, char[TAM_FRASE], char[TAM_FRASE]);
