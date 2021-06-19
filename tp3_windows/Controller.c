#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "General.h"
#include "Controller.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pData = NULL;
	int index;

	pData = fopen(path, "r");

	if(pArrayListEmployee != NULL && pData != NULL)
	{
		index = parser_EmployeeFromText(pData, pArrayListEmployee);
	}

	fclose(pData);

	return index;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pData;
	int index;

	pData = fopen(path, "rb");

	if(pArrayListEmployee != NULL && pData != NULL)
	{
		index = parser_EmployeeFromBinary(pData, pArrayListEmployee);
	}

	fclose(pData);

	return index;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int auxId;
	char auxNombre[125];
	int auxHsTrabajadas;
	int auxSueldo;
	int size;
	int index;

	index = -1;
	size = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL)
	{
		auxEmployee = employee_new();
		if(auxEmployee != NULL)
		{
			auxId = g_GenerarId(size, 1000);
			employee_setId(auxEmployee, auxId);
			g_PedirCadena("\nIngrese nombre del empleado: ", auxNombre);
			employee_setNombre(auxEmployee, auxNombre);
			auxHsTrabajadas = g_ValidarEntero("\nIngrese las horas trabajadas por el empleado: ", "\nERROR. Reingrese las horas trabajadas: ", 0, 900);
			employee_setHorasTrabajadas(auxEmployee, auxHsTrabajadas);
			auxSueldo = g_ValidarEntero("\nIngrese el sueldo del empleado: ", "\nERROR. Reingrese el sueldo del empleado: ", 0, 10000);
			employee_setSueldo(auxEmployee, auxSueldo);
		}
		index = ll_add(pArrayListEmployee, (Employee*)auxEmployee);
	}

	return index;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int i;
	int index;
	//int indexEdit;
	int idSeleccionado;
	int size;
	int auxId;
	char auxNombre[120];
	int auxHsTrabajadas;
	int auxSueldo;

	index = -1;
	size = ll_len(pArrayListEmployee);

	controller_ListEmployee(pArrayListEmployee);
	idSeleccionado = g_PedirEntero("\nIngrese el id que desea modificar: ");

	for(i=0; i<size; i++)
	{
		auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
		if(auxEmployee != NULL)
		{
			employee_getId(auxEmployee, &auxId);
			employee_getNombre(auxEmployee, auxNombre);
			employee_getHorasTrabajadas(auxEmployee, &auxHsTrabajadas);
			employee_getSueldo(auxEmployee, &auxSueldo);
			if(auxId == idSeleccionado)
			{
				index = i;
			}
			break;
		}
	}

	return index;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int size;
	int index;
	int idSeleccionado;
	int indexRemove;
	int auxId;
	char auxNombre[120];
	int auxHsTrabajadas;
	int auxSueldo;
	Employee* auxEmployee;

	index = -1;
	size = ll_len(pArrayListEmployee);

	controller_ListEmployee(pArrayListEmployee);
	idSeleccionado = g_PedirEntero("\nIngrese el id que desea eliminar: ");

	for(i=0; i<size; i++)
	{
		auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
		if(auxEmployee != NULL)
		{
			employee_getId(auxEmployee, &auxId);
			employee_getNombre(auxEmployee, auxNombre);
			employee_getHorasTrabajadas(auxEmployee, &auxHsTrabajadas);
			employee_getSueldo(auxEmployee, &auxSueldo);
			if(auxId == idSeleccionado)
			{
				index = i;
			}
			break;
		}
	}

	//funcion mostrar un empleado
	printf("\n  Id     Nombre  Horas Trabajadas        Sueldo\n");
	printf("%4d %10s %10d              $%d\n", auxId, auxNombre, auxHsTrabajadas, auxSueldo);
	//funcion validar remove
	indexRemove = ll_remove(pArrayListEmployee, index);
	g_MensajeRetorno(indexRemove, "\nEmpleado removido con exito...","\nERROR. No se removio el empleado...");

	return index;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int index;
	int i;
	int size;
	int auxId;
	int auxHorasTrabajadas;
	int auxSueldo;
	char auxNombre[120];

	index = -1;

	if(pArrayListEmployee!=NULL)
	{
		size = ll_len(pArrayListEmployee);
		printf("%d", size);
		if(size > 0)
		{
			printf("\n|  ID  |    NOMBRE   | HS TRABAJO | SUELDO |\n\n");
			for(i=0; i<size; i++)
			{
				auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
				if(auxEmployee!=NULL)
				{
					employee_getId(auxEmployee, &auxId);
					employee_getNombre(auxEmployee, auxNombre);
					employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas);
					employee_getSueldo(auxEmployee, &auxSueldo);
					printf("%2d %10s %10d %5d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
				}
			}
			index = 1;
			printf("\n");
		}
	}
	return index;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int index;
	int option;
	int orden;

	option = g_PedirEntero("\n1| Ordenar por nombre.\n2| Ordenar por id.");

	if(option == 1)
	{
		orden = g_ValidarEntero("\n+++ POR NOMBRE +++\n0| Orden ascendente.\n1| Orden descendente.\nSeleccione un orden: ","\nERROR. Ingrese opcion valida: ", 0, 1);
		index = ll_sort(pArrayListEmployee, employee_CompareByName,orden);
	}else
	{
		orden = g_ValidarEntero("\n+++ POR ID +++\n0| Orden ascendente.\n1| Orden descendente.\nSeleccione un orden: ", "ERROR. Ingrese opcion valida: ", 0, 1);
		index = ll_sort(pArrayListEmployee, employee_CompareById, orden);
	}

	return index;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int i;
	int index;
	int size;
	Employee* auxEmployee;
	int auxId;
	char auxNombre[120];
	int auxHorasTrabajadas;
	int auxSueldo;
	FILE* pData;

	size = ll_len(pArrayListEmployee);
	pData = fopen(path, "w");
	index = -1;

	if(pData != NULL)
	{
		for(i=0; i<size; i++)
		{
			auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			if(auxEmployee!=NULL)
			{
				employee_getId(auxEmployee, &auxId);
				employee_getNombre(auxEmployee, auxNombre);
				employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas);
				employee_getSueldo(auxEmployee, &auxSueldo);
				fprintf(pData, "%d,%s,%d,%d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
				index = 1;
			}
		}
	}

	fclose((FILE*)path);

	return index;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int i;
	int index;
	int size;
	Employee* auxEmployee;
	int auxId;
	char auxNombre[120];
	int auxHorasTrabajadas;
	int auxSueldo;
	FILE* pData;

	size = ll_len(pArrayListEmployee);
	pData = fopen(path, "wb");
	index = -1;

	if(pData != NULL)
	{
		for(i=0; i<size; i++)
		{
			auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			if(auxEmployee!=NULL)
			{
				employee_getId(auxEmployee, &auxId);
				employee_getNombre(auxEmployee, auxNombre);
				employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas);
				employee_getSueldo(auxEmployee, &auxSueldo);
				fprintf(pData, "%d,%s,%d,%d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
				index = 1;
			}
		}
	}

	fclose((FILE*)path);

	return index;
}

int MenuOpciones()
{
    int opcion;

    printf("\n| --> MENU PRINCIPAL <-- |\n");
    printf("|1| CARGAR DATOS MODO TXT.\n");
    printf("|2| CARGAR DATOS MODO BIN.\n");
    printf("|3| ALTA EMPLEADO.\n");
    printf("|4| MODIFICAR DATOS EMPLEADO.\n");
    printf("|5| BAJA EMPLEADO.\n");
    printf("|6| LISTAR EMPLEADOS.\n");
    printf("|7| ORDENAR EMPLEADOS.\n");
    printf("|8| GUARDAR DATOS MODO TXT.\n");
    printf("|9| GUARDAR DATOS MODO BIN.\n");
    printf("|10| SALIR.\n");
    opcion = g_PedirEntero("Que desea realizar? ");

    return opcion;
}

void InteractuarMenu(int opcion, LinkedList* ListEmployee)
{
    int retornoCargarTxt;
    int retornoCargarBin;
    int retornoAlta;
    int retornoModificar;
    int retornoBaja;
    int retornoListar;
    int retornoSort;
    int retornoGuardarTxt;
    int retornoGuardarBin;

    switch(opcion)
    {
        case 1:
            retornoCargarTxt = controller_loadFromText("data.csv", ListEmployee);
            g_MensajeRetorno(retornoCargarTxt, "CARGA TXT EXITOSA...", "ERROR AL CARGAR TXT...");
        break;
        case 2:
            retornoCargarBin = controller_loadFromBinary("data.bin", ListEmployee);
            g_MensajeRetorno(retornoCargarBin, "CARGA BIN EXITOSA...", "ERROR AL CARGAR BIN...");
        break;
        case 3:
            retornoAlta = controller_addEmployee(ListEmployee);
            g_MensajeRetorno(retornoAlta, "ALTA DEL EMPLEADO REALIZADA CON EXITO...", "ERROR AL DAR DE ALTA DEL EMPLEADO...");
        break;
        case 4:
            retornoModificar = controller_editEmployee(ListEmployee);
            g_MensajeRetorno(retornoModificar, "EMPLEADO MODIFICADO CON EXITO...", "ERROR AL MODIFICAR EL EMPLEADO...");
        break;
        case 5:
            retornoBaja = controller_removeEmployee(ListEmployee);
            g_MensajeRetorno(retornoBaja, "EMPLEADO REMOVIDO CON EXITO...", "ERROR AL REMOVER EMPLEADO...");
        break;
        case 6:
            retornoListar = controller_ListEmployee(ListEmployee);
            g_MensajeRetorno(retornoListar, "LISTADO EXITOSO...", "ERROR AL LISTAR...");
        break;
        case 7:
            retornoSort = controller_sortEmployee(ListEmployee);
            g_MensajeRetorno(retornoSort, "ORDENAMIENTO REALIZADO CON EXITO...", "ERROR AL ORDENAR...");
        break;
        case 8:
             retornoGuardarTxt = controller_saveAsText("data.csv", ListEmployee);
             g_MensajeRetorno(retornoGuardarTxt, "GUARDADO TXT REALIZADO CON EXITO...", "ERROR AL GUARDAR TXT...");
        break;
        case 9:
            retornoGuardarBin = controller_saveAsBinary("data.bin", ListEmployee);
            g_MensajeRetorno(retornoGuardarBin, "GUARDADO BIN REALIZADO CON EXITO...", "ERROR AL GUARDAR BIN...");
        break;
        case 10:
            printf("\nADIOS...");
        break;
    }

}
