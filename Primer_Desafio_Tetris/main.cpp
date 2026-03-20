#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

unsigned int* crearTablero(int alto);
void imprimirTablero(unsigned int* tablero, int alto, int ancho);
void generarFichas(unsigned int ficha[], int &altoFicha, int &anchoFicha);
void mostrarFicha(unsigned int* tablero, int alto, int ancho,
                  unsigned int ficha[], int altoFicha,int anchoFicha,
                  int x, int y);

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


unsigned int* crearTablero(int alto){

    unsigned int* tablero = new unsigned int[alto];

    for(int i = 0; i < alto; i++)
    {
        tablero[i] = 0;
    }

    return tablero;
};

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
                cout << "#";
            }
            else
            {

                if(i >= y && i < y + altoFicha)
                {
                    int filaFicha = i - y;

                    unsigned int filaMovida = ficha[filaFicha] << desplazamiento;

                    if(filaMovida & (1u << j))
                    {
                        cout << "@";
                    }
                    else
                    {
                        cout << ".";
                    }
                }
                else
                {
                    cout << ".";
                }
            }
        }
        cout << endl;
    }
}

void rotar_Fichas() {
    //Rotar a la derecha o izquierda las fichas
};

void mover_Derecha() {
    //Mover bits a la derecha (aun no sé si en la misma función mover a izq y a der o hacerlas separadas)
};

void mover_Izquierda() {
    //Mover bits a la izquierda
};

void verificar_Colisione() {
    //Verificar si la ficha se choca con algo para parar o seguir bajando
};

void eliminar_Filas() {
    //Eliminar las filas que esten completas con 1
};
