/**************************************
		CListeRendezVous.cpp
	Gestion de la liste de rendez-vous 
**************************************/

#include <string.h>		// pour strupr() et strcmp()
#include <iomanip.h>	// pour setw de statistique

#include "CListeRendezVous.h"


bool CListeRendezVous :: rechercherParDate(char * date,bool indice) {

	Noeud<CRendezVous> * tmp = new Noeud<CRendezVous>();
	tmp = _tete;
	CRendezVous obj ;

	char *dateObj;	//date qu'on recupére de l'objet courant

	char tmpS[MAX];
	CDate *d;
	obj = tmp->getObjet();
	bool trouve = false;
	int cpt=0; 

	while(tmp != NULL ){
		obj = tmp->getObjet();
		d = obj.getDate();
		dateObj = d->getDateS(tmpS);
		if( strcmp(dateObj,date) == 0 && taille()>0){
			if(indice)
				cout << "Id : "<<cpt<<endl;
			cout << obj <<endl;
			trouve = true;
		}
		tmp = tmp->getSuiv();
		cpt++;
	}

	if(!trouve)
		cout << "Aucun resultats trouve pour la date : "<< date << endl;
	return trouve;
}

/* Recherche par Type */
bool CListeRendezVous :: rechercherParType(char * type,bool indice) {
	
	type=strupr(type);
	Noeud<CRendezVous> * tmp = new Noeud<CRendezVous>();

	tmp = _tete;
	CRendezVous obj ;
	char nomObj[MAX]; 
	obj = tmp->getObjet();
	
	bool trouve = false;

	while(tmp != NULL ){
		obj = tmp->getObjet();
		if ( strcmp(strupr(obj.getType(nomObj)),type) == 0 ) {  
			cout << "\n-----------------------------\n" << obj;
			trouve = true;
		}
		tmp = tmp->getSuiv();
	}
	if(!trouve)
		cout << "Aucun resultat trouve pour le type : "<< type<<endl; 
	
	return trouve;
}


/* Sauvegarder */
void CListeRendezVous :: sauvegarder(void) {

}


/* Charger */
void CListeRendezVous :: charger(void) {

}

