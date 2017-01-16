/*************************
	CRepertoire.cpp
Définition du repertoire
**************************/



#include "CRepertoire.h"
#include <iostream.h>
#include <stdlib.h>  
#include <fstream.h>  // pour la sauvegarde et le chargement de la liste ds un fichier


void entete(void) {
			system("cls");
			cout << "\n		       [  CorTeX 2K5  ]"<<endl;
			cout << "____________________________________________________________\n"<<endl;
}

/*  Constructeur  */
CRepertoire :: CRepertoire(void) {
	_listeContact ;
}


void CRepertoire :: menu(void) {
int choix ;
do {
	do {
	entete();
	cout << "CorTex 2K5 -> Repertoire"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Repertoire   "<<_listeContact.taille() << " contact(s) >\n"<<endl;
	cout << " 1) Afficher les contacts."<<endl ;
	cout << " 2) Ajouter un contact."<<endl ;
	cout << " 3) Supprimer un contact."<<endl ;
	cout << " 4) Modifier un contact."<<endl ;
	cout << " 5) Rechercher un/des contact(s)."<<endl ;
	cout << " 6) Statistiques."<<endl ;
	cout << " 7) Aide."<<endl ;
	cout << "\n 0) Retour au menu Principal."<<endl;
	cout << "\n____________________________________________________________\n"<<endl;

	cin >> choix ;
	if( (choix<0) || (choix>7) )
		cout <<"Ce choix n'existe pas." <<endl;
	}
	while ( (choix<0) || (choix>7) ) ;
	
	switch(choix) {
		case 0: 
			_listeContact.sauvegarder();
			break;
		case 1: afficher();break;
		case 2: ajouter();break;
		case 3: supprimer();break;
		case 4: modifier();break;
		case 5: rechercher();break;
		case 6: statistiques();break;
		case 7: aide();break;
	}

}
while(choix != 0);
}


void CRepertoire :: afficher(void) {
	
	entete();
	cout << "CorTex 2K5 -> Repertoire -> Affichage de la liste de contact"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	_listeContact.afficher(false);
	int choix;

	do {
	cout << "\n 0) Retour au menu Repertoire."<<endl;
	cin >> choix; 
	if (choix != 0)
		cout << "Ce choix n'existe pas."<<endl;
	}
	while(choix!=0);
}

void CRepertoire :: ajouter(void) {

	
	entete();
	cout << "CorTex 2K5 -> Repertoire -> Ajout d'un contact"<<endl;
	cout << "____________________________________________________________"<<endl;
	
	int choix ;
	char nom[MAX]="" , prenom[MAX]="";



	cout << "< Ajouter un Contact >"<<endl; 
	cout << "\n 1) Definir le Nom."<<endl;
	cout << " 2) Definir le Prenom."<<endl;
	do {
		cin >> choix;
	if((choix<1) || (choix>2))
		cout << "Choix inexistant."<<endl;
	}
	while( (choix <1) || (choix >2) );
	
	if (choix==1) {
		cout <<"Entrez le Nom du nouveau contact :\n"<< flush;
		cin.getline(nom,MAX);
		cin.getline(nom,MAX);

	}
	else {
		cout << "Entrez le Prenom du nouveau contact :\n"<< flush;
		cin.getline(prenom,MAX);
		cin.getline(prenom,MAX);
	}

		CContact c(nom,prenom); // création du nouveau contact
		definirContact(c,"Ajout");
		sauvegarderListe();

}

void CRepertoire :: supprimer(void) {


	entete();
	cout << "CorTex 2K5 -> Repertoire -> Suppression d'un contact\n"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Suppression d'un contact >\n"<<endl;

	int choix;
	do {
		cout << " 1) Suppression depuis la Liste de contact(s)." <<endl;
		cout << " 2) Suppression par recherche de contacts." <<endl;
		cout << " 3) Aide."<<endl;
		cin >> choix ;
		if (  (choix<1) || (choix>3) )
			cout << "Ce choix n'existe pas." << endl;
	}
	while(  (choix<1) || (choix>3) );
		
	switch(choix) {
	case 1: // Suppression depuis la liste de contacts.
		_listeContact.afficher(true);
		int id;
		if(!_listeContact.estVide()) {
			do {
			cout << "Saisissez l'Id du contact a supprimer : "<<endl;
			cin>> id;
			if ( (id<0) || (id>=_listeContact.taille())  )
				cout << "Cet id n'existe pas."<<endl;
			}
			while( (id<0) || (id>=_listeContact.taille()) );
		
			_listeContact.suppr(id);

			cout << "Contact supprime.\n"<<endl;
			int chx;
			do {
			cout << " 1) Supprimer un autre contact."<<endl;
			cout << "\n 0) Retour au menu Repertoire."<<endl;
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
			cout << "\n 0) Retour au menu repertoire."<<endl;
			cin >> chx;
			if(chx!=0)
				cout << "Ce choix n'existe pas.";
			}
			while(chx!=0);
		}
		break;

	case 2:
		if(!_listeContact.estVide()) {
			char nom[MAX];
			bool trouve;
			cout << "Saisissez le Nom ou le Prenom du contact."<<endl;
			cin >> nom;
			trouve = _listeContact.rechercher(nom,true); // true pour dire qu'il faut afficher l'indice de la position
			if(!trouve) { // s'il n'y a aucun resultat trouvé
				int chx;
				do {
				cout << "\n 0) Retour au menu repertoire."<<endl;
				cin >> chx;
				if(chx!=0)
					cout << "Ce choix n'existe pas.";
				}
				while(chx!=0);
			}
			else {
				int id;
				// Selection de l'Id du contact
				do {
					cout << "Saisissez l'Id du contact a supprimer :"<<endl;
					cin >> id;
					if ( (id <0) || (id>=_listeContact.taille()) )
						cout << "Cet Id n'existe pas."<<endl;
				}
				while( (id <0) || (id>=_listeContact.taille()) );
				// Supression du contact
				_listeContact.suppr(id);
				// Choix entre supprimer un autre contact ou revenir au menu Repertoire
					int chx;
					do {
						cout << " 1) Supprimer un autre contact."<<endl;
						cout << "\n 0) Retour au menu Repertoire."<<endl;
						cin >> chx ;
						if ( (chx<1) || (chx>2) )
							cout << "Ce choix n'existe pas."<<endl;
					}
					while((chx<1) || (chx>2));
					if (chx == 1)
						supprimer();
					}
		}
		else {
			int chx;
			do {
				cout << "\n 0) Retour au menu repertoire."<<endl;
				cin >> chx;
				if(chx!=0)
					cout << "Ce choix n'existe pas.";
			}
			while(chx!=0);
		}
		break;

	case 3:
		cout << "-- Aide sur la Fonction Supprimer un Contact --"<<endl;
		cout << "Le menu de suppresion d'un contact ce compose de deux partie :"<<endl;
		cout << "	1) Suppression depuis la Liste de contact(s)."<<endl;
		cout << "		-> Cette fonction affiche toute la liste de contact(s) \n";
		cout << "avec pour chaque contact un attribut \"Id\", il vous suffit alors\n";
		cout << "de donner l'\"Id\" du contact pour le supprimer de la liste de contact.\n"<<endl;
		cout << "	2) Suppression par recherche de contacts."<<endl;
		cout << "		-> Cette fonction vous permet d'afficher seulement les contacts repondant\n";
		cout << "au Nom ou au Prenom que vous saisirez. Il vous suffit alors de saisir l'\"Id\" du\n";
		cout << "contact pour le supprimez de la liste.\n"<<endl;
			int chx;
			do {
			cout << "\n 0) Retour au menu repertoire."<<endl;
			cin >> chx;
			if(chx!=0)
				cout << "Ce choix n'existe pas.";
			}
			while(chx!=0);
	}
}

void CRepertoire :: modifier(void) {
	entete();
	cout << "CorTex 2K5 -> Repertoire -> Modification d'un contact"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Modification d'un contact >"<<endl;

	int choix;
	do {
		cout << "\n 1) Modification depuis la Liste de contact(s)." <<endl;
		cout << " 2) Modification par recherche de contacts." <<endl;
		cout << " 3) Aide."<<endl;
		cin >> choix ;
		if (  (choix<1) || (choix>3) )
			cout << "Ce choix n'existe pas." << endl;
	}
	while(  (choix<1) || (choix>3) );
		
	switch(choix) {
	case 1: // Modification depuis la liste de contacts.
		_listeContact.afficher(true);
		int id;
		if(!_listeContact.estVide()) {
			do {
			cout << "Saisissez l'Id du contact a modifier : "<<endl;
			cin>> id;
			if ( (id<0) || (id>=_listeContact.taille()) )
				cout << "Cet id n'existe pas."<<endl;
			}
			while( (id<0) || (id>=_listeContact.taille()) );
		
		    CContact contact = _listeContact.get(id);
			_listeContact.suppr(id);
			definirContact(contact,"Modification");

			int chx;
			do {
			cout << "1) Modifier un autre contact."<<endl;
			cout << "\n 0) Retour au menu Repertoire."<<endl;
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
			cout << "\n 0) Retour au menu repertoire."<<endl;
			cin >> chx;
			if(chx!=0)
				cout << "Ce choix n'existe pas.";
			}
			while(chx!=0);
		}
		break;

	case 2:
		if(!_listeContact.estVide()) { // la liste n'est pas vide
			char nom[MAX];
			bool trouve;
			cout << "Saisissez le Nom ou le Prenom du contact."<<endl;
			cin >> nom;
			trouve = _listeContact.rechercher(nom,true); // true pour dire qu'il faut afficher l'indice de la position
			if(!trouve) { // s'il n'y a aucun resultat trouvé
				int chx;
				do {
				cout << "\n 0) Retour au menu repertoire."<<endl;
				cin >> chx;
				if(chx!=0)
					cout << "Ce choix n'existe pas.";
				}
				while(chx!=0);
			}
			else {
				int id;
				do {
					cout << "Saisissez l'Id du contact a modifier :"<<endl;
					cin >> id;
					if ( (id <0) || (id>=_listeContact.taille()) )
						cout << "Cet id n'existe pas."<<endl;
				}
				while( (id <0) || (id>=_listeContact.taille()) );
				// Modification du contact
				CContact contact = _listeContact.get(id);
				_listeContact.suppr(id);
				_listeContact.afficher(true);

				definirContact(contact,"Modification");
				// Choix entre supprimer un autre contact ou revenir au menu Repertoire
					int chx;
					do {
						cout << "1) Modifier un autre contact."<<endl;
						cout << "\n 0) Retour au menu Repertoire."<<endl;
						cin >> chx ;
						if ( (chx<0) || (chx>1) )
							cout << "Ce choix n'existe pas."<<endl;
					}
					while( (chx<0) || (chx>1) );
					if (chx == 1)
						modifier();
					}
		}
		else { // La liste est vide
			int chx;
			do {
				cout << "\n 0) Retour au menu repertoire."<<endl;
				cin >> chx;
				if(chx!=0)
					cout << "Ce choix n'existe pas.";
			}
			while(chx!=0);
		}
		break;

	case 3:
		cout << "-- Aide sur la Fonction Supprimer un Contact --"<<endl;
		cout << "Le menu de suppresion d'un contact ce compose de deux parties :"<<endl;
		cout << "	1) Suppression depuis la Liste de contact(s)."<<endl;
		cout << "		-> Cette fonction affiche toute la liste de contact(s) \n";
		cout << "		avec pour chaque contact un attribut \"Id\", il vous suffit alors\n";
		cout << "		de donner l'\"Id\" du contact pour le supprimer de la liste de contact.\n"<<endl;
		cout << "	2) Suppression par recherche de contacts."<<endl;
		cout << "		-> Cette fonction vous permet d'afficher seulement les contacts répondant\n";
		cout << "	au Nom ou au Prenom que vous saisirez. Il vous suffit alors de saisir l'\"Id\" du\n";
		cout << "		contact pour le supprimez de la liste.\n"<<endl;
		int chx;
		do {
		cout << "\n 0) Retour au menu repertoire."<<endl;
		cin >> chx;
		if(chx!=0)
			cout << "Ce choix n'existe pas.";
		}
		while(chx!=0);
	} 
}


void CRepertoire :: rechercher(void) {
	entete();
	cout << "CorTex 2K5 -> Repertoire -> Recherche d'un contact\n"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Recherche d'un contact >"<<endl;

	int choix;
	do {
		cout << "1) Recherche par Nom OU Prenom." <<endl;
		cout << "2) Recherche par Nom ET Prenom. " <<endl;
		cout << "3) Recherche par Pseudo."<<endl;
		cout << "4) Recherche par Type."<<endl;
		cout << "5) Aide."<<endl;
		cin >> choix ;
		if (  (choix<1) || (choix>5) )
			cout << "Ce choix n'existe pas." << endl;
	}
	while(  (choix<1) || (choix>5) );
		
	switch(choix) {
	case 1: // Recherche par Nom OU du Prenom
		if(!_listeContact.estVide()) {
			char nom[MAX] ;
			cout << " Saisissez le Nom OU le Prenom du contact recherche."<<endl;
			cin>> nom;
		
			_listeContact.rechercher(nom,false);

			int chx;
			do {
			cout << "1) Rechercher un autre contact."<<endl;
			cout << "\n 0) Retour au menu Repertoire."<<endl;
			cin >> chx ;
			if ( (chx<0) || (chx>0) )
				cout << "Ce choix n'existe pas."<<endl;
			}
			while((chx<0) || (chx>1));
			if (chx == 1)
				rechercher();
		}
		else {
			int chx;
			do {
			cout << "\n 0) Retour au menu repertoire."<<endl;
			cin >> chx;
			if(chx!=1)
				cout << "Ce choix n'existe pas.";
			}
			while(chx!=0);
		}
		break;

	case 2: // Recherche par Nom ET Prenom
		if(!_listeContact.estVide()) {
			char nom[MAX] ;
			cout << " Saisissez le Nom du contact recherche."<<endl;
			cin >> nom;
			char prenom[MAX] ;
			cout << " Saisissez le Prenom du contact recherche."<<endl;
			cin>> prenom;
		
			_listeContact.rechercher(nom,prenom);

			int chx;
			do {
			cout << "1) Rechercher un autre contact."<<endl;
			cout << "\n 0) Retour au menu Repertoire."<<endl;
			cin >> chx ;
			if ( (chx<0) || (chx>1) )
				cout << "Ce choix n'existe pas."<<endl;
			}
			while((chx<0) || (chx>1));
			if (chx == 1)
				rechercher();
		}
		else {
			int chx;
			do {
			cout << "\n 0) Retour au menu repertoire."<<endl;
			cin >> chx;
			if(chx!=0)
				cout << "Ce choix n'existe pas.";
			}
			while(chx!=0);
		}
		break;


	case 3: // Recherche par Pseudo
		if(!_listeContact.estVide()) {
			char pseudo[MAX] ;
			cout << " Saisissez le Pseudo du contact recherche."<<endl;
			cin>> pseudo;
		
			_listeContact.rechercherPseudo(pseudo);

			int chx;
			do {
			cout << "1) Rechercher un autre contact."<<endl;
			cout << "2) Retour au menu Repertoire."<<endl;
			cin >> chx ;
			if ( (chx<1) || (chx>2) )
				cout << "Ce choix n'existe pas."<<endl;
			}
			while((chx<1) || (chx>2));
			if (chx == 1)
				rechercher();
		}
		else {
			int chx;
			do {
			cout << "\n 0) Retour au menu repertoire."<<endl;
			cin >> chx;
			if(chx!=0)
				cout << "Ce choix n'existe pas.";
			}
			while(chx!=0);
		}
		break;
	case 4: // Recherche par Type
		if(!_listeContact.estVide()) {
			char type[MAX] ;
			cout << " Saisissez le Type du contact recherche."<<endl;
			cin>> type;
		
			_listeContact.rechercherType(type);

			int chx;
			do {
			cout << "1) Rechercher un autre contact."<<endl;
			cout << "\n 0) Retour au menu Repertoire."<<endl;
			cin >> chx ;
			if ( (chx<0) || (chx>1) )
				cout << "Ce choix n'existe pas."<<endl;
			}
			while((chx<0) || (chx>1));
			if (chx == 1)
				rechercher();
		}
		else {
			int chx;
			do {
			cout << "\n 0) Retour au menu repertoire."<<endl;
			cin >> chx;
			if(chx!=0)
				cout << "Ce choix n'existe pas.";
			}
			while(chx!=0);
		}
		break;

	case 5 :
		cout << "-- Aide sur la Fonction Recherche un Contact --"<<endl;
		cout << "Le menu de recherche d'un contact ce compose de 4 parties :"<<endl;
		cout << "	1) Recherche par Nom ou Prenom."<<endl;
		cout << "		-> Permet en ne saisisant qu'une valeur d'effectuer une recherche sur \n";
		cout << "le nom et le prenom des contacts\n";
		cout << "	2) Recherche par Nom ET Prenom."<<endl;
		cout << "		-> Permet de chercher un contact avec le nom et le prenom donne en parametre\n";
		cout << "	3) Recherche par Pseudo."<<endl;
		cout << "		-> Permet de chercher un contact en saisissant son pseudo\n";
		cout << "	4) Recherche par Type."<<endl;
		cout << "		-> Permet de chercher les contacts dont vous avez specifier le type\n";
	int chx;
			do {
			cout << "\n 0) Retour au menu repertoire."<<endl;
			cin >> chx;
			if(chx!=0)
				cout << "Ce choix n'existe pas.";
			}
			while(chx!=0);
	} 
}


void CRepertoire :: statistiques(void) {
	entete();
	cout << "CorTex 2K5 -> Repertoire -> Statistiques\n"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Statistiques >"<<endl;
	
	_listeContact.statistiques();
			int chx;
			do {
			cout << "\n 0) Retour au menu repertoire."<<endl;
			cin >> chx;
			if(chx!=0)
				cout << "Ce choix n'existe pas.";
			}
			while(chx!=0);
}


void CRepertoire :: aide(void) {
	entete();
	cout << "CorTex 2K5 -> Repertoire -> Aide\n"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Aide >"<<endl;
	
	cout << "\nAide sur les fonctions du Repertoire de contact."<<endl;
	cout << "Le repertoire offre 6 fonctionnalites :"<<endl;
	cout << "	1) L'affichage de la liste de contact"<<endl;
	cout << "	2) L'ajout d'un nouveau contact"<<endl;
	cout << "	3) La suppression d'un contact"<<endl;
	cout << "	4) La modification d'un contact"<<endl;
	cout << "	5) La recherche d'un contact"<<endl;
	cout << "	6) Les statistique sur les differents type de contacts"<<endl;
	int chx;
	do {
	cout << "\n 0) Retour au menu repertoire."<<endl;
	cin >> chx;
	if(chx!=0)
		cout << "Ce choix n'existe pas.";
	}
	while(chx!=0);
}

// Fonction pour définir un contact (utilise par ajouter() et modifier())
void CRepertoire :: definirContact(CContact & c,char * mode) {
		
		int choix;
		do  {
		entete();
		cout << "CorTex 2K5 -> Repertoire -> "<< mode <<" d'un contact"<<endl;
		cout << "____________________________________________________________\n"<<endl;
		cout << "< "<< mode <<" d'un contact >"<<endl;
		cout << "\n---------------------------------"<<endl;
		cout <<"Creation du nouveau contact :\n"<<endl;
		cout << c <<endl;		
		cout << "---------------------------------\n"<<endl;
		cout << "Saisie d'autres informations ou Validez le nouveau contact\n (Tapez 11 pour Validez) :\n"<<endl;
		do {
		cout << " 1)  Definir son Nom."<<endl;
		cout << " 2)  Definir son Prenom."<<endl;
		cout << " 3)  Definir de quel Type de contact il s'agit."<<endl;
		cout << " 4)  Definir son Pseudo."<<endl;
		cout << " 5)  Definir son numero de Telephone."<<endl;
		cout << " 6)  Definir son numero de Fax."<<endl;
		cout << " 7)  Definir sa date de Naissance."<<endl;
		cout << " 8)  Definir son E-Mail."<<endl;
		cout << " 9)  Definir son URL ou Blog."<<endl;
		cout << " 10) Definir un Commentaire."<<endl;
		cout << " 11) Validez."<<endl;
		cout << "\n 0) Quitter, sans validez le nouveau contact."<<endl;
		cin>> choix ;
		if( (choix<0)  || (choix>11) )
			cout <<"Ce choix n'existe pas."<<endl;
		}
		while( (choix<0) || (choix>11) );

		switch(choix) {
			case 0:break;
			case 1:
				cout << "Saisie du Nom :"<<endl;
				char nom[MAX];
				cin.getline(nom,MAX); 
				cin.getline(nom,MAX); 
				c.setNom(nom);
				break;
			case 2:
				cout << "Saisie du Prenom :"<<endl;
				char prenom[MAX];
				cin.getline(prenom,MAX);
				cin.getline(prenom,MAX);
				c.setPrenom(prenom);
				break;
			case 3:
				cout << "Saisie du Type de contact : "<<endl;
				int chx ;
				do {
				cout << "1) Collegue"<<endl;
				cout << "2) Ami(e)"<<endl;
				cout << "3) Famille"<<endl;
				cout << "4) Personnaliser... "<<endl;
				cin >> chx ;
				if( (chx<1) || (chx >4) )
					cout << "Ce choix n'existe pas."<<endl;
				}
				while( (chx<1) || (chx >4) );

				switch(chx) {
				case 1 : c.setType("Collegue");break;
				case 2 : c.setType("Ami(e)");break;
				case 3 : c.setType("Famille");break;
				case 4 : 
					char type[MAX] ;
					cout << "Entrer le Type de contact "<<endl;
					cin.getline(type,MAX);
					cin.getline(type,MAX);
						c.setType(type);
					break;
				}
				break;

			case 4:
				cout << "Saisie du Pseudo :"<<endl;
				char pseudo[MAX];
					cin.getline(pseudo,MAX);
					cin.getline(pseudo,MAX);
				c.setPseudo(pseudo);
				break;
			case 5:
				cout << "Saisie du numero de Telephone :"<<endl;
				char telephone[MAX];
					cin.getline(telephone,MAX);
					cin.getline(telephone,MAX);
				c.setTelephone(telephone);
				break;
			case 6:
				cout << "Saisie du numero de Fax :"<<endl;
				char fax[MAX];
					cin.getline(fax,MAX);
					cin.getline(fax,MAX);
				c.setFax(fax);
				break;
			case 7:
				cout << "Saisie de sa date de Naissance :"<<endl;
				char naissance[MAX];
					cin.getline(naissance,MAX);
					cin.getline(naissance,MAX);
				c.setNaissance(naissance);
				break;
			case 8:
				cout << "Saisie de son E-Mail :"<<endl;
				char mail[MAX];
					cin.getline(mail,MAX);
					cin.getline(mail,MAX);
				c.setEmail(mail);
				break;
			case 9:
				cout << "Saisie de son adresse web ou blog :"<<endl;
				char web[MAX];
					cin.getline(web,MAX);
					cin.getline(web,MAX);
				c.setWeb(web);
				break;
			case 10:
				cout << "Saisie d'un commentaire ou d'une note :" << endl;
				char note[MAX];
					cin.getline(note,MAX);
					cin.getline(note,MAX);
				c.setNote(note);
				break;
			case 11:
				_listeContact.ajoutTrie(c);
				break;
		}
	}
	while( (choix != 0) && (choix != 11));	
}


void CRepertoire :: sauvegarderListe(void) {
	_listeContact.sauvegarder();
}


void CRepertoire :: chargerListe(void) {
	_listeContact.charger();
	
}

