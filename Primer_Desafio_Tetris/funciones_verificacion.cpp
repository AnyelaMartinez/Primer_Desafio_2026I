#include "funciones_tetris.h"


bool verificarColisiones(unsigned int* tablero,int alto,int ancho,unsigned int ficha[],int altoFicha, int anchoFicha, int &x, int y  ) {

    //con los bordes del tablero

    //borde derecho
    if(x < 0)
        return true;

    //borde izquierdo
    if (x + anchoFicha > ancho)
        return true;

    //Borde abajo
    if(y + altoFicha > alto)
        return true;

    //Colisión con otras fichas
    int desplazamiento1 = ancho - anchoFicha - x;

    for(int i = 0; i < altoFicha; i++)
    {
        unsigned int filaMovida = ficha[i] << desplazamiento1;
        if(filaMovida & tablero[y + i])
            return true;
    }

    return false;

}



void eliminar_Filas() {
    //Eliminar las filas que esten completas con 1
}
