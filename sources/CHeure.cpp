/******************************
		CHeure.cpp
  Gestion de l'heure complète
		(heureC)
*******************************/


#include <string.h>
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "CHeure.h"


/** Constructeur **/
CHeure :: CHeure (void) {
	_heure=-1;
	_min=-1;
}

/** Constructeur avec argument **/
CHeure :: CHeure(char * heureC){

	//Recopie de la heureC dans heureCTmp
	char heureCTmp[MAX];
	for (int i=0; i<10;i++)
		heureCTmp[i]=heureC[i];
	heureCTmp[10]='\0';

	recupererHeureC(heureCTmp);
	do {
		if (!verifierHeureC(heureCTmp)){
			if(strcmp(heureCTmp,"!")!=0)
				cout<<"\""<<heureCTmp<<"\" n'est pas une heure valide, veuillez saisir une nouvelle heure :\n"<< flush;
			cin.getline(heureCTmp,MAX);
			recupererHeureC(heureCTmp);
		}
	}
	while(!verifierHeureC(heureCTmp));	
}


/** Vérification de la validité de l'heureC **/
bool CHeure::verifierHeureC(char * heureC){
	bool heureCValide=true;

	if (strlen(heureC)>5 || strlen(heureC)<5) 
		heureCValide=false;
	else if ( _heure>23 || _min>59 || _heure<0 || _min<0) 
			heureCValide=false;
	return heureCValide;
}


/** Récupération de l'heure et des minutes à partir du char *heureC **/
void CHeure::recupererHeureC(char *heureC){
	char tmp[3];
	int i;

	//Récupération et transtypage de l'heure
	for (i=0; i<2;i++)
		tmp[i]=heureC[i];
	tmp[2]='\0';
	_heure= atoi(tmp);

	//Récupération et transtypage des minutes
	for (i=3; i<5;i++)
		tmp[i-3]=heureC[i];
	tmp[2]='\0';
	_min= atoi(tmp);	
}


/** Les Getters **/
int CHeure :: getHeure() { return _heure; }
int CHeure :: getMin() { return _min ; }


/** Les Setters **/
void CHeure :: setHeure(int heure) { _heure=heure; }
void CHeure :: setMin(int min) { _min=min ; }


/** Surdéfinition de l'opérateur > **/
bool CHeure :: operator> (CHeure &c) {

	if (_heure>c.getHeure() )
		return true;
	else if (_heure<c.getHeure())
		return false;
	else {
		if (_min>c.getMin() )
			return true;
		else if (_min<c.getMin())
			return false;
		else return false; //les heureC sont égales
	}

	return false; // par defaut
}
