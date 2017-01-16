/*****************************
		CAgenda.cpp
	Gestion des rendez-vous
******************************/


#include "CAgenda.h"
#include <iostream.h>	
#include <stdlib.h>		// pour system("cls") qui permet d'effacé l'écran de la console
#include <fstream.h>	// pour la sauvegarde et le chargement de la liste ds un fichier
#include <stdio.h>
#include <time.h>
#include <string.h>

CAgenda :: CAgenda(void) {
	_listeRendezVous ;
}

void CAgenda :: menu(void) {
int choix ;
do {
	do {
		entete();
		cout << "CorTex 2K5 -> Agenda"<<endl;
		cout << "____________________________________________________________\n"<<endl;
		cout << "< Agenda   "<<_listeRendezVous.taille() << " rendez-vous >\n"<<endl;
		cout << " 1) Afficher les rendez-vous."<<endl;
		cout << " 2) Ajouter un rendez-vous."<<endl ;
		cout << " 3) Rechercher un rendez-vous."<<endl ;
		cout << " 4) Supprimer un rendez-vous."<<endl ;
		cout << " 5) Modifier un rendez-vous."<<endl ;
		cout << " 6) Aide."<<endl ;
		cout << "\n 0) Revenir au menu Principal."<<endl;
		cout << "\n____________________________________________________________\n"<<endl;

		cin >> choix ;
		if( (choix<0) || (choix>6) )
			cout <<"Ce choix n'existe pas." <<endl;
	}
	while ( (choix<0) || (choix>6) ) ;
	
	switch(choix) {
		case 0: cout <<"Retour au menu Principal."<<endl;break;
		case 1: afficher();break;
		case 2: ajouter();break;
		case 3: rechercher();break;
		case 4: supprimer();break;
		case 5: modifier();break;
		case 6: aide();break;
	}
}
while(choix != 0);
}

void CAgenda :: afficher(void) {
	int choix;
	do {
		entete();
		cout << "CorTex 2K5 -> Agenda -> Afficher des rendez-vous\n"<<endl;
		cout << "____________________________________________________________\n"<<endl;
		cout << "Afficher des rendez-vous"<<endl;
		do {
			cout << " 1)  Afficher les rendez-vous d'aujourd'hui."<<endl;
			cout << " 2)  Afficher les rendez-vous d'une date specifie."<<endl;
			cout << " 3)  Afficher tous les rendez-vous."<<endl;
			cout << " 4)  Retour au menu Agenda."<<endl;
			cin>> choix ;
			if( (choix<1)  || (choix>4) )
				cout <<"Ce choix n'existe pas."<<endl;
		}
		while( (choix<1) || (choix>4) );
		switch(choix) {
			case 1: afficherJour(); break;
			case 2: afficherDate(); break;
			case 3: afficherTous(); break;
			case 4: break;
		}
	}
	while(choix<1 ||choix>4);
}

void CAgenda :: afficherJour(void) {
	
	entete();
	cout << "CorTex 2K5 -> Agenda -> Affichage les rendez-vous d'aujourd'hui"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	
	time_t timestamp;
	struct tm *t;
	// Lecture de la date et de l'heure
	timestamp = time (NULL);
	t = gmtime(&timestamp);

	int j= t->tm_mday;
	int m= 1+t->tm_mon;
	int a= 1900+t-> tm_year;

	char tab[MAX];
	if (j<10 && m <10)
		sprintf(tab,"0%d 0%d %d",j,m,a);
	else if (j<10 && m>=10)
		sprintf(tab,"0%d  %d %d",j,m,a);
	else if (j>=10 && m<10)
		sprintf(tab,"%d 0%d %d",j,m,a);
	else
		sprintf(tab,"%d %d %d",j,m,a);

	_listeRendezVous.rechercherParDate(tab,0);
	int choix;

	do {
		cout << "\n0) Retour au menu Agenda."<<endl;
		cin >> choix;
		if (choix != 0)
			cout << "Ce choix n'existe pas."<<endl;
	}
	while(choix!=0);
}

void CAgenda :: afficherDate(void) {
	
	entete();
	cout << "CorTex 2K5 -> Agenda -> Affichage les rendez-vous d'une date specifie"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "Afficher les rendez-vous d'une date specifie\n"<<endl;
	cout <<"Entrez une date sous la forme \"jj mm aaaa\""<<endl;
	char datet[MAX];
	cin.getline(datet,MAX);

	_listeRendezVous.rechercherParDate(datet,0);

	int choix;
	do {
		cout << "\n0) Retour au menu Agenda."<<endl;
		cin >> choix; 
		if (choix != 0)
			cout << "Ce choix n'existe pas."<<endl;
	}
	while(choix!=0);
}



void CAgenda :: afficherTous(void) {
	
	entete();
	cout << "CorTex 2K5 -> Agenda -> Affichage de tous les rendez-vous"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "Afficher tous les rendez-vous\n"<<endl;

	char datet[MAX];
	cin.getline(datet,MAX);

	_listeRendezVous.afficher(0);

	int choix;
	do {
		cout << "\n0) Retour au menu Agenda."<<endl;
		cin >> choix; 
		if (choix != 0)
			cout << "Ce choix n'existe pas."<<endl;
	}
	while(choix!=0);
}


void CAgenda :: ajouter(void) {

	entete();
	cout << "CorTex 2K5 -> Agenda -> Ajouter un rendez-vous"<<endl;
	cout << "____________________________________________________________\n"<<endl;

	int choix ;
	char date[MAX]="!" , heureDeDebut[MAX]="!";

	cout << "	< Ajouter un Rendez-vous >"<<endl;
	cout << "> Definissez la date du rendez-vous sous la forme \"jj mm aaaa\" :"<<endl;
	cin.getline(date,MAX);
	cin.getline(date,MAX);

	cout << "> Definissez l'heure de debut du rendez-vous sous la forme \"hh mm\" :\n"<< flush;
	cin.getline(heureDeDebut,MAX);
	//cin.getline(heureDeDebut,MAX); //*** obliger d'ecrire 2 fois sinon ca marche pas !!!!

	CRendezVous c(date,heureDeDebut); // création du nouveau rendez-vous
	do  {	
		entete();
		cout << "CorTex 2K5 -> Agenda -> Ajouter un rendez-vous\n"<<endl;
		cout << "____________________________________________________________\n"<<endl;
		
		cout << "---------------------------------"<<endl;
		cout <<"Etat du nouveau rendez-vous :\n"<<endl;
		cout << c <<endl;		
		cout << "---------------------------------\n"<<endl;
		cout << "Saisie d'autres informations ou Validez le nouveau rendez-vous\n (Tapez 7 pour Validez) :\n"<<endl;
		
		do {
			cout << " 1)  (Re)Definir la Date."<<endl;
			cout << " 2)  (Re)Definir l'Heure de debut."<<endl;
			cout << " 3)  Definir une Heure de fin."<<endl;
			cout << " 4)  Definir un Type."<<endl;
			cout << " 5)  Definir une Description."<<endl;
			cout << " 6)  Quitter, sans validez le nouveau rendez vous."<<endl;
			cout << " 7)  Validez et Quitter."<<endl;
			cin>> choix ;
			if( (choix<1)  || (choix>7) )
				cout <<"Ce choix n'existe pas."<<endl;
		}
		while( (choix<1) || (choix>7) );

		switch(choix) {
			case 1:
				cout << "Saisie de la Date :"<<endl;
				char date[MAX];
				cin.getline(date,MAX); 
				cin.getline(date,MAX); 
				c.setDate(date);
				break;
			case 2:
				cout << "Saisie de l'Heure de debut :"<<endl;
				char heureDeDebut[MAX];
				cin.getline(heureDeDebut,MAX);
				cin.getline(heureDeDebut,MAX);
				c.setHeureDeDebut(heureDeDebut);
				break;
			case 3:
				cout << "Saisie d'une Heure de fin :"<<endl;
				char heureDeFin[MAX];
				cin.getline(heureDeFin,MAX);
				cin.getline(heureDeFin,MAX);
				c.setHeureDeFin(heureDeFin);
				break;
			case 4:
				cout << "Saisie du Type de rendez-vous : "<<endl;
				int chx ;
				do {
				cout << "1) Reunion"<<endl;
				cout << "2) Anniversaire"<<endl;
				cout << "3) Evenement"<<endl;
				cout << "4) Conges"<<endl;
				cout << "5) Deplacement"<<endl;
				cout << "6) Aucun"<<endl;
				cout << "7) Personnalise... "<<endl;
				cin >> chx ;
				if( (chx<1) || (chx >7) )
					cout << "Ce choix n'existe pas."<<endl;
				}
				while( (chx<1) || (chx >7) );

				switch(chx) {
				case 1 : c.setType("Reunion");break;
				case 2 : c.setType("Anniversaire");break;
				case 3 : c.setType("Evenement");break;
				case 4 : c.setType("Conges");break;
				case 5 : c.setType("Deplacement");break;
				case 6 : c.setType("");break;
				case 7 :
					cout << "Entrer le Type de rendez vous : "<<endl;
					char type[MAX];
					cin >> type;
					c.setType(type);
					break;
				}
				break;

			case 5:
				cout << "Saisie d'une Description :"<<endl;
				char description[MAX];
				cin.getline(description,MAX);
				cin.getline(description,MAX);
				c.setDescription(description);
				break;

			case 6: 
				break;
			case 7:
				_listeRendezVous.ajoutTrie(c);
				break;
		}
	}
	while( (choix != 6) && (choix != 7));	

}

void CAgenda :: supprimer(void) {

	entete();
	cout << "CorTex 2K5 -> Agenda -> Suppression d'un rendez-vous\n"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "Suppression d'un rendez-vous"<<endl;
	int choix;
	do {
		cout << "1) Suppression depuis la Liste de rendez-vous." <<endl;
		cout << "2) Suppression par recherche de rendez-vous." <<endl;
		cout << "3) Aide."<<endl;
		cin >> choix ;
		if (  (choix<1) || (choix>3) )
			cout << "Ce choix n'existe pas." << endl;
	}
	while(  (choix<1) || (choix>3) );
		
	switch(choix) {
	case 1:
		_listeRendezVous.afficher(true);
		int id;
		if(!_listeRendezVous.estVide()) {
			do {
			cout << "Saisissez l'Id du rendez-vous a supprimer : "<<endl;
			cin>> id;
			if ( (id<0) || (id>=_listeRendezVous.taille()) )
				cout << "Cet id n'existe pas."<<endl;
			}
			while( (id<0) || (id>=_listeRendezVous.taille()) );
		
			_listeRendezVous.suppr(id);

			cout << "Rendez-vous supprime.\n"<<endl;
			int chx;
			do {
			cout << "1) Supprimer un autre rendez vous."<<endl;
			cout << "2) Retour au menu Agenda."<<endl;
			cin >> chx ;
			if ( (chx<1) || (chx>2) )
				cout << "Ce choix n'existe pas."<<endl;
			}
			while((chx<1) || (chx>2));
			if (chx == 1)
				supprimer();
		}
		else {
			int chx;
			do {
			cout << "1) Retour au menu agenda."<<endl;
			cin >> chx;
			if(chx!=1)
				cout << "Ce choix n'existe pas.";
			}
			while(chx!=1);
		}
		break;

	case 2:
		if(!_listeRendezVous.estVide()) {
			char date[MAX];
			bool trouve;
			cout << "Saisissez la date et l'heure de debut du rendez-vous"<<endl;
			cin >> date;
			trouve = _listeRendezVous.rechercherParDate(date,1);
			if(!trouve) { // s'il n'y a aucun resultat trouvé
				int chx;
				do {
				cout << "1) Retour au menu agenda."<<endl;
				cin >> chx;
				if(chx!=1)
					cout << "Ce choix n'existe pas.";
				}
				while(chx!=1);
			}
			else {
				int id;
				do {
					cout << "Saisissez l'Id du rendez-vous a supprimer :"<<endl;
					cin >> id;
					if ( (id <0) || (id>=_listeRendezVous.taille()) )
						cout << "Cet Id n'existe pas."<<endl;
				}
				while( (id <0) || (id>=_listeRendezVous.taille()) );
				// Supression du rendez vous
				_listeRendezVous.suppr(id);
				// Choix entre supprimer un autre rendez vous ou revenir au menu Agenda
					int chx;
					do {
						cout << "1) Supprimer un autre rendez vous."<<endl;
						cout << "2) Retour au menu Agenda."<<endl;
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
				cout << "1) Retour au menu agenda."<<endl;
				cin >> chx;
				if(chx!=1)
					cout << "Ce choix n'existe pas.";
			}
			while(chx!=1);
		}
		break;

	case 3:
		cout << "-- Aide sur la Fonction Supprimer un Rendez-vous --"<<endl;
		cout << "Le menu de suppresion d'un rendez-vous ce compose de deux parties :"<<endl;
		cout << "	1) Suppression depuis la Liste de rendez-vous."<<endl;
		cout << "		->	Cette fonction affiche toute la liste de rendez-vous \n";
		cout << "			avec pour chaque rendez-vous un attribut \"Id\", il vous suffit alors\n";
		cout << "			de donner l'\"Id\" du rendez-vous pour le supprimer de la liste de rendez-vous.\n"<<endl;
		cout << "	2) Suppression par recherche de rendez-vous."<<endl;
		cout << "		->	Cette fonction vous permet d'afficher seulement les rendez-vous répondant\n";
		cout << "			au type que vous saisirez. Il vous suffit alors de saisir l'\"Id\" du\n";
		cout << "			rendez-vous pour le supprimez de la liste.\n"<<endl;
			int chx;
			do {
				cout << "1) Retour au menu agenda."<<endl;
				cin >> chx;
				if(chx!=1)
					cout << "Ce choix n'existe pas.";
			}
			while(chx!=1);
	} 
}

void CAgenda :: modifier(void) {

	entete();
	cout << "CorTex 2K5 -> Agenda -> Modification d'un rendez-vous"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "Modification d'un rendez-vous"<<endl;

	int choix;
	do {
		cout << "1) Modification depuis la Liste de rendez-vous." <<endl;
		cout << "2) Modification par recherche du type de rendez-vous." <<endl;
		cout << "3) Aide."<<endl;
		cin >> choix ;
		if (  (choix<1) || (choix>3) )
			cout << "Ce choix n'existe pas." << endl;
	}
	while((choix<1) || (choix>3));
		
	switch(choix) {
	case 1: // Modificiation depuis la liste de rendez vouss.
		_listeRendezVous.afficher(true);
		int id;
		if(!_listeRendezVous.estVide()) {
			do {
			cout << "Saisissez l'Id du rendez-vous a modifier : "<<endl;
			cin>> id;
			if ( (id<0) || (id>=_listeRendezVous.taille()) )
				cout << "Cet id n'existe pas."<<endl;
			}
			while( (id<0) || (id>=_listeRendezVous.taille()) );
		
		    CRendezVous rendezvous = _listeRendezVous.get(id);
			_listeRendezVous.suppr(id);
			definirRendezVous(rendezvous,"Modification");	

			int chx;
			do {
			cout << "1) Modifier un autre rendez-vous."<<endl;
			cout << "2) Retour au menu Agenda."<<endl;
			cin >> chx ;
			if ( (chx<1) || (chx>2) )
				cout << "Ce choix n'existe pas."<<endl;
			}
			while((chx<1) || (chx>2));
			if (chx == 1)
				modifier();
		}
		else {
			int chx;
			do {
			cout << "1) Retour au menu agenda."<<endl;
			cin >> chx;
			if(chx!=1)
				cout << "Ce choix n'existe pas.";
			}
			while(chx!=1);
		}
		break;
//OLALA sa supprime tout les rendez-vous d'un type donné ?! c nul ?!
	case 2:
		if(!_listeRendezVous.estVide()) { // la liste n'est pas vide
			char type[MAX];
			bool trouve;
			cout << "Saisissez le Type du rendez-vous."<<endl;
			cin >> type;										// OLALA
			trouve = _listeRendezVous.rechercherParType(type,true);	// true pour dire qu'il faut afficher l'indice de la position
																// de l'objet dans la liste.
			if(!trouve) { // s'il n'y a aucun resultat trouvé
				int chx;
				do {
				cout << "1) Retour au menu agenda."<<endl;
				cin >> chx;
				if(chx!=1)
					cout << "Ce choix n'existe pas.";
				}
				while(chx!=1);
			}
			else {
				int id;
				do {
					cout << "Saisissez l'Id du rendez-vous a modifier :"<<endl;
					cin >> id;
					if ( (id <0) || (id>=_listeRendezVous.taille()) )
						cout << "Cet id n'existe pas."<<endl;
				}
				while( (id <0) || (id>=_listeRendezVous.taille()) );
				// Modification du rendez vous
				CRendezVous rendezvous = _listeRendezVous.get(id);
				_listeRendezVous.suppr(id);
				
				_listeRendezVous.afficher(true);

				definirRendezVous(rendezvous,"Modification");
				// Choix entre supprimer un autre rendez vous ou revenir au menu Agenda
					int chx;
					do {
						cout << "1) Supprimer un autre rendez-vous."<<endl;
						cout << "2) Retour au menu Agenda."<<endl;
						cin >> chx ;
						if ( (chx<1) || (chx>2) )
							cout << "Ce choix n'existe pas."<<endl;
					}
					while((chx<1) || (chx>2));
					if (chx == 1)
						modifier();
					}
		}
		else { // La liste est vide
			int chx;
			do {
				cout << "1) Retour au menu agenda."<<endl;
				cin >> chx;
				if(chx!=1)
					cout << "Ce choix n'existe pas.";
			}
			while(chx!=1);
		}
		break;

	case 3:
		cout << "-- Aide sur la Fonction Supprimer un Rendez-vous --"<<endl;
		cout << "Le menu de suppresion d'un rendez-vous ce compose de deux parties :"<<endl;
		cout << "	1) Suppression depuis la Liste de rendez-vous."<<endl;
		cout << "		->	Cette fonction affiche toute la liste de rendez-vous \n";
		cout << "			avec pour chaque rendez-vous un attribut \"Id\", il vous suffit alors\n";
		cout << "			de donner l'\"Id\" du rendez-vous pour le supprimer de la liste de rendez-vous.\n"<<endl;
		cout << "	2) Suppression par recherche de rendez-vous."<<endl;
		cout << "		->	Cette fonction vous permet d'afficher seulement les rendez-vous répondant\n";
		cout << "			au type que vous saisirez. Il vous suffit alors de saisir l'\"Id\" du\n";
		cout << "			rendez-vous pour le supprimez de la liste.\n"<<endl;

	} 
}


void CAgenda :: rechercher(void) {

	entete();
	cout << "CorTex 2K5 -> Agenda -> Recherche d'un Rendez-vous\n"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "Recherche d'un Rendez-vous\n"<<endl;

	int choix;
	do {
		cout << "1) Recherche par Date." <<endl;
		cout << "2) Recherche par Type. " <<endl;
		cout << "3) Aide."<<endl;
		cin >> choix ;
		if (  (choix<1) || (choix>3) )
			cout << "Ce choix n'existe pas." << endl;
	}
	while(  (choix<1) || (choix>3) );
		
	switch(choix) {
	case 1:
		if(!_listeRendezVous.estVide()) {
			char date[MAX] ;
			cout << " Saisissez la Date du rendez-vous a recherche."<<endl;
			cin.getline(date,MAX); 	
			cin.getline(date,MAX);

			_listeRendezVous.rechercherParDate(date,false);

			int chx;
			do {
			cout << "1) Rechercher un autre rendez-vous."<<endl;
			cout << "2) Retour au menu Agenda."<<endl;
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
			cout << "0) Retour au menu agenda."<<endl;
			cin >> chx;
			if(chx!=0)
				cout << "Ce choix n'existe pas."<<endl;
			}
			while(chx!=0);
		}
		break;

	case 2: // Recherche par Type
		if(!_listeRendezVous.estVide()) {
			char type[MAX] ;
			cout << " Saisissez le Type du rendez-vous rechercher."<<endl;
			cin.getline(type,MAX); 						
			cin.getline(type,MAX); 							
		
			_listeRendezVous.rechercherParType(type,1);

			int chx;
			do {
			cout << "1) Rechercher un autre rendez-vous."<<endl;
			cout << "2) Retour au menu Agenda."<<endl;
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
			cout << "0) Retour au menu agenda."<<endl;
			cin >> chx;
			if(chx!=0)
				cout << "Ce choix n'existe pas."<<endl;
			}
			while(chx!=0);
		}
		break;

	} 
}


//Aide
void CAgenda :: aide(void) {

	entete();
	cout << "CorTex 2K5 -> Agenda -> Aide\n"<<endl;
	cout << "< Aide >"<<endl;
	cout << "L'agenda contient des rendez-vous qui peuvent etre definit par :"<<endl;
	cout << "\t - Une date, une heure de début, une heure de fin, un type ou une description"<<endl;
	cout << "Vous pouvez afficher les contacts de trois maniere differente"<<endl;
	cout << "\t - Rendez-vous du jour, ou rendez-vous d'une date donnee ou bien tous les rendez-vous"<<endl;
	cout << "Sinon vous pouvez evidement :"<<endl;
	cout << "\t - Modifier, supprimer, ou ajouter un rendez.\n"<<endl;


			int chx;
			do {
			cout << "0) Retour au menu agenda."<<endl;
			cin >> chx;
			if(chx!=0)
				cout << "Ce choix n'existe pas."<<endl;
			}
			while(chx!=0);
}


// Fonction pour définir un rendez vous (utilise par ajouter() et modifier())
void CAgenda :: definirRendezVous(CRendezVous & c,char * mode) {
		int choix;
		do  {
		entete();
		cout << "affichage";
		_listeRendezVous.afficher(true);
		cout << "\nCorTex 2K5 -> Agenda -> "<< mode <<" d'un rendez-vous\n"<<endl;
		cout << "< "<< mode <<" d'un rendez vous >"<<endl;
		cout << "---------------------------------"<<endl;
		cout <<"Creation du nouveau rendez-vous :\n"<<endl;
		cout << c <<endl;		
		cout << "---------------------------------\n"<<endl;
		cout << "Saisie d'autres informations ou Validez le nouveau rendez-vous\n (Tapez 12 pour Validez) :\n"<<endl;
		do {
			cout << "< "<<mode<<" d'un rendez vous"<<endl;
			cout << "1)  Definir sa Date."<<endl;
			cout << "2)  Definir son Heure de debut."<<endl;
			cout << "3)  Definir son Heure de fin."<<endl;
			cout << "4)  Definir son Type."<<endl;
			cout << "5)  Definir une Description."<<endl;
			cout << "6)  Quitter, sans validez le nouveau rendez-vous."<<endl;
			cout << "7)  Validez et Quitter."<<endl;
			cin>> choix ;
			if( (choix<1)  || (choix>7) )
				cout <<"Ce choix n'existe pas."<<endl;
			}
			while( (choix<1) || (choix>7) );

			switch(choix) {
				case 1:
					char date[MAX];
					cout << "Saisie d'une Date :"<<endl;
					cin >> date;
					cout << "date saisi :" << date; 
					c.setDate(date);
					break;
				case 2:
					cout << "Saisie de l'Heure de debut :"<<endl;
					char heureDeDebut[MAX];
					cin>>heureDeDebut;
					c.setHeureDeDebut(heureDeDebut);
					break;
				case 3:
					cout << "Saisie de l'Heure de fin :"<<endl;
					char heureDeFin[MAX];
					cin>>heureDeFin;
					c.setHeureDeFin(heureDeFin);
					break;
				case 4:
					cout << "Saisie du Type de rendez-vous : "<<endl;
					int chx ;
					do {
					cout << "1) Reunion"<<endl;
					cout << "2) Anniversaire"<<endl;
					cout << "3) Evenement"<<endl;
					cout << "4) Conges"<<endl;
					cout << "5) Deplacement"<<endl;
					cout << "6) Aucun"<<endl;
					cout << "7) Personnalise... "<<endl;
					cin >> chx ;
					if( (chx<1) || (chx >7) )
						cout << "Ce choix n'existe pas."<<endl;
					}
					while( (chx<1) || (chx >7) );

					switch(chx) {
					case 1 : c.setType("Reunion");break;
					case 2 : c.setType("Anniversaire");break;
					case 3 : c.setType("Evenement");break;
					case 4 : c.setType("Conges");break;
					case 5 : c.setType("Deplacement");break;
					case 6 : c.setType("");break;
					case 7 :
						cout << "Entrer le Type de rendez vous : "<<endl;
						char type[MAX];
						cin >> type;
						c.setType(type);
						break;
					}
					break;
				case 5:
					cout << "Saisie d'une Description :"<<endl;
					char description[MAX];
					cin.getline(description,MAX);
					cin.getline(description,MAX);
					c.setDescription(description);
					break;
				case 6:
					break;
				case 7:
					_listeRendezVous.ajoutTrie(c);
					break;
			}
	}
	while( (choix != 6) && (choix != 7));	
}


void CAgenda :: sauvegarderListe(void) {
	_listeRendezVous.sauvegarder();
}


void CAgenda :: chargerListe(void) {
	_listeRendezVous.charger();
	
}

