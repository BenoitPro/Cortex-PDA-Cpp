/***********************************
		CPenseBete.cpp
Definit les champs d'un pense-bete
***********************************/

#include "CPenseBete.h"
#include <iostream.h>
#include <string.h>

/* Constructeurs */
CPenseBete :: CPenseBete(void) {
	strcpy(_titre,"");
	strcpy(_description,"");
	strcpy(_type,"");
}

CPenseBete :: CPenseBete(char * titre) {
	strcpy(_titre,titre);
	strcpy(_description,"");
	strcpy(_type,"");
}

/* Méthodes */

// Getters
char * CPenseBete :: getTitre(char * v) {
	strcpy(v,_titre); return v;
}

char * CPenseBete :: getDescription(char * v) {
	strcpy(v,_description); return v;
}

char * CPenseBete :: getType(char * v) {
	strcpy(v,_type); return v;
}

// Setters
void CPenseBete :: setTitre(char * v) {
	strcpy(_titre,v);
}
void CPenseBete :: setDescription(char * v) {
	strcpy(_description,v);
}
void CPenseBete :: setType(char * v) {
	strcpy(_type,v);
}

// Surdéfinition de l'opérateur > pour l'ajout trié par titre
bool CPenseBete :: operator> (CPenseBete c) {
	char tmp1[MAX],tmp2[MAX];

	strcpy(tmp1,_titre);
	strcpy(tmp2,c._titre);
	strupr(tmp1);
	strupr(tmp2);
	return strcmp(tmp1,tmp2)>0;
}

// Redéfinition de l'opérateur << pour l'affichage
ostream& operator<<(ostream& o,CPenseBete c) {
	char tmp[MAX];
	
	if(strcmp(c.getTitre(tmp),"") != 0) cout << "Titre : " << c.getTitre(tmp) << endl;
	if(strcmp(c.getDescription(tmp),"") != 0) cout << "Description : " << c.getDescription(tmp) << endl;
	if(strcmp(c.getType(tmp),"") != 0) cout << "Type : " << c.getType(tmp) << endl;
return o;
}
