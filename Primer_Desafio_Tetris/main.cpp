#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;
unsigned int* crearTablero(int alto);
void imprimirTablero(unsigned int* tablero, int alto, int ancho);

int main()
{
    int ancho, alto;

    cout<<"VAMOS A JUGAR TETRIS!"<<endl;
    cout<<"Intrucciones del juego: "<<endl;
    cout<<"1.Debes elegir las dimensiones del alto y ancho del tablero de tetris"<<endl;
    cout<<"2."<<endl;
    cout<<"RESTRICCIONES"<<endl;
    cout<<"El ancho debe ser un multiplo de 8, siendo 8 el numero minimo y 32 el numero maximo."<<endl;
    cout<<"El alto debe ser minimo 8, No hay un limite en altura, pero ten en cuenta que no tiene sentido jugar un tetris tan alto."<<endl;
    cout<<"Ancho:"<<endl;
    cin>>ancho;
    cout<<"Alto: "<<endl;
    cin>>alto;

    //Validación del ancho (antes de iniciar cualquier funcion)
    if(ancho < 8 || ancho > 32 || ancho % 8 != 0)
    {
        cout << "El ancho debe ser multiplo de 8, entre 8 y 32" << endl;
        return 0;
    }

    unsigned int* tablero = crearTablero(alto);
    imprimirTablero(tablero, alto, ancho);


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
            if(tablero[i] & (1 << j))
                cout << "#";
            else
                cout << ".";
        }

        cout << endl;
    }
}

void generarFichas() {
    unsigned int ficha[4]; //maximo de filas que usaría una ficha

    srand(time(0));
    int tipo = (rand() % 5) + 1;

    switch(tipo)
    {
    case 1: // I
        ficha[0] = 15;
        break;

    case 2: // O
        ficha[0] = 3;
        ficha[1] = 3;
        break;

    case 3: // T
        ficha[0] = 7;
        ficha[1] = 2;
        break;

    case 4: // L
        ficha[0] = 2;
        ficha[1] = 2;
        ficha[2] = 3;
        break;

    case 5: // Z
        ficha[0] = 6;
        ficha[1] = 3;
        break;
    }
};

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
