/**********************
	 CBlockNote.cpp
 Gère la liste de Note
**********************/

#include <iostream.h>
#include "CBlockNote.h"
#include <stdlib.h>


/* Constructeur */
CBlockNote :: CBlockNote(void) { _liste ; }


/* Méthode d'affichage du Menu */
void CBlockNote :: menu(void) {
int choix ;
do {
	do {
	entete();
	cout << "CorTex 2K5 -> Utilitaires -> Block Note"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Block Note >\n"<<endl;
	cout << " 1) Afficher les Notes."<<endl ;
	cout << " 2) Ajouter une Note."<<endl ;
	cout << " 3) Supprimer une Note."<<endl ;
	cout << " 4) Modifier une Note."<<endl ;
	cout << "\n 0) Revenir au menu Utilitaire."<<endl;
	cout << "\n____________________________________________________________\n"<<endl;

	cin >> choix ;
	if( (choix<0) || (choix>4) )
		cout <<"Ce choix n'existe pas." <<endl;
	}
	while ( (choix<0) || (choix>4) ) ;
	switch(choix) {
		case 0: break;
		case 1: afficher();break;
		case 2: ajouter();break;
		case 3: supprimer();break;
		case 4: modifier();break;
	}
}
while(choix != 0);
}

/* Méthode d'affichage */
void CBlockNote :: afficher(void) {
	entete();
	cout << "CorTex 2K5 -> Utilitaires -> Block Note -> Affichage"<<endl;
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

void CBlockNote :: modifier(void) {

	entete();
	cout << "CorTex 2K5 -> Utilitaires -> Block Note -> Modification d'une Note"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Modification d'une Note >"<<endl;

	// Modificiation depuis la liste.
		_liste.afficher(true);
		int id;
		if(!_liste.estVide()) {
			do {
			cout << "Saisissez l'Id de la Note a modifier : "<<endl;
			cin>> id;
			if ( (id<0) || (id>=_liste.taille()) )
				cout << "Cet id n'existe pas."<<endl;
			}
			while( (id<0) || (id>=_liste.taille()) );
		
		    CNote note = _liste.get(id);
			_liste.suppr(id);
			definirNote(note,"Modification");

			int chx;
			do {
			cout << " 1) Modifier une autre Note."<<endl;
			cout << "\n 0) Retour au menu Block Note."<<endl;
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
			cout << "\n 0) Retour au menu Block Note."<<endl;
			cin >> chx;
			if(chx!=0)
				cout << "Ce choix n'existe pas.";
			}
			while(chx!=0);
		}
}

void CBlockNote :: ajouter(void) {

	entete();
	cout << "CorTex 2K5 -> Utilitaires -> Block Note -> Ajout d'une Note"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	
	char note[MAX]="" ;

	cout << "< Ajouter une Note >"<<endl; 
		cout <<"Entrez une nouvelle Note :\n"<< flush;
		cin.getline(note,MAX);
		cin.getline(note,MAX);
		CNote n(note);
		_liste.ajout(n,0);
}


void CBlockNote :: supprimer(void) {

	entete();
	cout << "CorTex 2K5 -> Utilitaires -> Block Note -> Suppression d'une Note \n"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Suppression d'une Note >\n"<<endl;
	
		// Suppression depuis la liste de Note
		_liste.afficher(true);
		int id;
		if(!_liste.estVide()) {
			do {
			cout << "Saisissez l'Id de la Note a supprimer : "<<endl;
			cin>> id;
			if ( (id<0) || (id>=_liste.taille()) )
				cout << "Cet id n'existe pas."<<endl;
			}
			while( (id<0) || (id>=_liste.taille()) );
		
			_liste.suppr(id);

			cout << "Note supprime.\n"<<endl;
			int chx;
			do {
			cout << " 1) Supprimer une autre Note."<<endl;
			cout << "\n 0) Retour au menu Block Note."<<endl;
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
			cout << "\n 0) Retour au menu Block Note."<<endl;
			cin >> chx;
			if(chx!=0)
				cout << "Ce choix n'existe pas.";
			}
			while(chx!=0);
		}
}

/* Méthode definirPenseBete */
void CBlockNote :: definirNote(CNote & n,char * mode) {
		int choix;
		do  {
		entete();
		cout << "\nCorTex 2K5 -> Utilitaires -> Block Note -> "<< mode <<" d'une Note\n"<<endl;
		cout << "____________________________________________________________\n"<<endl;
		cout << "< "<< mode <<" d'une Note"<<endl;
		cout << "---------------------------------"<<endl;
		cout <<"Creation de la nouvelle Note :\n"<<endl;
		cout << n <<endl;		
		cout << "---------------------------------\n"<<endl;

		cout << "Saisie ou Validation de la nouvelle Note\n (Tapez 2 pour Validez) :\n"<<endl;
		
		do {
		cout << " 1)  Definir la Note."<<endl;
		cout << " 2)  Validez."<<endl;
		cout << "\n 0) Quitter, sans validez la nouvelle Note."<<endl;
		cin>> choix ;
		if( (choix<0)  || (choix>2) )
			cout <<"Ce choix n'existe pas."<<endl;
		}
		while( (choix<0) || (choix>2) );

		char note[MAX];
		switch(choix) {
			case 0:break;
			case 1:
				cout << "Saisie de la Note :"<<endl;
				cin.getline(note,MAX); 
				cin.getline(note,MAX); 
				n.setNote(note);
				break;
			
			case 2:
				_liste.ajout(n,0);
				break;

		}
	}
	while( (choix != 0) && (choix != 2));	
}