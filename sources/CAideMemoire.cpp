/****************************
	 CAideMemoire.cpp
 Gère la liste de CPenseBete
*****************************/

#include <iostream.h>
#include "CAideMemoire.h"
#include <stdlib.h>


/* Constructeur */
CAideMemoire :: CAideMemoire(void) { _liste ; }


/* Méthode d'affichage du Menu */
void CAideMemoire :: menu(void) {
int choix ;
do {
	do {
	entete();
	cout << "CorTex 2K5 -> Utilitaires -> Aide Memoire"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Aide Memoire >\n"<<endl;
	cout << " 1) Afficher la liste de Pense Bete."<<endl ;
	cout << " 2) Ajouter un Pense Bete."<<endl ;
	cout << " 3) Supprimer un Pense Bete."<<endl ;
	cout << " 4) Modifier un Pense Bete."<<endl ;
	cout << " 5) Aide."<<endl ;
	cout << "\n 0) Revenir au menu Principale."<<endl;
	cout << "\n____________________________________________________________\n"<<endl;

	cin >> choix ;
	if( (choix<0) || (choix>5) )
		cout <<"Ce choix n'existe pas." <<endl;
	}
	while ( (choix<0) || (choix>5) ) ;
	
	switch(choix) {
		case 0: break;
		case 1: afficher();break;
		case 2: ajouter();break;
		case 3: supprimer();break;
		case 4: modifier();break;
		case 5: aide();break;
	}

}
while(choix != 0);
}

/* Méthode d'affichage */
void CAideMemoire :: afficher(void) {
	entete();
	cout << "CorTex 2K5 -> Utilitaires -> Aide Memoire -> Affichage"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	_liste.afficher(false);
	int choix;
	do {
	cout << "\n 0) Retour au menu Aide Memoire."<<endl;
	cin >> choix; 
	if (choix != 0)
		cout << "Ce choix n'existe pas."<<endl;
	}
	while(choix!=0);
}

void CAideMemoire :: modifier(void) {

	entete();
	cout << "CorTex 2K5 -> Utilitaire -> Aide Memoire -> Modification d'un Pense Bete"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Modification d'un Pense Bete >"<<endl;

	// Modificiation depuis la liste de contacts.
		_liste.afficher(true);
		int id;
		if(!_liste.estVide()) {
			do {
			cout << "Saisissez l'Id du contact a modifier : "<<endl;
			cin>> id;
			if ( (id<0) || (id>=_liste.taille()) )
				cout << "Cet id n'existe pas."<<endl;
			}
			while( (id<0) || (id>=_liste.taille()) );
		
		    CPenseBete p = _liste.get(id);
			_liste.suppr(id);
			definirPenseBete(p,"Modification");

			int chx;
			do {
			cout << " 1) Modifier un autre Pense Bete."<<endl;
			cout << "\n 0) Retour au menu Aide Memoire."<<endl;
			cin >> chx ;
			if ( (chx<0) || (chx>1) )
				cout << "Ce choix n'existe pas."<<endl;
			}
			while((chx<0) || (chx>1));
			if (chx == 1)
				modifier();
		}
		else {
			int chx;
			do {
			cout << "\n 0) Retour au menu Aide Memoire."<<endl;
			cin >> chx;
			if(chx!=0)
				cout << "Ce choix n'existe pas.";
			}
			while(chx!=0);
		}
	

}

void CAideMemoire :: ajouter(void) {

	entete();
	cout << "CorTex 2K5 -> Aide Memoire -> Ajout d'un Pense Bete"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	
	char titre[MAX]="" ;

	cout << "< Ajouter un Pense Bete >"<<endl; 
		cout <<"Entrez le Titre du nouveau Pense Bete :\n"<< flush;
		cin.getline(titre,MAX);
		cin.getline(titre,MAX);

		CPenseBete p(titre); // création du nouveau Pense Bete

		definirPenseBete(p,"Ajout");

}


void CAideMemoire :: supprimer(void) {

	entete();
	cout << "CorTex 2K5 -> Aide Memoire -> Suppression d'un Pense Bete\n"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Suppression d'un Pense Bete >\n"<<endl;

	
		// Suppression depuis la liste de Pense Bete
		_liste.afficher(true);
		int id;
		if(!_liste.estVide()) {
			do {
			cout << "Saisissez l'Id du Pense Bete a supprimer : "<<endl;
			cin>> id;
			if ( (id<0) || (id>=_liste.taille()) )
				cout << "Cet id n'existe pas."<<endl;
			}
			while( (id<0) || (id>=_liste.taille()) );
		
			_liste.suppr(id);

			cout << "Pense Bete supprime.\n"<<endl;
			int chx;
			do {
			cout << " 1) Supprimer un autre Pense Bete."<<endl;
			cout << "\n 0) Retour au menu Aide Memoire."<<endl;
			cin >> chx ;
			if ( (chx<0) || (chx>1) )
				cout << "Ce choix n'existe pas."<<endl;
			}
			while((chx<0) || (chx>1));
			if (chx == 1)
				supprimer();
		}
		else {
			int chx;
			do {
			cout << "\n 0) Retour au menu Aide Memoire."<<endl;
			cin >> chx;
			if(chx!=0)
				cout << "Ce choix n'existe pas.";
			}
			while(chx!=0);
		}
	

}

void CAideMemoire :: aide(void) {
		entete();
	cout << "CorTex 2K5 -> Utilitaires -> Aide Memoire -> Aide\n"<<endl;
	cout << "< Aide >"<<endl;
	
	cout << "Aide sur les fonctions de l'aide memoire."<<endl;


			int chx;
			do {
			cout << "\n 0) Retour au menu Aide Memoire."<<endl;
			cin >> chx;
			if(chx!=0)
				cout << "Ce choix n'existe pas.";
			}
			while(chx!=0);
}

/* Méthode definirPenseBete */
void CAideMemoire :: definirPenseBete(CPenseBete& p,char * mode) {

		int choix;
		do  {
			entete();
			cout << "\nCorTex 2K5 -> Utilitaires -> Aide Memoire -> "<< mode <<" d'un Pense Bete\n"<<endl;
			cout << "____________________________________________________________\n"<<endl;
			cout << "< "<< mode <<" d'un Pense Bete >"<<endl;
			cout << "---------------------------------"<<endl;
			cout <<"Creation du nouveau Pense Bete :\n"<<endl;
			cout << p <<endl;		
			cout << "---------------------------------\n"<<endl;
			cout << "Saisie d'autres informations ou Validez le nouveau Pense Bete\n (Tapez 4 pour Validez) :\n"<<endl;
			do {
				cout << " 1)  Definir le Titre."<<endl;
				cout << " 2)  Definir le Type."<<endl;
				cout << " 3)  Definir la Description."<<endl;
				cout << " 4)  Validez."<<endl;
				cout << "\n 0) Quitter, sans validez le nouveau contact."<<endl;
				cin>> choix ;
				if( (choix<0)  || (choix>4) )
					cout <<"Ce choix n'existe pas."<<endl;
			}
			while( (choix<0) || (choix>4) );

		switch(choix) {
			case 0:break;
			case 1:
				cout << "Saisie du Titre :"<<endl;
				char t[MAX];
				cin.getline(t,MAX); 
				cin.getline(t,MAX); 
				p.setTitre(t);
				break;
			case 2:
				cout << "Saisie du Type : "<<endl;
				int chx ;
				do {
				cout << "1) Course"<<endl;
				cout << "2) Travail"<<endl;
				cout << "3) Idee"<<endl;
				cout << "4) Personnalise... "<<endl;
				cin >> chx ;
				if( (chx<1) || (chx >4) )
					cout << "Ce choix n'existe pas."<<endl;
				}
				while( (chx<1) || (chx >4) );

				switch(chx) {
				case 1 : p.setType("Course");break;
				case 2 : p.setType("Travail");break;
				case 3 : p.setType("Idee");break;
				case 4 : 
					char type[MAX] ;
					cout << "Entrer le Type de contact "<<endl;
					cin.getline(type,MAX);
					cin.getline(type,MAX);
						p.setType(type);
					break;
				}
				break;
			case 3:
				cout << "Saisie de la Description :"<<endl;
				char d[MAX];
				cin.getline(d,MAX);
				cin.getline(d,MAX);
				p.setDescription(d);
				break;

			case 4:
				_liste.ajoutTrie(p);
				break;

			}
		}
	while( (choix != 0) && (choix != 4));	
}