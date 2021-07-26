#include "Tablero.h"

Tablero::Tablero() {
	
}

void Tablero::mostrar(){
	cout<<" "<<" 1 "<<" 2 "<<" 3 "<<endl;
	
	cout << "   " << "=============" << endl;
	
	for(int i=0; i<3; i++) {
		cout << " " << i+1 << " | ";
		
		for(int j=0; j<3; j++) {
			cout << board[i][j].getFigura() << " | ";
		}
		
		cout << endl << "   -------------" << endl;
	}
	
	cout << endl;
}

void Tablero::setFiguraEn(int x, int y, Fichas r){
	if(!hayFicha(x, y)) {
		board[x][y] = r;
	}
}

bool Tablero::hayFicha(int x, int y){
	if(board[x][y].getFigura() == ' ') {
		return false;
	}
	return true;
}

Fichas Tablero::getFiguritas(int x, int y){
	return board[x][y];
}
