#include <iostream>
#include "funciones_tetris.h"

using namespace std;



int main()
{
    srand(time(0));
    int ancho, alto;

    cout <<"VAMOS A JUGAR TETRIS!"<<endl;
    cout <<"Intrucciones del juego: "<<endl;
    cout << "1. Elige las dimensiones del tablero" << endl;
    cout << "2. Mover las fichas en el tablero con los siguientes comandos: " << endl;
    cout << "D = Derecha"<<endl;
    cout << "A = Izquierda"<<endl;
    cout << "S = Bajar"<<endl;
    cout << "Q = Rotar"<<endl;
    cout << "E = Salir"<<endl;
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

    bool jugando = true;

    while (jugando){
        unsigned int ficha[4];
        int altoFicha;
        int anchoFicha;

        generarFichas(ficha, altoFicha, anchoFicha);

        int x = (ancho-anchoFicha)/2;
        int y = 0;

        if (verificarColisiones(tablero, alto, ancho, ficha, altoFicha, anchoFicha, x, y))
        {
            mostrarFicha(tablero, alto, ancho, ficha, altoFicha, anchoFicha, x, y);
            cout << "GAME OVER" << endl;
            jugando = false;
            break;
        }

        bool fichaJugando = true;

        while(fichaJugando)
        {
            mostrarFicha(tablero, alto, ancho, ficha, altoFicha, anchoFicha, x, y);
            cout << "D = Derecha A = Izquierda S = Bajar Q = Rotar E = Salir"<<endl;

            char movimiento;
            cin >> movimiento;

            switch(movimiento)
            {
            case 'D': case 'd':
                mover_Derecha(tablero, alto, ancho, ficha, altoFicha, anchoFicha, x, y);
                break;
            case 'A': case 'a':
                mover_Izquierda(tablero, alto, ancho, ficha, altoFicha, anchoFicha, x, y);
                break;

            case 'Q': case 'q':
                rotar_Fichas(tablero, alto, ancho, ficha, altoFicha, anchoFicha, x, y);
                break;
            case 'S': case 's':
                if(!bajar_Ficha(tablero, alto, ancho, ficha, altoFicha, anchoFicha, x, y))
                {
                    eliminar_Filas(tablero, alto, ancho);
                    fichaJugando = false;
                }
                break;

            case 'E': case 'e':
                jugando = false;
                fichaJugando = false;
                break;

            default:
                cout << "Accion no reconocida" << endl;
                break;

            }

        }

    }

    delete[] tablero;
    return 0;
}







