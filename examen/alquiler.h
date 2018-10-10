#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED
#include "cliente.h"
#include "juego.h"


typedef struct
{
    int dia, mes , anio;

}eFecha;

typedef struct
{
    int id;
    int idJuego;
    int idCliente;
    eFecha feNac;

    int isEmpty;

}eAlquiler;

void initAlquiler(eAlquiler alquileres[],int tam);
void alquilerMenuPrincipal();
void alquilerFuncionPrincipal(eAlquiler alquileres[],int tamAlqui,eCliente clientes[],int tamCliente,eJuego juegos[],int tamJuego);
int siguienteID(eAlquiler alquileres[],int tam);
int buscarAlquilerLibre(eAlquiler alquileres[], int tam);
int buscarAlquiler(eAlquiler alquileres[], int tam, int id);
int clientesActivos(eCliente clientes[], int tamClientes);
int juegosActivos(eJuego juegos[], int tamJuegos);
void cargarDescripcion(eJuego juegos[], int tamJuegos, int idJuego, char cadena[]);
void cargarNombre(eCliente clientes[], int tamClientes, int idCliente, char cadena[]);
void abmAlquiler(eJuego juegos[], int tamJuegos, eCliente clientes[], int tamClientes, eAlquiler alquileres[], int tamAlquileres);

#endif // ALQUILER_H_INCLUDED
