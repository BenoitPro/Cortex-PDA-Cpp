/***************************
		CDate.cpp
	Gestion d'une date 
****************************/

#include "CDate.h"
#include <string.h>
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/** Constructeur **/
CDate :: CDate () {
	_annee=-1;
	_mois=-1;
	_jour=-1;
}

/** Constructeur avec argument **/
CDate :: CDate(char * date){
	//Recopie de la date dans dateTmp
	char dateTmp[MAX];
	for (int i=0; i<10;i++){
		dateTmp[i]=date[i];
		_dateS[i]=date[i];	//sauvegarde de la date sous forme d'un string pour CListeR
	}
	dateTmp[10]='\0';
	_dateS[10]='\0';
	recupererDate(dateTmp);
	do {
		if (!verifierDate(dateTmp) ){
			if(strcmp(dateTmp,"")!=0)
				cout<<"\""<<dateTmp<<"\" n'est pas une date valide, veuillez saisir une nouvelle date :\n"<< flush;
			cin.getline(dateTmp,MAX);
			recupererDate(dateTmp);
		}
	}
	while(!verifierDate(dateTmp));	
}


/** V�rifie si l'ann�e donn� en param�tre est bissextile ou non **/
bool CDate::bissextile(int annee) {
	if (annee%4!=0 || annee%400==0)
		return false;
	else
		return true;
}


/** V�rification de la validit� de la date **/
bool CDate::verifierDate(char * date){
	bool dateValide=true;
	if (strlen(date)>10 || strlen(date)<10) 
		dateValide=false;
	else {
		if ( _jour<1 || ((_jour>31 && (_mois==1 ||_mois==3 ||_mois==5 ||_mois==7 ||_mois==8 ||_mois==10 ||_mois==12))   ||  (_jour>30 && (_mois==2 || _mois==4 || _mois==6 || _mois==9 || _mois==11))    || (_jour>29 && bissextile(_annee) && _mois==2)   ||   (_jour>28 && !bissextile(_annee) && _mois==2) ) )
			dateValide=false;
		if ( _mois>12 || _mois<1 || _annee<1 || _annee>4000)
			dateValide=false;
	}
	return dateValide;
}


/** R�cup�ration du jour mois et ann�e � partir du char *date **/
void CDate::recupererDate(char *date){
	char tmp[3];
	int i;

	//R�cup�ration et transtypage du jour
	for (i=0; i<2;i++)
		tmp[i]=date[i];
	tmp[2]='\0';
	_jour= atoi(tmp);

	//R�cup�ration et transtypage du mois
	for (i=3; i<5;i++)
		tmp[i-3]=date[i];
	tmp[2]='\0';
	_mois= atoi(tmp);	

	//R�cup�ration et transtypage de l'ann�e
	char tmp2[5];
	for (i=6; i<10;i++)
		tmp2[i-6]=date[i];
	tmp2[4]='\0';
	_annee= atoi(tmp2);
}


/** Les Getters **/
int CDate :: getAnnee() { return _annee; }
int CDate :: getMois() { return _mois ; }
int CDate :: getJour() { return _jour ; }
char * CDate :: getDateS(char * dateS) { strcpy(dateS,_dateS); return dateS; }


/** Les Setters **/
void CDate :: setAnnee(int annee) { _annee=annee; }
void CDate :: setMois(int mois) { _mois=mois ; }
void CDate :: setJour(int jour) { _jour=jour ; }



/** Surd�finition de l'op�rateur > **/
bool CDate :: operator> (CDate &c) {
	if (_annee>c.getAnnee() ){
		return true;
	}
	else if (_annee<c.getAnnee()){
		return false;
	}
	else {
		if (_mois>c.getMois() )
			return true;
		else if (_mois<c.getMois())
			return false;
		else {
			if (_jour>c.getJour() )
				return true;
			else if (_jour<c.getJour())
				return false;
			else return false; //les dates sont �gales
		}
	}	
	return false; // par defaut
}

/** V�rifie si deux date sont �gale **/
bool CDate:: egalite(char * date){

	if (strcmp(_dateS,date)==0) 
		return true;
	return false;
}