/***********************************
		CSysteme.cpp
Gere les propriétés du mode console
************************************/

#include "CSysteme.h"
#include <stdlib.h>
#include <string.h>
#include <iostream.h>
#include <fstream.h>
#define MAX 255

CSysteme :: CSysteme(void) {
_proprietaire;
}


/* Méthode d'affichage du Menu */
void CSysteme :: menu() {
int choix ;
do {
	do {
	entete();
	cout << "CorTex 2K5 -> Systeme"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Systeme >\n"<<endl;
	cout << " 1) Definir le mot de passe."<<endl ;
	cout << " 2) Voir et Definir mes informations personnelles ."<<endl ;
	cout << " 3) Definir la couleur de fond."<<endl ;
	cout << " 4) Definir la couleur du texte."<<endl ;
	cout << " 5) Aide."<<endl ;
	cout << "\n 0) Retour au menu Principale."<<endl;
	cout << "\n____________________________________________________________\n"<<endl;

	cin >> choix ;
	if( (choix<0) || (choix>5) )
		cout <<"Ce choix n'existe pas." <<endl;
	}
	while ( (choix<0) || (choix>5) ) ;
	
	switch(choix) {
		case 0: cout <<"Retour au menu Principale."<<endl;break;
		case 1: setMotDePasse(false);break;
		case 2: setProprietaire();break;
		case 3: setCouleurFond();break;
		case 4: setCouleurTexte();break;
		case 5: aide();break;
	}
}
while(choix != 0);
}


/* Méthode de définition de la couleur de fond */
void CSysteme :: setCouleurFond(void) {

	char fond[2];
	char cmd[MAX];
	char texte[2];
	entete();
	cout << "CorTex 2K5 -> Systeme -> Definition de la couleur du fond"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Couleur du fond >\n"<<endl;

	cout << "entrer la nouvelle couleur de fond [0-9;a-f] : "<<endl;
	cin >> fond ;

	// on definie la nouvelle couleur de fond	
	_proprietaire.setCouleurFond(fond);

	strcpy(cmd,"color "); // commande a envoyer
	_proprietaire.setCouleurTexte("0"); 
	_proprietaire.getCouleurTexte(texte); // récuperation de la couleur du texte
	strcat(cmd,fond);
	strcat(cmd,texte);
	system(cmd); // execution de la commande

	int choix;
	do {
		cout << "1) Choisir une autre couleur."<<endl;
		cout << "0) Revenir au menu Systeme."<<endl;
		cin >> choix;
		if((choix <0) || (choix >1))
			cout << "Ce choix n'existe pas."<<endl;
	}
	while((choix <0) || (choix >1));
	if (choix==1)
		setCouleurFond();

}
/* Méthode de définition de la couleur du texte */
void CSysteme :: setCouleurTexte(void) {
	char texte[2];
	char cmd[MAX];
	char fond[2];
	
	entete();
	cout << "CorTex 2K5 -> Systeme -> Definition de la couleur du texte"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Couleur du texte >\n"<<endl;

	cout << "entrer la nouvelle couleur de texte [0-9;a-f] : "<<endl;
	cin >> texte ;

	// on definie la nouvelle couleur de fond	
	_proprietaire.setCouleurTexte(texte);

	strcpy(cmd,"color "); // commande a envoyer
	_proprietaire.setCouleurFond("0"); 
	_proprietaire.getCouleurFond(fond); // récuperation de la couleur du texte
	strcat(cmd,fond);
	strcat(cmd,texte);
	system(cmd); // execution de la commande

	int choix;
	do {
		cout << "1) Choisir une autre couleur."<<endl;
		cout << "0) Revenir au menu Systeme."<<endl;
		cin >> choix;
		if((choix <0) || (choix >1))
			cout << "Ce choix n'existe pas."<<endl;
	}
	while((choix <0) || (choix >1));
	if (choix==1)
		setCouleurTexte();

}

/* Méthode de définition du mot de passe du proprietaire */
void CSysteme :: setMotDePasse(bool connex) {
	
	char mdp[MAX];
	entete();
	if(connex)
		cout << "CorTex 2K5 -> Premiere connexion, definition du mot de passe"<<endl;
	else 
		cout << "CorTex 2K5 -> Systeme -> Definition du mot de passe"<<endl;
	
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Mot de passe >"<<endl;
	
	cout << "tapez votre nouveau mot de passe (sans espace) : "<<endl;
	cin >> mdp ;

	_proprietaire.setMotDePasse(mdp);

	cout << "Votre nouveau mot de passe est desormais : "<< _proprietaire.getMotDePasse(mdp)<<endl;
	sauvegarder();
	system("pause");
}


char * CSysteme :: getMotDePasse(char * m) {
	return _proprietaire.getMotDePasse(m);
}


void CSysteme :: setProprietaire(void) {
	int choix;
	do  {	
	
		entete();
		cout << "CorTex 2K5 -> Systeme -> Definir le Proprietaire"<<endl;
		cout << "____________________________________________________________\n"<<endl;
		cout << "< Definir le Proprietaire >\n"<<endl;

		cout << "---------------------------------"<<endl;
		cout <<"Status du proprietaire :\n"<<endl;
		cout << _proprietaire <<endl;		
		cout << "---------------------------------\n"<<endl;

		cout << "Saisie d'autres informations ou Validez le nouveau contact :\n"<<endl;
		
		do {
		cout << " 1)  Definir mon Nom."<<endl;
		cout << " 2)  Definir mon Prenom."<<endl;
		cout << " 3)  Definir mon Pseudo."<<endl;
		cout << " 4)  Definir mon Adresse 1."<<endl;
		cout << " 5)  Definir mon Adresse 2."<<endl;
		cout << " 6)  Definir mon numero de Telephone fixe."<<endl;
		cout << " 7)  Definir mon numero de Telephone portable."<<endl;
		cout << " 8)  Definir mon numero de Fax."<<endl;
		cout << " 9)  Definir mon E-Mail."<<endl;
		cout << " 10) Definir mon adresse Web ou blog."<<endl;
		cout << " 11) Definir une Note ou un commentaire ."<<endl;
		cout << "\n 0)  Validation."<<endl;
		cin>> choix ;
		if( (choix<0)  || (choix>11) )
			cout <<"Ce choix n'existe pas."<<endl;
		}
		while( (choix<0) || (choix>11) );
		switch(choix) {
			case 1:
				cout << "Saisie du nouveau Nom :"<<endl;
				char nom[MAX];
				cin.getline(nom,MAX);
				cin.getline(nom,MAX); 
				_proprietaire.setNom(nom);
				break;
			case 2:
				cout << "Saisie du nouveau Prenom :"<<endl;
				char prenom[MAX];
				cin.getline(prenom,MAX);
				cin.getline(prenom,MAX);
				_proprietaire.setPrenom(prenom);
				break;
			case 3:
				cout << "Saisie du Pseudo : "<<endl;
				char pseudo[MAX];
				cin.getline(pseudo,MAX);
				cin.getline(pseudo,MAX);
				_proprietaire.setPseudo(pseudo);
				break;
			case 4:
				cout << "Saisie de l'Adresse 1 :"<<endl;
				char ad[MAX];
				cin.getline(ad,MAX);
				cin.getline(ad,MAX);
				_proprietaire.setAdresse1(ad);
				break;
			case 5:
				cout << "Saisie de l'Adresse 2 :"<<endl;
				char ad2[MAX];
				cin.getline(ad2,MAX);
				cin.getline(ad2,MAX);
				_proprietaire.setAdresse2(ad2);
				break;
			case 6:
				cout << "Saisie du numero de Telephone fixe :"<<endl;
				char fixe[MAX];
				cin.getline(fixe,MAX);
				cin.getline(fixe,MAX);
				_proprietaire.setTelephoneFixe(fixe);
				break;
			case 7:
				cout << "Saisie du numero de Telephone Portable :"<<endl;
				char p[MAX];
				cin.getline(p,MAX);
				cin.getline(p,MAX);
				_proprietaire.setTelephonePortable(p);
				break;
			case 8:
				cout << "Saisie du numero de fax :"<<endl;
				char fax[MAX];
				cin.getline(fax,MAX);
				cin.getline(fax,MAX);
				_proprietaire.setFax(fax);
				break;
			case 9:
				cout << "Saisie de son E-Mail :"<<endl;
				char mail[MAX];
				cin.getline(mail,MAX);
				cin.getline(mail,MAX);
				_proprietaire.setEmail(mail);
				break;
			case 10:
				cout << "Saisie d'une adresse Web ou Blog :" << endl;
				char web[MAX];
				cin.getline(web,MAX);
				cin.getline(web,MAX);
				_proprietaire.setWeb(web);
				break;
			case 11:
				cout << "Saisie d'un commentaire ou d'une note :" << endl;
				char note[MAX];
				cin.getline(note,MAX);
				cin.getline(note,MAX);
				_proprietaire.setNote(note);
				break;
		}
	}
	while(choix != 0);
	cout << "sauv";
	sauvegarder();

}

void CSysteme :: sauvegarder(void) {

	ofstream sortie("Proprietaire.dat");
	sortie << _proprietaire ;
	sortie.close();

}

bool CSysteme :: charger(void) {

	ifstream entree("Proprietaire.dat");
	bool charger=true;
	char n[MAX];
	if (!entree) {
		cout << "Impossible de lire le fichier "<<endl;
		charger=false;
	}
	else {		
	entree.getline(n,MAX);
	entree >> _proprietaire;
	char tmp[MAX];
	if(strcmp(_proprietaire.getMotDePasse(tmp),"")==0)
		charger=false;
	}
	entree.close();

return charger;

}

/* Méthode d'affichage de l'aide sur la fonction Systeme */
void CSysteme :: aide() {
	entete();
	cout << "CorTex 2K5 -> Systeme -> Aide"<<endl;
	cout << "____________________________________________________________\n"<<endl;
	cout << "< Aide >"<<endl;
	cout << "La configuration du systeme se compose de 4 parties :"<<endl;
	cout << "\t - La premiere permet de definir le mot de passe."<<endl;
	cout << "\t - La seconde permet de definir les informations vous concernant."<<endl;
	cout << "\t - La troisieme permet de definir la couleur de fond du texte"<<endl;
	cout << "\t - La troisieme permet de definir la couleur du texte\n"<<endl;

	int chx;
	do {
	cout << "0) Retour au menu Systeme."<<endl;
	cin >> chx;
	if(chx!=0)
		cout << "Ce choix n'existe pas.";
	}
	while(chx!=0);
}