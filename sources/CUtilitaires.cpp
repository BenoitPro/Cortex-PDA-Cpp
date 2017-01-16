/*******************************
		CUtilitaire.cpp 
	Gère les utilitaires
*******************************/

#include "CUtilitaires.h"
#include <stdlib.h>

void CUtilitaires :: menu() {
int choix ;
do {
	do {
	entete();
	cout << "CorTex 2K5 -> Utilitaires"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Utilitaires >\n"<<endl;
	cout << " 1) Calculatrice."<<endl ;
	cout << " 2) Aide Memoire."<<endl ;
	cout << " 3) Block Note."<<endl ;
	cout << " 4) Aide."<<endl ;
	cout << "\n 0) Revenir au menu Principale."<<endl;
	cout << "\n____________________________________________________________\n"<<endl;

	cin >> choix ;
	if( (choix<0) || (choix>4) )
		cout <<"Ce choix n'existe pas." <<endl;
	}
	while ( (choix<0) || (choix>4) ) ;
	
	switch(choix) {
		case 0: cout <<"Retour au menu Principale."<<endl;break;
		case 1: calculatrice.menu();break;
		case 2: aideMemoire.menu();break;
		case 3: blockNote.menu();break;
		case 4: aide();break;
	}

}
while(choix != 0);
}

void CUtilitaires :: aide() {
	entete();
	cout << "CorTex 2K5 -> Utilitaires -> Aide"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Aide >"<<endl;
	cout << "Vous pous trouvez dans cette section 3 utilitaires pratiques :"<<endl;
	cout << "\t - Une calculatrice, gerant 4 operations mathematique de bases"<<endl;
	cout << "\t - Un Aide memoire, pemettant de gere des Pense Betes"<<endl;
	cout << "\t - Un Block Note, offrant un systeme de gestion de Notes"<<endl;
	int chx;
	do {
		cout << "0) Retour au menu Principale."<<endl;
		cin >> chx;
		if(chx!=0)
			cout << "Ce choix n'existe pas.";
	}
	while(chx!=0);
}

