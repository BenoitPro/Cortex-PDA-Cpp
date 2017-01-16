/*
CUtilitaires.h
*/
#include "CAideMemoire.cpp"
#include "CCalculatrice.cpp"
#include "CBlockNote.cpp"

class CUtilitaires {

private : // Déclarer ici tous les classes a inclure dans les utilitaires
	CAideMemoire aideMemoire ;
	CCalculatrice calculatrice ;
	CBlockNote blockNote ;
public :
	void menu(void);
	void aide(void);
};