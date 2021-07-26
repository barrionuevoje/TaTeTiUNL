#include "Jugadores.h"

Jugadores::Jugadores() {
	
}

void Jugadores::setNombre(string n) {
	nombre = n;
}

string Jugadores::getNombre() {
	return nombre;
}

void Jugadores::setFichas(Fichas r) {
	fichas = r;
}

Fichas Jugadores::getFichas() {
	return fichas;
}
