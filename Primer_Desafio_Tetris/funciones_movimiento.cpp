#include "funciones_tetris.h"


void rotar_Fichas(unsigned int* tablero,int alto,int ancho,unsigned int ficha[],int &altoFicha,int &anchoFicha, int &x, int y)
{
    unsigned int nueva[4] = {0,0,0,0};

    int nuevoAlto = anchoFicha;
    int nuevoAncho = altoFicha;

    for(int i = 0; i < altoFicha; i++)
    {
        for(int j = 0; j < anchoFicha; j++)
        {
            if(ficha[i] & (1u << j))
            {
                int nuevaFila = j;
                int nuevaColumna = altoFicha - 1 - i;

                nueva[nuevaFila] |= (1u << nuevaColumna);
            }
        }
    }

    int xOriginal = x;

    if(x + nuevoAncho > ancho)
        x = ancho - nuevoAncho;

    if(verificarColisiones(tablero, alto, ancho, nueva, nuevoAlto, nuevoAncho, x, y))
    {
        x = xOriginal;
        return;
    }

    for(int i = 0; i < nuevoAlto; i++)
    {
        ficha[i] = nueva[i];
    }

    altoFicha = nuevoAlto;
    anchoFicha = nuevoAncho;
}
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

bool bajar_Ficha(unsigned int* tablero,int alto,int ancho,unsigned int ficha[],int altoFicha, int anchoFicha, int x, int &y) {

    y++;
    if(verificarColisiones(tablero, alto, ancho, ficha, altoFicha, anchoFicha, x, y))
    {
        y--;

        int desplazamiento = ancho - anchoFicha - x;
        for(int i = 0; i < altoFicha; i++)
            tablero[y + i] |= (ficha[i] << desplazamiento);
        return false;
    }

    return true;

}
