#include "funciones_tetris.h"


void rotar_Fichas() {
    //Rotar a la derecha o izquierda las fichas
};

bool mover_Derecha(unsigned int* tablero,int alto,int ancho,unsigned int ficha[],int altoFicha, int anchoFicha, int &x, int y ) {

    x++;
    if(verificarColisiones(tablero, alto, ancho, ficha, altoFicha, anchoFicha, x, y))
    {
        x--;
        return false;
    }
    return true;
};

bool mover_Izquierda(unsigned int* tablero,int alto,int ancho,unsigned int ficha[],int altoFicha, int anchoFicha, int &x, int y) {

    x--;
    if(verificarColisiones(tablero, alto, ancho, ficha, altoFicha, anchoFicha, x, y))
    {
        x++;
        return false;
    }
    return true;
};
