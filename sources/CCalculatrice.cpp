/*************************
	 CCalculatrice.cpp 
**************************/

#include <iostream.h>
#include "CCalculatrice.h"
#include <stdlib.h>

/* Méthode d'affichage du Menu */
void CCalculatrice :: menu(void) {
int choix ;
do {
	do {
	entete();
	cout << "CorTex 2K5 -> Utilitaires -> Calculatrice"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Calculatrice >\n"<<endl;
	cout << " 1) Faire un nouveau calcul."<<endl ;
	cout << " 0) Revenir au menu Utilitaires."<<endl;
	cout << "\n____________________________________________________________\n"<<endl;

	cin >> choix ;
	if( (choix<0) || (choix>1) )
		cout <<"Ce choix n'existe pas." <<endl;
	}
	while ( (choix<0) || (choix>1) ) ;
	
	switch(choix) {
		case 0: break;
		case 1: calcul();break;
	}
}
while(choix != 0);
}


/* Méthode d'affichage */
void CCalculatrice :: calcul(void) {
	entete();
	cout << "CorTex 2K5 -> Utilitaires -> Calculatrice"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	
	double nb1,nb2;
	char op;
	cout << "Entrez le 1ier nombre :"<<endl;
	cin >> nb1;

	cout << "Entrez l'operateur :"<<endl;
	cin >> op;

	cout << "Entrez le 2nd nombre :"<<endl;
	cin >> nb2;

	switch(op) {
	case '+':cout << " Resultat : "<< (((double) nb1+nb2))<<endl ;break;
	case '-':cout << " Resultat : "<< (((double) nb1-nb2))<<endl  ;break;
	case '*':cout << " Resultat : "<< (((double) nb1*nb2))<<endl  ;break;
	case '/':cout << " Resultat : "<< (((double) nb1/nb2))<<endl  ;break;
	}

	int choix;
	do {
	cout << "\n 0) Retour au menu Calculatrice."<<endl;
	cin >> choix; 
	if (choix != 0)
		cout << "Ce choix n'existe pas."<<endl;
	}
	while(choix != 0);
}