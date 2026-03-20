#include "funciones_tetris.h"


bool verificarColisiones(unsigned int* tablero,int alto,int ancho,unsigned int ficha[],int altoFicha,int anchoFicha, int &x, int y)
{
    // bordes
    if(x < 0)
        return true;

    if(x + anchoFicha > ancho)
        return true;

    if(y + altoFicha > alto)
        return true;

    for(int i = 0; i < altoFicha; i++)
    {
        for(int j = 0; j < anchoFicha; j++)
        {
            if(ficha[i] & (1u << j))
            {
                int colTablero = x + j;

                int bitReal = ancho - 1 - colTablero;

                if(tablero[y + i] & (1u << bitReal))
                {
                    return true;
                }
            }
        }
    }

    return false;
}


void eliminar_Filas(unsigned int* tablero, int alto, int ancho)
{
    for(int i = alto - 1; i >= 0; i--)
    {
        bool llena = true;

        for(int j = 0; j < ancho; j++)
        {
            if(!(tablero[i] & (1u << j)))
            {
                llena = false;
                break;
            }
        }

        if(llena)
        {
            for(int k = i; k > 0; k--)
            {
                tablero[k] = tablero[k - 1];
            }

            tablero[0] = 0;

            i++;
        }
    }
}
