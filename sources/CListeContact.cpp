/*******************************
		  CListeContact
Gere une liste d'objet CContact
	  et herite de CListe
********************************/


#include "CListeContact.h"
#include <string.h>  // pour strupr() et strcmp()
#include <iomanip.h> // pour setw de statistique

bool CListeContact :: rechercher(char * nom,bool indice){
	nom=strupr(nom); // on met le nom(ou prenom) en majuscule

	Noeud<CContact> * tmp = new Noeud<CContact>();
	tmp = _tete;
	CContact obj ;
	char nomObj[MAX];
	obj = tmp->getObjet();
	bool trouve = false;
	int cpt=0; 

	while(tmp != NULL ){

		obj = tmp->getObjet();
		
		if( (strcmp(strupr(obj.getNom(nomObj)),nom) == 0) || (strcmp(strupr(obj.getPrenom(nomObj)),nom) == 0) ) {
			if (indice)cout << "\n-----------------------------\n" << "Id : "<<cpt<<endl;
			cout << obj <<endl;
				trouve = true;
	}		
		tmp = tmp->getSuiv();
		cpt++;
	}
	if(!trouve)
		cout << "Aucun resultats trouve pour : "<< nom <<endl; 
	return trouve;
}

void CListeContact :: rechercher(char * nom,char * prenom) {

	nom=strupr(nom);
	prenom=strupr(prenom);
	Noeud<CContact> * tmp = new Noeud<CContact>();
	tmp = _tete;
	CContact obj ;
	char nomObj[MAX]; 
	obj = tmp->getObjet();
	bool trouve = false;

	while(tmp != NULL ){
		

		obj = tmp->getObjet();

		if( (strcmp(strupr(obj.getNom(nomObj)),nom) == 0) && (strcmp(strupr(obj.getPrenom(nomObj)),prenom) == 0) ) {
			cout << "\n-----------------------------\n" << obj;
			trouve = true;
		}
		tmp = tmp->getSuiv();
	}
	if(!trouve)
		cout << "Aucun resultats trouve pour : "<< nom << " " << prenom << endl; 

}

void CListeContact :: rechercherPseudo(char * pseudo) {
	
	pseudo=strupr(pseudo);

	Noeud<CContact> * tmp = new Noeud<CContact>();

	tmp = _tete;
	CContact obj ;
	char nomObj[MAX]; 
	obj = tmp->getObjet();
	bool trouve = false;
	while(tmp != NULL ){
		obj = tmp->getObjet();
		if ( strcmp(strupr(obj.getPseudo(nomObj)),pseudo) == 0 ) {  
			cout << "\n-----------------------------\n" << obj;
			trouve = true;
		}
		tmp = tmp->getSuiv();
	}
	if(!trouve)
		cout << "Aucun resultats trouve pour : "<< pseudo<<endl; 
}

void CListeContact :: rechercherType(char * type) {
	type=strupr(type);
	Noeud<CContact> * tmp = new Noeud<CContact>();
	tmp = _tete;
	CContact obj ;
	char nomObj[MAX]; 
	obj = tmp->getObjet();
	bool trouve = false;
	while(tmp != NULL ){
		obj = tmp->getObjet();
		if ( strcmp(strupr(obj.getType(nomObj)),type) == 0 ) { 
			cout << "\n-----------------------------\n" << obj;
			trouve=true;
		}
		tmp = tmp->getSuiv();
	}
	if(!trouve)
		cout << "Aucun resultat trouve pour : "<< type<<endl; 
}


/** Méthode de recherche de contact par numéro de telephone **/
void CListeContact :: rechercherTelephone(char * tel) {
	tel=strupr(tel);
	Noeud<CContact> * tmp = new Noeud<CContact>();
	tmp = _tete;
	CContact obj ;
	char nomObj[MAX]; 
	obj = tmp->getObjet();
	bool trouve = false;

	while(tmp != NULL ){
		obj = tmp->getObjet();
		if ( strcmp(strupr(obj.getTelephone(nomObj)),tel) == 0 ) { 
			cout << "\n-----------------------------\n" << obj;
			trouve=true;
		}
		tmp = tmp->getSuiv();
	}
	if(!trouve)
		cout << "Aucun resultat trouve."<<endl; 
}

void CListeContact :: statistiques() {
	if (!estVide()) {

	int nbAmi=0, nbCollegue=0,nbFamille=0, nbAutre=0, nbIndefinie=0 ;
	
	Noeud<CContact> * tmp = new Noeud<CContact>();
	tmp = _tete;
	CContact obj ;
	
	char ami[10]="Ami(e)" ;
	char collegue[10]="Collegue" ;
	char famille[10]="Famille" ;
	char indefinie[10]="" ;

	char type[MAX] ;

	while(tmp != NULL) {
			obj = tmp->getObjet();
			obj.getType(type);
			if ( strcmp(type,ami) == 0)
				nbAmi++;
			else if ( strcmp(type,collegue) == 0)
				nbCollegue++;
			else if ( strcmp(type,famille) == 0)
				nbFamille++;
			else if ( strcmp(type,indefinie) == 0)
				nbIndefinie++;
			else
				nbAutre++;

			tmp=tmp->getSuiv();

		}
	cout << "Il y a " << taille() << " contact(s) dans le repertoire."<<endl;
	cout << "\nDetails sur les  differents type de contact : \n" <<endl;
	cout << setw(17) <<"Ami(e)(s) : "    <<   setw(2)  << nbAmi       << " soit "<< setw(2) << (((double) nbAmi/taille())        * 100 ) << " %."    <<  endl; 
	cout << setw(17) <<"Collegue(s)  : " <<   setw(2)  << nbCollegue  << " soit "<< setw(2) << (((double) nbCollegue/taille())   * 100 ) << " %."<<  endl; 
	cout << setw(17) <<"Famille : "      <<   setw(2)  << nbFamille   << " soit "<< setw(2) << (((double)  nbFamille/taille())   * 100 ) << " %."  <<  endl; 
	cout << setw(17) <<"Autre : "        <<   setw(2)  << nbAutre     << " soit "<< setw(2) << (((double)  nbAutre/taille())     * 100 ) << " %."    <<  endl; 
	cout << setw(17) <<"Indefinie : "    <<   setw(2)  << nbIndefinie << " soit "<< setw(2) << (((double)  nbIndefinie/taille()) * 100 ) << " %."<<  endl; 
	}
	else 
		cout << "Il n'y a pas de contact dans le repertoire\n" ; 
}


void CListeContact :: sauvegarder(void) {
	if(!estVide()) {
		Noeud<CContact> * tmp ;
		ofstream sortie("ListeContact.dat");
		tmp = _tete ;
		while(tmp != NULL ) {
			CContact c ;
			c = tmp->getObjet();
			sortie << c;
			tmp = tmp->getSuiv();
		}
		sortie.close();
	}
}

void CListeContact :: charger(void) {

	ifstream entree("ListeContact.dat");
	char n[MAX];
	if (!entree) {
		cout << "Impossible de lire le fichier "<<endl;
	}
	else {		
	entree.getline(n,MAX);
		while ( entree.eof()==0 ) {
		CContact c;	
		entree >> c;
		ajoutTrie(c);
		}
	entree.close();
	}
}