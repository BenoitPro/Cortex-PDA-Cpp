/***************************
		 CNote.cpp
Defini les champs d'une note
*****************************/

#include "CNote.h"
#include "string.h"

/* Constructeurs */

CNote :: CNote() { // constructeur par defaut 
	strcpy(_note,"");
}
CNote :: CNote(char * n) { // constructeur
	strcpy(_note,n);
}	
void CNote :: setNote(char * n) { strcpy(_note,n); }

char * CNote :: getNote(char * n) { strcpy(n,_note); return n; }


ostream& operator<< (ostream& o,CNote c) {
	cout << c._note<<endl;
	return o;
}