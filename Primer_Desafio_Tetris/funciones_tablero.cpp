#include <iostream>
#include "funciones_tetris.h"

using namespace std;

unsigned int* crearTablero(int alto){

    unsigned int* tablero = new unsigned int[alto];

    for(int i = 0; i < alto; i++)
    {
        tablero[i] = 0;
    }

    return tablero;
}

void imprimirTablero(unsigned int* tablero, int alto, int ancho)
{
    for(int i = 0; i < alto; i++)
    {
        for(int j = ancho - 1; j >= 0; j--)
        {
            if(tablero[i] & (1u << j))
                cout << "#";
            else
                cout << ".";
        }

        cout << endl;
    }
}
