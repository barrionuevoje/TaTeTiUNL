#include "Juego.h"
#include <conio2.h>
Juego::Juego() {
	
}

//Instancias de teclas
int Juego::teclaAEntero(int tecla) {
	switch(tecla) {
	case '1':
		tecla = 1;
		break;
	case '2':
		tecla = 2;
		break;
	case '3':
		tecla = 3;
		break;
	case '4':
		tecla = 4;
		break;
	case '5':
		tecla = 5;
		break;
	case '6':
		tecla = 6;
		break;
	case '7':
		tecla = 7;
		break;
	case '8':
		tecla = 8;
		break;
	case '9':
		tecla = 9;
		break;
	default:
		tecla = 0;
		break;
	}
	
	return tecla;
}


bool Juego::reconocerTecla(int tecla, Tablero t) {
	if(!tecla) {
		return false;
	}
	
	tecla = tecla - 1;
	if(t.hayFicha(t.teclaUbicacion[tecla][0], t.teclaUbicacion[tecla][1])) {
		return false;
	}
	
	return true;
}


void Juego::imprimirCabecera(Jugadores jugador1, Jugadores jugador2){
	
	cout<<"Tateti"<<endl;
	cout<<jugador1.getNombre()<<" "<<jugador1.getFichas().getFigura()<<endl;
	cout<<jugador2.getNombre()<<" "<<jugador2.getFichas().getFigura()<<endl;
	
}

//Sepador
void Juego::imprimirSeparador() {
	cout << "============================" << endl;
}

//Muestra en pantalla el proximo turno
void Juego::imprimirProxTurno() {
	cout << "Turno " << getTurno().getNombre() << " (" << getTurno().getFichas().getFigura() << ")" << endl << endl; 
}

//Set para el jugador.
void Juego::setPlaying(bool p) {
	playing = p;
}

bool Juego::getPlaying() {
	return playing;
}

void Juego::setInGame(bool g) {
	inGame = g;
}

bool Juego::getInGame() {
	return inGame;
}


void Juego::setTurno(Jugadores p) {
	turno = p;
}

Jugadores Juego::getTurno() {
	return turno;
}

void Juego::setTicTacToe(bool g) {
	ticTacToe= g;
}

bool Juego::getTicTacToe() {
	return ticTacToe;
}

void Juego::setTableroCompleto(bool g) {
	tableroCompleto = g;
}

bool Juego::getTableroCompleto() {
	return tableroCompleto;
}


void Juego::comprobarTateti(Tablero t) {
	char fichas[9];
	int k = 0;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			fichas[k] = t.getFiguritas(i, j).getFigura();
			k++;
		}
	}
	
	if(fichas[0] == fichas[1] && fichas[1] == fichas[2] && fichas[0] != ' ') {
		setTicTacToe(true);
	} else if(fichas[3] == fichas[4] && fichas[4] == fichas[5] && fichas[3] != ' ') 
	{
		setTicTacToe(true);
	} else if(fichas[6] == fichas[7] && fichas[7] == fichas[8] && fichas[6] != ' ')
	{
		setTicTacToe(true);
	} else if(fichas[0] == fichas[3] && fichas[3] == fichas[6] && fichas[0] != ' ')
	{
		setTicTacToe(true);
	} else if(fichas[1] == fichas[4] && fichas[4] == fichas[7] && fichas[1] != ' ') 
	{
		setTicTacToe(true);
	} else if(fichas[2] == fichas[5] && fichas[5] == fichas[8] && fichas[2] != ' ') 
	{
		setTicTacToe(true);
	} else if(fichas[0] == fichas[4] && fichas[4] == fichas[8] && fichas[0] != ' ')
	{
		setTicTacToe(true);
	} else if(fichas[2] == fichas[4] && fichas[4] == fichas[6] && fichas[2] != ' ')
	{
		setTicTacToe(true);
	}
}

//Instancia para Jugar un nuevo juego. 
void Juego::newGame(){
	cout << endl << "¿Desea jugar otra partida? (S = si - N = no)" << endl << endl;
	int opcion;
	do {
		opcion = getch();
	} while(opcion != 'S' && opcion != 's' && opcion != 'N' && opcion != 'n');
	
	if(opcion == 'N' || opcion == 'n') {
		// Terminamos partida
		setPlaying(false);
	} else {
		// Reiniciamos las variables necesarias
		setInGame(true);
		setTicTacToe(false);
		setTableroCompleto(false);
	}
}

//Pasa al proximo turno del jugador.
void Juego::nextTurn(Jugadores jugador1, Jugadores jugador2){
	if(getTurno().getNombre() == jugador1.getNombre()){
		setTurno(jugador2);
	}else{
		setTurno(jugador1);
	}
}

//Realiza el turno del actual jugador.
void Juego::realizarTurno(Tablero &t, Jugadores jugador) {
	int l = 1;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(!t.hayFicha(i, j)) {
				cout << t.positionBoard[i][j] << " presiona " << l << endl;
			}
			l++;
		}
	}
	cout << endl << "Elige una opción: " << endl << endl;
	int opcion;
	do {
		opcion = getch();
		opcion = teclaAEntero(opcion);
	} while(!reconocerTecla(opcion, t));
	
	t.setFiguraEn(t.teclaUbicacion[opcion-1][0], t.teclaUbicacion[opcion-1][1], jugador.getFichas());
}





//Comprueba si el tablero esta completo
void Juego::comprobarTableroCompleto(Tablero t) {
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(t.getFiguritas(i, j).getFigura() == ' ') {
				return;
			}
		}
	}
	
	setTableroCompleto(true);
}

//Muestra que jugador gano o si se empato el game.

void Juego::mostrarResultadoFinal() {
	if(getTicTacToe()) {
		cout << "Ganador: " << getTurno().getNombre() << endl;
	} else {
		cout << "Empate!" << endl;
	}
}

//Se realiza el juego.
void Juego::play(){
	Fichas R1;
	R1.setFigura('O');
	Jugadores P1;
	P1.setNombre("Player 1");
	P1.setFichas(R1);
	
	Fichas R2;
	R2.setFigura('X');
	Jugadores P2;
	P2.setNombre("Player 2");
	P2.setFichas(R2);
	
	imprimirCabecera(P1, P2);
	
	while(getPlaying()){
		Tablero T;
		setTurno(P1);
		
		while(getInGame()){
			imprimirProxTurno();
			T.mostrar();
			realizarTurno(T, getTurno());
			T.mostrar();
			comprobarTateti(T);
			comprobarTableroCompleto(T);
			
			if(getTicTacToe() || getTableroCompleto()){
				imprimirSeparador();
				mostrarResultadoFinal();
				imprimirSeparador();
				setInGame(false);
			}else{
				nextTurn(P1, P2);
			}
		}
		newGame();
	}
	cout<<"Gracias por jugar"<<endl;
}

