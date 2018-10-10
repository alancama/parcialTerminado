#include "cliente.h"
#include <stdio.h>
#include <string.h>
#include "validacion.h"
#include <conio.h>
#include <stdlib.h>

int initcliente(eCliente clientes[], int tam)
{

    for(int i=0; i<tam; i++)
    {
        clientes[i].isEmpty=0;
        clientes[i].id=0;
    }

    return  0;
}

int altacliente(eCliente clientes[],int tam)
{

    eCliente aux;

    int index=obtenerEspacioLibre(clientes,tam);

    if(index!=-1)
    {
        aux.id=siguienteIDCliente(clientes,tam);

        do
        {
            printf("\nIngrese nombre:");
            fflush(stdin);
            gets(aux.nombre);
        }
        while(validarNombre(aux.nombre)==0);

        do
        {
            printf("\nIngrese Apellido:");
            fflush(stdin);
            gets(aux.apellido);
        }
        while(validarNombre(aux.apellido)==0);

        do
        {
            printf("\nIngrese sexo:");
            fflush(stdin);
            scanf("%c",&aux.sexo);
        }
        while(validarNombre(&aux.sexo)==0);


        do
        {
            printf("\nIngrese domicilio:");
            fflush(stdin);
            gets(aux.domicilio);
        }
        while(validarNombre(aux.domicilio)==0);


        //aux.idSector=elegirSector(sectores,5);

        aux.isEmpty = 1;

        clientes[index] = aux;

    }
    else
    {
        printf("ERROR NO HAY LUGAR\n ");
    }

    mostrarClientes(clientes,tam);
    system("pause");
}


int obtenerEspacioLibre(eCliente clientes[], int tam)
{
    int i;
    int retorno = -1;

    for(i=0; i<tam; i++)
    {
        if(clientes[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int menu()
{
    printf("[1] INGRESAR AL MENU DE CLIENTES\n");
    printf("[2] INGRESAR AL MENU DE JUEGO\n");
    printf("[3] AGREGAR UN ALQUILER\n");
    printf("[4] LISTAR\n\n");
    printf("[5] SALIR\n");
}
void menuCliente()
{

    printf("\n1-ALTA\n");
    printf("2-MODIFICAR\n");
    printf("3-BAJA\n");
    printf("4-INFORMAR\n");
    printf("5-Salir\n");

}

int buscarcliente(eCliente clientes [], int tam, int id )
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {

        if( clientes[i].id == id && clientes[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarCliente(eCliente clientes)
{

    printf("%d %s %s %c %s \n\n", clientes.id, clientes.nombre, clientes.apellido,clientes.sexo,clientes.domicilio);
}


void mostrarClientes(eCliente clientes[], int tam)
{
    for(int i=0; i< tam; i++)
    {
        if( clientes[i].isEmpty == 1)
        {
            mostrarCliente(clientes[i]);
        }
    }
}

int siguienteIDCliente(eCliente list[],int tam)
{
    int retorno = 0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty == 1)
        {
            if(list[i].id>retorno)
            {
                retorno=list[i].id;
            }

        }
    }

    return retorno+1;
}

void modificarCliente(eCliente clientes [],int tam)
{
    int id;
    int indice;
    int opcion;
    char seguir='s';
    char confirmacion;

    char apellidoAux[51];
    char nombreAux[51];
    char sexoAux;
    char direccionAux[51];

    mostrarClientes(clientes,tam);
    printf("Ingrese id del cliente a modificar:");
    scanf("%d",&id);

    indice=buscarcliente(clientes,tam,id);
    if( indice == -1)
    {
        printf("No hay ningun cliente con el id %d\n",id);
    }
    else
    {

        mostrarCliente(clientes[indice]);

        do
        {
            printf("***Que Desea Modificar?***");

            printf("\n 1.Nombre");
            printf("\n 2.Apellido");
            printf("\n 3.sexo");
            printf("\n 4.domicilio");
            printf("\n 5.salir\n ");

            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                printf("ingrese Nuevo Nombre:");
                fflush(stdin);
                gets(clientes[indice].nombre);

                confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
                if(confirmacion == 'n')
                {
                    printf("Se cancelo la modificacion del nombre.\n\n");
                }
                else
                {
                    strcpy(clientes[indice].nombre,nombreAux);
                    printf("Se modifico el nombre con exito.\n\n");
                }
                break;
            case 2:

                printf("Ingrese Nuevo apellido:");
                fflush(stdin);
                gets(clientes[indice].apellido);

                confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
                if(confirmacion == 'n')
                {
                    printf("Se cancelo la modificacion del apellido.\n\n");
                }
                else
                {
                    strcpy(clientes[indice].apellido, apellidoAux);
                    printf("Se modifico el apellido con exito.\n\n");
                }
                break;

            case 3:


                printf("\nIngrese Nuevo sexo:");
                fflush(stdin);
                scanf("%c",&clientes[indice].sexo);

                confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');

                if(confirmacion == 'n')
                {
                    printf("Se cancelo la modificacion del sexo.\n\n");
                }
                else
                {
                    clientes[indice].sexo = sexoAux;
                    printf("Se modifico el sexo con exito.\n\n");
                }

                break;

            case 4:


                printf("\ningrese nuevo domicilio:");
                fflush(stdin);
                gets(clientes[indice].domicilio);
                confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');

                if(confirmacion == 'n')
                {
                    printf("Se cancelo la modificacion del nombre.\n\n");
                }
                else
                {
                    strcpy(clientes[indice].domicilio, direccionAux);
                    printf("Se modifico la direccion con exito.\n\n");
                }
                break;
            //}
            //while(validarNombre(clientes[indice].domicilio)==0);
            case 5:
                seguir='n';
                break;
            }

        }
        while(seguir=='s');
        system("cls");
        mostrarClientes(clientes,tam);

    }

}


int bajaCliente(eCliente clientes[],int tam)
{
    int indice;
    int id;

    mostrarClientes(clientes,tam);
    printf("Ingrese id del cliente a Dar de baja:");
    scanf("%d",&id);

    indice=buscarcliente(clientes,tam,id);

    if(indice==-1)
    {
        printf("Error id no Encontrado\n");
    }
    else
    {
        clientes[indice].isEmpty=0;
        printf("\n cliente Borrado\n");
    }
}

/*void ordenarEmpleados(eCliente clientes[],int tam,eJuego sectores[],int tamSectores)
{
    eCliente aux;
    char descripcionI[20];
    char descripcionJ[20];

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam;j++)
        {
            cargarDescripcion(sectores,tamSectores,clientes[i].idSector,descripcionI);
            cargarDescripcion(sectores,tamSectores,clientes[j].idSector,descripcionJ);

            if(strcmp(descripcionI,descripcionJ)>0)
            {
                aux=clientes[i];
                clientes[i]=clientes[j];
                clientes[j]=aux;
            }
            else if(strcmp(descripcionI,descripcionJ)==0 && strcmp(clientes[i].apellido,clientes[j].apellido)>0)
            {
                aux=clientes[i];
                clientes[i]=clientes[j];
                clientes[j]=aux;
            }

        }
    }
}*/

void clienteFuncionPrincipal(eCliente clientes [], int tam)
{
    int exit = 0;
    char option = 's';
    int check;
    int contadorclientes=0;
    do
    {
        system("cls");
        menuCliente();

        printf("\nELIJE UNA OPCION: ");
        option = getch();

        switch(option)
        {
        case '1': //AGREGAR EMPLEADOS//
            check = altacliente(clientes, tam);
            if(check==-1)
            {
                printf("ERROR. No se pudo dar de alta o no hay mas espacio libre\n");
                system("pause");
            }
            else
            {
                contadorclientes++;
            }
            break;
        case '2': //MODIFICAR EMPLEADOS//
            if(contadorclientes>0)
            {
                modificarCliente(clientes,tam);
            }
            else
            {
                printf("Ingrese un cliente primero\n");
                system("pause");
            }
            break;
        case '3':   //ELIMINAR EMPLEADOS//
            if(contadorclientes>0)
            {
                check =bajaCliente(clientes,tam);
                if(check==0)
                {
                    contadorclientes--;
                }
            }
            else
            {
                printf("Ingrese un cliente primero\n");
                system("pause");
            }
            break;
        case '4':   //LISTAR//
            if(contadorclientes>0)
            {
                listarClientes(clientes,tam);
                system("pause");
            }
            else
            {
                printf("Ingrese un cliente primero\n");
                system("pause");
            }
            break;
        case '5':   //SALIR//
            exit = 1;
            break;
        default:
            printf("\nIngreso una opcion no valida\n");
            system("pause");
            break;
        }

    }
    while(exit == 0);

}

void listarClientes(eCliente clientes[], int tamClientes)
{
    eCliente aux;
    system("cls");
    printf("  *** Lista de Clientes ***\n");
    printf("  Ordenados por Apellido (ascendente) y Nombre (descendente).\n\n");
    for(int i=0; i<tamClientes-1; i++)
    {
        for(int j=i+1; j<tamClientes; j++)
        {
            if(strcmp(clientes[i].apellido, clientes[j].apellido) > 0)
            {
                aux = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = aux;
            }
            else if((strcmp(clientes[i].apellido, clientes[j].apellido) == 0) && strcmp(clientes[i].nombre, clientes[j].nombre) < 0)
            {
                aux = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = aux;

            }
        }
    }
    mostrarClientes(clientes, tamClientes);
    printf("\n");
}

void hardcodeoClientes(eCliente clientes[])
{
    clientes[0].id = 1;
    strcpy(clientes[0].apellido, "Mefisto");
    strcpy(clientes[0].nombre, "Magnus");
    clientes[0].sexo = 'm';
    strcpy(clientes[0].domicilio, "Su casa 1234");
    clientes[0].isEmpty = 1;

    clientes[1].id = 2;
    strcpy(clientes[1].apellido, "Perez");
    strcpy(clientes[1].nombre, "Juan");
    clientes[1].sexo = 'f';
    strcpy(clientes[1].domicilio, "Su casa 4321");
    clientes[1].isEmpty = 1;

    clientes[2].id = 3;
    strcpy(clientes[2].apellido, "Fernandez");
    strcpy(clientes[2].nombre, "Facundo");
    clientes[2].sexo = 'm';
    strcpy(clientes[2].domicilio, "Alvarez 111");
    clientes[2].isEmpty = 1;

    clientes[3].id = 4;
    strcpy(clientes[3].apellido, "Liniers");
    strcpy(clientes[3].nombre, "Ricardo");
    clientes[3].sexo = 'm';
    strcpy(clientes[3].domicilio, "ASDA 654");
    clientes[3].isEmpty = 1;
}

