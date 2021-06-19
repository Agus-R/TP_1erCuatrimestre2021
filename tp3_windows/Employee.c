#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* pEmpleado;

    pEmpleado = (Employee*)malloc(sizeof(Employee));

    return pEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* eRetorno;

    eRetorno = employee_new();

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        employee_setId(eRetorno, atoi(idStr));
        employee_setNombre(eRetorno, nombreStr);
        employee_setHorasTrabajadas(eRetorno, atoi(horasTrabajadasStr));
        employee_setSueldo(eRetorno, atoi(sueldoStr));
    }

    return eRetorno;
}

void employee_delete(Employee* e1)
{
    free(e1);
}

int employee_setId(Employee* e1, int id)
{
    int index;

    index = -1;

    if(id > 0)
    {
        e1->id = id;
    }

    return index;
}

int employee_getId(Employee* e1, int* id)
{
    int index;

    index = -1;

    if(e1->id <= 0)
    {
        *id = e1->id;
        index = 1;
    }

    return index;
}

int employee_setNombre(Employee* e1, char* nombre)
{
    int index;

    index = -1;

    if(nombre == NULL)
    {
        strcpy(e1->nombre, nombre);
        index = 1;
    }

    return index;
}

int employee_getNombre(Employee* e1, char* nombre)
{
    int index;

    index = -1;

    if(e1->nombre != NULL)
    {
        strcpy(nombre, e1->nombre);
        index = 1;
    }

    return index;
}

int employee_setHorasTrabajadas(Employee* e1, int horasTrabajadas)
{
    int index;

    index = -1;

    if(horasTrabajadas > 0)
    {
        e1->horasTrabajadas = horasTrabajadas;
        index = 1;
    }

    return index;
}

int employee_getHorasTrabajadas(Employee* e1, int* horasTrabajadas)
{
    int index;

    index = -1;

    if(e1->horasTrabajadas > 0)
    {
        *horasTrabajadas = e1->horasTrabajadas;
        index = 1;
    }

    return index;
}

int employee_setSueldo(Employee* e1, int sueldo)
{
    int index;

    index = -1;

    if(sueldo > 0)
    {
        e1->sueldo = sueldo;
        index = 1;
    }

    return index;
}

int employee_getSueldo(Employee* e1, int* sueldo)
{
    int index;

    index = -1;

    if(e1->sueldo != 0)
    {
        *sueldo = e1->sueldo;
        index = 1;
    }

    return index;
}

int employee_CompareByName(void* empleado1, void* empleado2)
{
    int index;
    int retornoGetUno;
    int retornoGetDos;
    Employee* e1;
    Employee* e2;
    char* nombreUno = "";
    char* nombreDos = "";
    ///warning pide inicializar nombre uno y dos

    e1 = (Employee*)empleado1;
    e2 = (Employee*)empleado2;

    retornoGetUno = employee_getNombre(e1, nombreUno);
    retornoGetDos = employee_getNombre(e2, nombreDos);

    if(retornoGetUno == 1 && retornoGetDos == 1)
    {
        index = strcmp(e1->nombre, e2->nombre);
    }

    return index;
}

int employee_CompareById(void* empleado1, void* empleado2)
{
    int index;
    int retornoIdUno;
    int retornoIdDos;
    Employee* e1;
    Employee* e2;
    int* idUno = 0;
    int* idDos = 0;

    e1 = (Employee*)empleado1;
    e2 = (Employee*)empleado2;

    retornoIdUno = employee_getId(e1, idUno);
    retornoIdDos = employee_getId(e2, idDos);

    if(retornoIdUno == 1 && retornoIdDos == 1)
    {
        if(idUno < idDos)
        {
            index = 1;
        }
        else
        {
            if(idUno > idDos)
            {
                index = -1;
            }
            else
            {
                index = 0;
            }
        }
    }

    return index;
}


