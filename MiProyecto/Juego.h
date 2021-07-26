#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include "Tablero.h"
#include "Jugadores.h"

using namespace std;
class Juego {
public:
	Juego();
	
	void play();
	void setPlaying(bool p);
	bool getPlaying();
	void setInGame(bool g);
	bool getInGame();
	void setTurno(Jugadores p);
	Jugadores getTurno();
	void setTicTacToe(bool g);
	bool getTicTacToe();
	void setTableroCompleto(bool g);
	bool getTableroCompleto();
	
	
private:
	// Jugador al que pertenece el turno actual.
	Jugadores turno;
	
	// Muestra el texto del juego.
	void imprimirCabecera(Jugadores jugador1, Jugadores jugador2);
	void imprimirSeparador();
	void imprimirProxTurno();
	
	// Reinicia la partida o la termina.
	void newGame();
	
	// Indica de quien es el turno siguiente.
	void nextTurn(Jugadores jugador1, Jugadores jugador2);
	
	// Realiza el turno del juagdor.
	void realizarTurno(Tablero &t, Jugadores jugador);
	
	// Valida que la tecla presionada por el usuario sea valida.
	bool reconocerTecla(int tecla, Tablero t);
	
	
	// Se comprueba si estamos en la partida.
	bool playing = true;
	bool inGame = true;
	
	// Se corrobora que el jugador gano la partida
	bool ticTacToe = false;
	
	// Indica si se termino de completar el tablero
	bool tableroCompleto = false;
	
	// Convierte el char de la tecla del usuario.
	int teclaAEntero(int tecla);
	
	// Chequea si se logro hacer tateti
	void comprobarTateti(Tablero t);
	
	// Chequea si se completo el tablero con fichas
	void comprobarTableroCompleto(Tablero t);
	
	// Imprime el resultado final de la partida
	void mostrarResultadoFinal();
	
};

#endif

