#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[51];
    float importe;
    int isEmpty;

} eJuego;

int buscarLibre(eJuego juegos [], int tam);
int altaJuegos(eJuego juegos [], int tam);
int siguienteIDJuego(eJuego juegos [],int tam);
int initJuegos(eJuego juegos [],int tam);
void mostrarJuego(eJuego juegos/*eJuego sectores[],int tamSector*/);
int modificarJuego(eJuego juegos[],int tam);
void mostrarJuegos(eJuego juegos[], int tam);
int buscarJuego(eJuego juegos [], int tam, int id );
int bajaJuego(eJuego juegos[],int tam);
void menuJuego();
void funcionPrincipalJuego(eJuego juegos[], int tam);
void hardcodeoJuegos(eJuego juegos[]);

#endif // JUEGO_H_INCLUDED
