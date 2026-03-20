#include <iostream>
#include "funciones_tetris.h"

using namespace std;



int main()
{
    srand(time(0));
    int ancho, alto;

    cout<<"VAMOS A JUGAR TETRIS!"<<endl;
    cout<<"Intrucciones del juego: "<<endl;
    cout << "1. Elige las dimensiones del tablero" << endl;
    cout << "RESTRICCIONES" << endl;
    cout << "Ancho: multiplo de 8, minimo 8, maximo 32." << endl;
    cout << "Alto: minimo 8." << endl;

    cout << "Ancho: ";
    cin >> ancho;
    cout << "Alto: ";
    cin >> alto;

    //Validación del ancho (antes de iniciar cualquier funcion)
    if(ancho < 8 || ancho > 32 || ancho % 8 != 0)
    {
        cout << "El ancho debe ser multiplo de 8, entre 8 y 32" << endl;
        return 0;
    }

    //Tambien se debe validar el alto minimo
    if(alto < 8)
    {
        cout << "El alto debe ser minimo 8"<<endl;
        return 0;
    }

    unsigned int* tablero = crearTablero(alto);

    unsigned int ficha[4];
    int altoFicha;
    int anchoFicha;


    generarFichas(ficha, altoFicha, anchoFicha);

    //Las fichas se deben mostrar centradas, entonces se calcula el centro

    int xInicial = (ancho-anchoFicha)/2;
    mostrarFicha(tablero, alto, ancho, ficha, altoFicha, anchoFicha, xInicial, 0);

    delete[] tablero;
    return 0;
}







