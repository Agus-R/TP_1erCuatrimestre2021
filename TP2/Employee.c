#include "Employee.h"

/** \brief Realiza la ejecucion del menu principal
 *
 * \param sEmployee la lista
 * \param int el tamaño de la lista
 * \return int Retorna la opcion seleccionada
 *
 */

int e_MenuPrincipal(sEmployee list[], int tam)
{
    int opcion;
    int retornoAlta;
    int retornoBaja;
    int retornoModificacion;

    e_InitEmployee(list, tam);
    do
    {
        opcion = g_MostrarOpciones();
        e_HarcodeoEmployee(list, TH);
        switch(opcion)
        {
            case 1:
                retornoAlta = e_AltaEmployee(list, tam);
                g_MensajeRetorno(retornoAlta, "ALTA REALIZADA CON EXITO...", "HUBO UN FALLO AL DAR DE ALTA...");
            break;
            case 2:
                retornoModificacion = e_ModificarEmployee(list, tam);
                g_MensajeRetorno(retornoModificacion, "MODIFICACION REALIZADA CON EXITO...", "HUBO UN FALLO AL MODIFICAR...");
            break;
            case 3:
                retornoBaja = e_BajaEmployee(list, tam);
                g_MensajeBaja(retornoBaja, "BAJA REALIZADA CON EXITO...", "HUBO UN FALLO AL DAR DE BAJA...");
            break;
            case 4:
                e_MenuCaseCuatro(list, tam);
            break;
            case 5:
                printf("Hasta pronto...\n");
            break;
        }
    }while(opcion != 5);

    return opcion;
}

/** \brief Permite seleccionar si desea listar o dar promedio
 *
 * \param sEmployee la lista
 * \param int el tamaño de la lista
 * \return int Retorna la opcion seleccionada
 *
 */
int e_MenuCaseCuatro(sEmployee list[], int tam)
{
    int opcion;
    int retornoListado;
    float retornoPromedio;

    printf("\n| 1 | LISTADO.  | 2 | PROMEDIO SALARIO.\n");
    opcion = g_PedirEntero("Ingrese una opcion: ");

    if(opcion == 1)
    {
        retornoListado = e_ListarPorNombreSector(list, tam);
        g_MensajeRetorno(retornoListado, "LISTADO EXITOSO...", "ERROR AL LISTAR...");
    }else
    {
        retornoPromedio = e_TotalPromedioSalarios(list, tam);
        g_MensajePromedio(retornoPromedio, "CALCULO DEL PROMEDIO EXITOSO...", "ERROR AL CALCULAR PROMEDIO...");
    }

    return opcion;
}

/** \brief Inicializa la bandera que indica el estado de la posicion del array
 *
 * \param sEmployee la lista
 * \param int el tamaño de la lista
 * \return void
 *
 */
void e_InitEmployee(sEmployee list[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        list[i].isEmpty = VACIO;
    }
}

/** \brief Realiza la carga de un solo empleado
 *
 * \param int recibe el indice del alta
 * \return sEmployee Retorna dicho empleado
 *
 */
sEmployee e_CargarEmployee(int indexAlta)
{
    sEmployee oneEmployee;

    oneEmployee.id = g_GenerarId(indexAlta, ID_E);
    g_PedirCadena("\nIngrese nombre: ", oneEmployee.name);
    g_MayusculaMinuscula(oneEmployee.name);
    g_PedirCadena("Ingrese apellido: ", oneEmployee.lastname);
    g_MayusculaMinuscula(oneEmployee.lastname);
    oneEmployee.salary = g_ValidarFlotante("Ingrese salario: ", "ERROR. Ingrese salario valido: ", oneEmployee.salary, S_MIN, S_MAX);
    e_MostrarSectores();
    oneEmployee.idSector = g_ValidarEntero("Ingrese id sector: ", "ERROR. Ingrese error valido: ", oneEmployee.idSector, ID_S_MIN, ID_S_MAX);
    oneEmployee.isEmpty = OCUPADO;

    return oneEmployee;
}

/** \brief Busca un espacio libre en el array
 *
 * \param sEmployee la lista
 * \param int el tamaño de la lista
 * \return int Retorna la poscicion disponible en el array
 *
 */
int e_BuscarLibre(sEmployee list[], int tam)
{
    int i;
    int index;

    index = -1;

    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty == VACIO)
        {
            index = i;
            break;
        }
    }

    return index;
}

/** \brief
 *
 * \param sEmployee la lista
 * \param int el tamaño de la lista
 * \return int Retorna el indice donde se realiza la carga
 *
 */
int e_AltaEmployee(sEmployee list[], int tam)
{
    int index;

    index = e_BuscarLibre(list, tam);

    if(index != -1)
    {
        list[index] = e_CargarEmployee(index);
    }

    return index;
}

/** \brief Muestra algunos datos almacenados en el array
 *
 * \param sEmployee la lista
 * \param int el tamaño de la lista
 * \return int Retorna el indice del ultimo elemento mostrado
 *
 */
int e_MostrarEmployee(sEmployee list[], int tam)
{
    int i;
    int index;

    index = -1;

    e_InterfazMostrarEmployee();
    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
            printf("| %d | %20s\t| %20s\t| %9.2f | %6d |\n", list[i].id, list[i].name, list[i].lastname, list[i].salary, list[i].idSector);
            index = i;
        }
    }

    return index;
}

/** \brief Realiza la baja logica de un elemento del array
 *
 * \param sEmployee la lista
 * \param int el tamaño de la lista
 * \return int Retorna la posicion del elemento borrado
 *
 */
int e_BajaEmployee(sEmployee list[], int tam)
{
    int i;
    int idBorrar;

    e_OrdenarPorId(list, tam);
    idBorrar = g_PedirEntero("Ingrese el ID del empleado que desea eliminar: ");
    for(i=0; i<tam; i++)
    {
        if(list[i].id == idBorrar)
        {
            list[i].isEmpty = VACIO;
            break;
        }
    }

    return i;
}

/** \brief Modifica algunos elementos de una posicion de la array seleccionada
 *
 * \param sEmployee la lista
 * \param int el tamaño de la lista
 * \return int Retorna la posicion del elemento borrado
 *
 */
int e_ModificarEmployee(sEmployee list[], int tam)
{
    int i;
    int idModificar;

    e_OrdenarPorId(list, tam);
    idModificar = g_PedirEntero("Ingrese ID del empleado a modificar: ");
    for(i=0; i<tam; i++)
    {
        if(idModificar == list[i].id)
        {
            e_MenuModificacion(list[i].name, list[i].lastname, list[i].salary, list[i].idSector);
        }
    }

    return i;
}

/** \brief Realiza la interaccion de un menu encargado de la modificacion
 *
 * \param sEmployee la lista
 * \param int el tamaño de la lista
 * \return void
 *
 */
void e_MenuModificacion(char nombre[], char apellido[], float salario, int idSector)
{
    int opcion;

    do
    {
        opcion = e_MostrarMenuModificar();
        switch(opcion)
        {
            case 1:
                g_PedirCadena("Ingrese nuevo nombre: ", nombre);
                g_MayusculaMinuscula(nombre);
            break;
            case 2:
                g_PedirCadena("Ingrese nuevo apellido: ", apellido);
                g_MayusculaMinuscula(apellido);
            break;
            case 3:
                salario = g_ValidarFlotante("Ingrese salario: ", "ERROR. Ingrese salario valido: ", salario, S_MIN, S_MAX);
            break;
            case 4:
                e_MostrarSectores();
                idSector = g_ValidarEntero("Ingrese id sector: ", "ERROR. Ingrese error valido: ", idSector, ID_S_MIN, ID_S_MAX);
            break;
            case 5:
                printf("Volviendo al menu principal...");
            break;
        }
    }while(opcion != 5);
}

/** \brief Calcula el promedio de los salarios
 *
 * \param sEmployee la lista
 * \param int el tamaño de la lista
 * \return float Retorna el promedio
 *
 */
float e_TotalPromedioSalarios(sEmployee list[], int tam)
{
    int i;
    float acumSalario;
    int cantSalarios;
    float salarioPromedio;

    cantSalarios = 0;
    acumSalario = 0;

    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
            acumSalario = acumSalario + list[i].salary;
            cantSalarios++;
        }
    }

    salarioPromedio = acumSalario / (float)cantSalarios;

    return salarioPromedio;
}

/** \brief Indica la cantidad que superan el salario promedio
 *
 * \param sEmployee la lista
 * \param int el tamaño de la lista
 * \return int Retorna la cantidad
 *
 */
int e_SuperanSalarioPromedio(float salarioPromedio, sEmployee list[], int tam)
{
    int i;
    int cantSuperanSalario;

    cantSuperanSalario = 0;

    for(i=0; i<tam; i++)
    {
        if(list[i].salary > salarioPromedio)
        {
            printf("| %d | %20s\t| %20s\t| %9.2f | %6d |\n", list[i].id, list[i].name, list[i].lastname, list[i].salary, list[i].idSector);
            cantSuperanSalario++;
        }
    }

    return cantSuperanSalario;
}

/** \brief Interfaz del menu
 *
 * \return int Retorna la opcion seleccionada
 *
 */
int e_MostrarMenuModificar()
{
    int opcion;

    printf("| - MODIFICACION - |\n");
    printf("|1| NOMBRE.\n");
    printf("|2| APELLIDO.\n");
    printf("|3| SALARIO.\n");
    printf("|4| SECTOR.\n");
    printf("|5| MENU PRINCIPAL.\n");
    opcion = g_PedirEntero("Que desea realizar? ");

    return opcion;
}

/** \brief Realiza un ordenamiento por id
 *
 * \param sEmployee la lista
 * \param int el tamaño de la lista
 * \return int Retorna la ultima posicion ordenada del array
 *
 */
int e_OrdenarPorId(sEmployee list[], int tam)
{
    int i;
    int j;
    int index;
    sEmployee auxEmployee;

    for(i=0; i<tam; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(list[i].id > list[j].id)
            {
                auxEmployee = list[i];
                list[i] = list[j];
                list[j] = auxEmployee;
                index = i;
            }
        }
    }
    e_MostrarEmployee(list, tam);

    return index;
}

/** \brief Ordena el array segun sector y
 *
 * \param sEmployee la lista
 * \param int el tamaño de la lista
 * \return
 *
 */
int e_ListarPorNombreSector(sEmployee list[], int tam)
{
    int i;
    int j;
    int index;
    sEmployee auxEmployee;

    index = -1;

    for(i=0; i<tam; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(list[i].idSector > list[j].idSector)
            {
                auxEmployee = list[i];
                list[i] = list[j];
                list[j] = auxEmployee;
            }
            if(list[i].idSector == list[j].idSector)
            {
                index = strcmp(list[i].name, list[j].name);
                if(index > 0)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
            }
        }
    }
    e_MostrarEmployee(list, tam);

    return index;
}

/** \brief Interfaz del menu de empleados
 *
 * \return void
 *
 */
void e_InterfazMostrarEmployee()
{
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+  ID  +          NOMBRE        +        APELLIDO       +  SALARIO  + SECTOR +\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

/** \brief Indica los sectores disponibles
 *
 * \return void
 *
 */
void e_MostrarSectores()
{
    printf("+ Los sectores  disponibles son: +\n");
    printf("+   |  1  |  2  |  3  |  4  |    +\n");
}

/** \brief Realiza la carga de cinco elementos en el array
 *
 * \param sEmployee la lista
 * \param int el tamaño de la lista
 * \return int Retorna la ultima posicion cargada del array
 *
 */
int e_HarcodeoEmployee(sEmployee list[], int tam)
{
    int i;
    int index;
    char nombres[TH][50]={"felipe simon","miguel angel","Jose pablo","santino","federico"};
    char apellidos[TH][50]={"rodriguez","siporsupuesto","rascaypica","ruiz","sobre"};
    float salarios[TH]={790.5, 1200, 1850.5, 650, 2300.4};
    int sectores[TH]={1, 2, 3, 2, 1};

    index = -1;
    for(i=0; i<tam; i++)
    {
        list[i].id = g_GenerarId(i, ID_E);
        strcpy(list[i].name, nombres[i]);
        g_MayusculaMinuscula(list[i].name);
        strcpy(list[i].lastname, apellidos[i]);
        g_MayusculaMinuscula(list[i].lastname);
        list[i].salary = salarios[i];
        list[i].idSector = sectores[i];
        list[i].isEmpty = OCUPADO;
        index = i;
    }

    return index;
}
