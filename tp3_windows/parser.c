#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* eAux;
	int index;
	int r;
	char auxId[25];
	char auxNombre[150];
	char auxHorasTrabajadas[25];
	char auxSueldo[25];

	index = -1;

	r = fscanf(pFile, "%[^,], %[^,], %[^,], %[^,]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
	printf("\nLECTURA FSCANF FALSA LECTURA: %d\n", r);
	do
	{
		r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
		printf("\nLECTURA FSCANF DEL DO: %d\n", r);
		if(r == 4)
		{
			eAux = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
			index = ll_add(pArrayListEmployee, eAux);
			printf("\nLL ADD: %d\n", index);
		}
	}
	while(!feof(pFile));


	return index;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int index;
	int r;
	Employee* eAux;
	char auxId[25];
	char auxNombre[150];
	char auxHorasTrabajadas[25];
	char auxSueldo[25];

	index = -1;

	do
	{
		r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
		if(r == 4)
		{
			eAux = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
			ll_add(pArrayListEmployee, eAux);
			index = 1;
		}
	}while(!feof(pFile));

	return index;
}
