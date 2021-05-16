#include "General.h"

#define ID_E 1000
#define S_MIN 0
#define S_MAX 10000
#define ID_S_MIN 1
#define ID_S_MAX 4
#define TH 5


typedef struct
{
    int id;
    char name[50];
    char lastname[50];
    float salary;
    int idSector;
    int isEmpty;
}sEmployee;

int e_MenuPrincipal(sEmployee[], int);

void e_InitEmployee(sEmployee[], int);
sEmployee e_CargarEmployee(int);
int e_BuscarLibre(sEmployee[], int);
int e_AltaEmployee(sEmployee[], int);
int e_BajaEmployee(sEmployee[], int);
int e_ModificarEmployee(sEmployee[], int);
int e_ListarPorNombreSector(sEmployee[], int);
int e_HarcodeoEmployee(sEmployee[], int);
int e_MenuCaseCuatro(sEmployee[], int);
int e_OrdenarPorId(sEmployee[], int);

int e_MostrarEmployee(sEmployee[], int);
void e_InterfazMostrarEmployee();

int e_MostrarMenuModificar();
void e_MenuModificacion(char[], char[], float, int);

void e_MostrarSectores();

float e_TotalPromedioSalarios(sEmployee[], int);
int e_SuperanSalarioPromedio(float, sEmployee[], int);
