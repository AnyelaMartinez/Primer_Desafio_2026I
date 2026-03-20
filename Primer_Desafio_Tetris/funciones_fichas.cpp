#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funciones_tetris.h"

using namespace std;

void generarFichas(unsigned int ficha[], int &altoFicha, int &anchoFicha)
{
    int tipo = rand() % 5 + 1;

    switch(tipo)
    {
    case 1: // I
        ficha[0] = 15;
        altoFicha = 1;
        anchoFicha = 4;
        break;

    case 2: // O
        ficha[0] = 3;
        ficha[1] = 3;
        altoFicha = 2;
        anchoFicha = 2;
        break;

    case 3: // T
        ficha[0] = 7;
        ficha[1] = 2;
        altoFicha = 2;
        anchoFicha = 3;
        break;

    case 4: // L
        ficha[0] = 2;
        ficha[1] = 2;
        ficha[2] = 3;
        altoFicha = 3;
        anchoFicha = 2;
        break;

    case 5: // Z
        ficha[0] = 6;
        ficha[1] = 3;
        altoFicha = 2;
        anchoFicha = 3;
        break;
    }
}

void mostrarFicha(unsigned int* tablero, int alto, int ancho,unsigned int ficha[], int altoFicha, int anchoFicha, int x, int y)
{
    int desplazamiento = ancho - anchoFicha - x;

    for(int i = 0; i < alto; i++)
    {
        for(int j = ancho - 1; j >= 0; j--)
        {
            if(tablero[i] & (1u << j))
            {
                cout << " # ";
            }
            else
            {

                if(i >= y && i < y + altoFicha)
                {
                    int filaFicha = i - y;

                    unsigned int filaMovida = ficha[filaFicha] << desplazamiento;

                    if(filaMovida & (1u << j))
                    {
                        cout << " @ ";
                    }
                    else
                    {
                        cout << " . ";
                    }
                }
                else
                {
                    cout << " . ";
                }
            }
        }
        cout << endl;
    }
}
