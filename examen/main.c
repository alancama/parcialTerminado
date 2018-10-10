#include <stdio.h>
#include <stdlib.h>
#include "alquiler.h"
#include "cliente.h"
#include "conio.h"
#include "string.h"
#define TAMCLIENTE 3
#define TAMJUEGO 3
#define TAMALQUILER 3
#include "juego.h"



int main()
{
    eJuego juego[TAMJUEGO];
    eCliente cliente[TAMCLIENTE];
    eAlquiler alquileres[TAMALQUILER];

    int exit = 0;
    char option = 'x';

    hardcodeoJuegos(juego);
    hardcodeoClientes(cliente);

    initJuegos(juego, TAMJUEGO);
    initcliente(cliente, TAMCLIENTE);
    iniciarEstadosAlquileres(alquileres,TAMALQUILER);

    do
    {
        menu();

        printf("\nELIJE UNA OPCION: ");
        scanf("%d",&option);

        switch(option)
        {

        case 1:
            clienteFuncionPrincipal(cliente,TAMCLIENTE);
            system("pause");
            break;
        case 2:
            funcionPrincipalJuego(juego,TAMJUEGO);
            system("pause");
            break;
        case 3:
            abmAlquiler(juego,TAMJUEGO,cliente,TAMCLIENTE,alquileres,TAMALQUILER);
            system("pause");
            break;
        case 4:
            exit = 1;
            break;
        default:
            printf("Incorrect Input\n");
            system("pause");
            break;

        }

    }
    while(exit == 0);
    return 0;
}
