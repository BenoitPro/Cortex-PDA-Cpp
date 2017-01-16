/******************************************
				CPda.cpp
	Lance les menus des différents
élements du projet (agenda, répertoire etc)
*******************************************/

#include <stdlib.h>
#include <iomanip.h> 
#include <iostream.h> 
#include "CRepertoire.cpp"
#include "CSysteme.cpp"
#include "CUtilitaires.cpp"
#include "CAgenda.cpp"


/* Fonction principale (main) */
void main(void) {

CRepertoire repertoire;			// le Repertoire
CSysteme systeme ;				// le Systeme
CUtilitaires utilitaires ;		// les Utilitaires
CAgenda agenda;					// l'Agenda


/* Gestion du repertoire */
repertoire.chargerListe();


/* Gestion de l'affichage console */
system("color 0F");
system("title [- CorTeX 2K5 -] par Anthony et Benoit Maréchal");


/* Gestion de la premiere connexion */
if(!systeme.charger()) { // si aucun mot de passe n'as été défini
	systeme.setMotDePasse(true);
	int choix; 
	do {
		cout << "\n Voulez-vous definir des maintenant vos informations personnelles :"<<endl;
		cout << " 1) Oui, je veux les definir des maintenant."<<endl;
		cout << " 2) Non, je les definirai plus tard. "<<endl;
		cin >> choix;
		if( (choix<1) || (choix>2) )
			cout << "Ce choix n'existe pas."<<endl;
	}
	while( (choix<1) || (choix>2) );
	if (choix == 1)
		systeme.setProprietaire();
}

char passe[MAX]; 
char tmp[MAX];
do {
	entete();
	cout << "CorTeX 2K5 -> Identification"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Saisi du mot de passe >\n"<<endl;
	cout << "Veillez entrez le mot de passe (sans espace) :" << endl;
	cin >> passe;
}
while(strcmp(passe,systeme.getMotDePasse(tmp))!=0);


/* Gestion du menu Principale de CorTeX 2K5*/
int choix;
do {
	do {
		system("cls");
		cout << "\n		       [  CorTeX 2K5  ]"<<endl;
		cout << "____________________________________________________________\n"<<endl;
		cout << "CorTeX 2K5 -> Accueil"<<endl;
		cout << "____________________________________________________________\n"<<endl;
		cout << "< Accueil >\n"<<endl;
		cout << " 1) Repertoire"<<endl;
		cout << " 2) Agenda"<<endl;
		cout << " 3) Utilitaires"<<endl;
		cout << " 4) Systeme"<<endl;
		cout << "\n 0) Quitter CorTeX 2K5."<<endl;
		cout << "\n____________________________________________________________\n"<<endl;
		cin >> choix;
		if ( (choix<0) || (choix>4) )
			cout <<"Ce choix n'existe pas"<<endl;
	}
	while ( (choix<0) || (choix>4) );

	switch(choix) {
		case 0: repertoire.sauvegarderListe();break;
		case 1:	repertoire.menu();break;
		case 2: agenda.menu(); break;
		case 3: utilitaires.menu(); break;
		case 4: systeme.menu(); break;
	}
}
while(choix != 0);
}

