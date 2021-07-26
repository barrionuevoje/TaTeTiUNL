#ifndef JUGADORES_H
#define JUGADORES_H

#include <iostream>
#include "Fichas.h"


using namespace std;

class Jugadores {
public:
	Jugadores();
	void setNombre(string n);
	string getNombre();
	void setFichas(Fichas r);
	Fichas getFichas();
private:
	string nombre;
	Fichas fichas;
};

#endif

