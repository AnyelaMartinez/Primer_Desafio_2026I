#ifndef FUNCIONES_TETRIS_H
#define FUNCIONES_TETRIS_H

unsigned int* crearTablero(int alto);
void imprimirTablero(unsigned int* tablero, int alto, int ancho);
void generarFichas(unsigned int ficha[], int &altoFicha, int &anchoFicha);
void mostrarFicha(unsigned int* tablero, int alto, int ancho,unsigned int ficha[], int altoFicha,int anchoFicha,int x, int y);
bool verificarColisiones(unsigned int* tablero,int alto,int ancho,unsigned int ficha[],int altoFicha, int anchoFicha, int &x, int y );
bool mover_Derecha(unsigned int* tablero,int alto,int ancho,unsigned int ficha[],int altoFicha, int anchoFicha, int &x, int y );
bool mover_Izquierda(unsigned int* tablero,int alto,int ancho,unsigned int ficha[],int altoFicha, int anchoFicha, int &x, int y);
bool bajar_Ficha(unsigned int* tablero,int alto,int ancho,unsigned int ficha[],int altoFicha, int anchoFicha, int x, int &y);
void rotar_Fichas(unsigned int* tablero,int alto,int ancho,unsigned int ficha[],int &altoFicha, int &anchoFicha, int &x, int y );
void eliminar_Filas(unsigned int* tablero, int alto, int ancho);

#endif // FUNCIONES_TETRIS_H
