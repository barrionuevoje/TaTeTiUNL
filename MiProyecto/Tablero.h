#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include "Fichas.h"

using namespace std;

class Tablero {
public:
	
	
	string positionBoard[3][3] = {{"1.1", "1.2", "1.3"}, {"2.1", "2.2", "2.3"}, {"3.1", "3.2", "3.3"}};
	int teclaUbicacion[9][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
	
	Tablero();
	void mostrar();
	void setFiguraEn(int x, int y, Fichas r);
	bool hayFicha(int x, int y);
	Fichas getFiguritas(int x, int y);
	
private:
	Fichas board[3][3];
};

#endif

