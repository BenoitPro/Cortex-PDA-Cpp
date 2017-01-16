/********************
	Exception.cpp  
*********************/

#include <iostream.h>
#include "Exception.h"


/** Constructeur **/
Exception :: Exception(int i,int r) { 
	_ind = i ; 
	_raison=r; 
}
	
int Exception :: getInd() { return _ind ; }

void Exception :: message() {
	switch(_raison) {
		case 1 : cout << "Aucun noeud n'est a la position : " << _ind <<endl; break;
		case 2 : cout << "La file est vide.";break;
	}
}
