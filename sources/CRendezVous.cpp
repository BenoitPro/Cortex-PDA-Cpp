/***************************
		CRendezVous.cpp
	Gestion d'un rendez-vous
****************************/

#include <ostream.h>
#include <fstream.h>
#include <iostream.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "CRendezVous.h"


/* Constructeurs */ 
CRendezVous :: CRendezVous(void) { 
	_date = new CDate();
	_heureDeDebut= new CHeure();
	_heureDeFin= new CHeure();
	strcpy(_repetition,"");
	strcpy(_type,"");
	strcpy(_description,"");
}

CRendezVous :: CRendezVous(char * date,char * heureDeDebut) {
	_date = new CDate(date);
	_heureDeDebut = new CHeure(heureDeDebut);
	_heureDeFin = new CHeure();
	strcpy(_repetition,"");
	strcpy(_type,"");
	strcpy(_description,"");
}


// Les Getters
CDate* CRendezVous :: getDate() { return _date; }
CHeure* CRendezVous :: getHeureDeDebut() { return _heureDeDebut; }
CHeure* CRendezVous :: getHeureDeFin() { return _heureDeFin; }
char * CRendezVous :: getType(char * type) { strcpy(type,_type); return type ;}
char * CRendezVous :: getDescription(char * description) { strcpy(description,_description); return description; }

// Les Setters
void CRendezVous :: setDate(char * date) { _date= new CDate(date);}
void CRendezVous :: setHeureDeDebut(char * heureDeDebut) { _heureDeDebut = new CHeure(heureDeDebut); }
void CRendezVous :: setHeureDeFin(char * heureDeFin) {_heureDeFin = new CHeure(heureDeFin);}
void CRendezVous :: setType(char * type) { strcpy(_type,type) ; }
void CRendezVous :: setDescription(char * description) { strcpy(_description,description) ; }


// Surdéfinition de l'opérateur > pour l'ajout trié
bool CRendezVous :: operator> (CRendezVous &c) {
	if( *_date > *c.getDate()){
		cout<< "date> getD \n";
		return true;
	}
	else {
		if ( *_heureDeDebut > *c.getHeureDeDebut() )
			return true;
		else
			return false; // même horaire & date de rendez vous...
	}
	return false;
}


/* Redéfinition de l'opérateur>> pour le chargement */
ifstream& operator>> (ifstream& entree,CRendezVous& c) {	
	
	char da[MAX];char hd[MAX];char hf[MAX];char t[MAX] ;char d[MAX];
	
	entree.getline(da,MAX);
	entree.getline(hd,MAX);
	entree.getline(hf,MAX);	
	entree.getline(t,MAX);
	entree.getline(d,MAX);

	c.setDate(da);
	c.setHeureDeDebut(hd);
	c.setHeureDeFin(hf);
	c.setType(t);
	c.setDescription(d);

return entree;
}


/* Redéfinition de l'opérateur << pour l'affichage */
ostream& operator<< (ostream& o,CRendezVous c) {
	CDate *dateee = c.getDate();
	cout << "Date :\t\t"<< dateee->getJour()<<"/"<<dateee->getMois()<<"/"<<dateee->getAnnee()<<endl;

	CHeure *heured = c.getHeureDeDebut();
	if(heured->getHeure()!=-1)
		cout << "Heure de debut :"<< heured->getHeure()<<"h "<<heured->getMin()<<"min "<<endl;

	CHeure *heuref = c.getHeureDeFin();
	if(heuref->getHeure()!=-1)
		cout << "Heure de fin :\t"	<< heuref->getHeure()<<"h "<<heuref->getMin()<<"min "<<endl;

	char tmp[MAX];
	if(strcmp(c.getDescription(tmp),"") != 0) cout << "Description :\t" << c.getDescription(tmp)<< endl;
	if(strcmp(c.getType(tmp),"") != 0) cout << "Type :\t\t" << c.getType(tmp)<< endl;

return o;
}


