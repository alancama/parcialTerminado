#include "juego.h"
#include <stdio.h>
#include "validacion.h"
#include <stdlib.h>
#include <string.h>
#include <conio.h>



int initJuegos( eJuego juegos [],int tam)
{
    int i;
    for( i=0; i < tam; i++)
    {
        juegos[i].isEmpty = 0;
        juegos[i].id=0;
    }
    return 0;
}



int buscarLibre( eJuego juegos [], int tam)
{
    int indice = -1,i;

    for( i=0; i< tam; i++)
    {

        if( juegos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int altaJuegos(eJuego juegos [], int tam)
{
    eJuego auxJuego;
    int indice;
    char validaImporte[10];

    indice = buscarLibre(juegos, tam);

    if(indice != -1)
    {

         auxJuego.id=siguienteIDJuego(juegos,tam);
        do
            {
            printf("\nIngrese juego: ");
            fflush(stdin);
            gets(auxJuego.descripcion);
            }while(validarNombre(auxJuego.descripcion)==0);

            do
            {
            printf("\nIngrese el importe del juego: ");
            scanf("%s",&validaImporte);
            }while(validarNumero(validaImporte)==0);

            auxJuego.importe=atoi(validaImporte);

            //nuevoEmpleado.idSector=elegirSector(sectores,5);

            auxJuego.isEmpty = 1;

            juegos[indice] = auxJuego;
    }else
    {
        printf("NO HAY LUGAR");
    }
}

int siguienteIDJuego(eJuego juegos [],int tam)
{
    int retorno = 0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(juegos[i].isEmpty == 1)
        {
            if(juegos[i].id>retorno)
            {
                retorno=juegos[i].id;
            }

        }
    }

    return retorno+1;
}

int modificarJuego(eJuego juegos[],int tam)
{
    int id;
    int indice;
    int opcion;
    char seguir='s';

    mostrarJuegos(juegos,tam);

    printf("Ingrese id del juego a modificar:");
    scanf("%d",&id);

    indice=buscarJuego(juegos,tam,id);
    if( indice == -1)
    {
        printf("No hay ningun juego con el id %d\n",id);
    }
    else
    {

        mostrarJuego(juegos[indice]);

        do
        {
            printf("***Que Desea Modificar?***");

            printf("\n 1.Nombre del juego");
            printf("\n 2.Importe");
            printf("\n 3.salir\n ");

            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:

                printf("\nIngrese nuevo Nombre:");
                fflush(stdin);
                gets(juegos[indice].descripcion);
                system("pause");

                break;

            case 2:
                printf("\nIngrese Nuevo importe:");
                scanf("%f",&juegos[indice].importe);
                system("pause");
                break;

            case 3:
                seguir='n';
                break;

            }
        }
        while(seguir=='s');
        system("cls");
        mostrarJuegos(juegos,tam);
    }
}
void mostrarJuego(eJuego juegos/*eJuego sectores[],int tamSector*/)
{
    //char descripcion[30];
    //cargarDescripcion(sectores,tamSector,clientes.idSector,descripcion);
    printf("%d %s %.2f \n\n", juegos.id, juegos.descripcion, juegos.importe);
}

void mostrarJuegos(eJuego juegos[], int tam)
{
    for(int i=0; i< tam; i++)
    {
        if( juegos[i].isEmpty == 1)
        {
            mostrarJuego(juegos[i]);
        }
    }
}

int buscarJuego(eJuego juegos [], int tam, int id )
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {

        if( juegos[i].id == id && juegos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int bajaJuego(eJuego juegos[],int tam)
{
    int indice;
    int id;

    mostrarJuegos(juegos,tam);
    printf("Ingrese id del cliente a Dar de baja:");
    scanf("%d",&id);

    indice=buscarJuego(juegos,tam,id);

    if(indice==-1)
    {
        printf("Error id no Encontrado\n");
    }
    else
    {
        juegos[indice].isEmpty=0;
        printf("\n Juego Borrado\n");
    }
}

void menuJuego()
{
    printf("1-AGREGAR JUEGO\n");
    printf("2-MODIFICAR JUEGO\n");
    printf("3-BAJA DEL JUEGO\n");
    printf("4-LISTAR\n");
    printf("5-SALIR\n");
}

void funcionPrincipalJuego(eJuego juegos[], int tam)
{
    int exit = 0;
    char option = 's';
    int check;
    int contadorJuegos=0;
    do
    {
        system("cls");
        menuJuego();

        printf("\nINGRESE UN OPCION: ");
        option = getch();

        switch(option)
        {
        case '1': //AGREGAR MENU//
                check = altaJuegos(juegos,tam);
                if(check==-1)
                {
                    printf("ERROR. No se pudo dar de alta o no hay mas espacio libre\n");
                    system("pause");
                }else
                {
                    contadorJuegos++;
                }
            break;
        case '2': //MODIFICAR MENU//
            if(contadorJuegos>0)
            {
                modificarJuego(juegos,tam);
            }else
            {
                printf("Ingrese un juego primero\n");
                system("pause");
            }
            break;
        case '3':   //ELIMINAR MENU//
            if(contadorJuegos>0)
            {
                check = bajaJuego(juegos, tam);
                if(check==0)
                {
                    contadorJuegos--;
                }
            }else
            {
                printf("Ingrese un juego primero\n");
                system("pause");
            }
            break;
        case '4':   //LISTAR//
            if(contadorJuegos>0)
            {
                listarJuegos(juegos,tam);
                system("pause");
            }else
            {
                printf("Ingrese un juego primero\n");
                system("pause");
            }
            break;
        case '5':   //SALIR//
            exit = 1;
            break;
        default:
            printf("Incorrect Input\n");
            system("pause");
        break;
        }

    }
    while(exit == 0);

}

void listarJuegos(eJuego juegos[], int tamJuegos)
{
    system("cls");
    printf("  *** Lista de Juegos ***\n");
    printf("  Ordenados por Importe (descendente) y descripcion (ascendente).\n\n");
    eJuego aux;
    for(int i=0; i<tamJuegos-1; i++)
    {
        for(int j=i+1; j<tamJuegos; j++)
        {
            if(juegos[i].importe < juegos[j].importe)
            {
                aux = juegos[i];
                juegos[i] = juegos[j];
                juegos[j] = aux;
            }
            else if((juegos[i].importe == juegos[j].importe) && strcmp(juegos[i].descripcion, juegos[j].descripcion) > 0)
            {
                aux = juegos[i];
                juegos[i] = juegos[j];
                juegos[j] = aux;
            }
        }
    }
    mostrarJuegos(juegos, tamJuegos);
    printf("\n");
}

void hardcodeoJuegos(eJuego juegos[])
{

    juegos[0].id = 1;
    strcpy(juegos[0].descripcion, "Juego 1 test");
    juegos[0].importe = 455.89;
    juegos[0].isEmpty = 1;

    juegos[1].id = 2;
    strcpy(juegos[1].descripcion, "Juego 2 test");
    juegos[1].importe = 1234.12;
    juegos[1].isEmpty = 1;

    juegos[2].id = 3;
    strcpy(juegos[2].descripcion, "Juego 3 test");
    juegos[2].importe = 5.55;
    juegos[2].isEmpty = 1;

    juegos[3].id = 4;
    strcpy(juegos[3].descripcion, "Juego 4 test");
    juegos[3].importe = 654.98;
    juegos[3].isEmpty = 1;
}
