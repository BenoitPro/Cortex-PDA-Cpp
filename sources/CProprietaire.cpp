/***********************************
		CProprietaire.cpp
Définit les champs d'un propriétaire
************************************/

#include "CProprietaire.h"
#include <iostream.h>
#include <string.h>

/* Constructeur */
CProprietaire :: CProprietaire(void) {
	strcpy(_mot_de_passe,""); 
	strcpy(_pseudo,"");
	strcpy(_nom,"");
	strcpy(_prenom,"");
	strcpy(_adresse1,"");
	strcpy(_adresse2,"");
	strcpy(_telephoneFixe,"");
	strcpy(_telephonePortable,"");
	strcpy(_fax,"");
	strcpy(_email,"");
	strcpy(_web,"");
	strcpy(_note,"");
}

/* Getters */
char * CProprietaire :: getMotDePasse(char * v)       { strcpy(v,_mot_de_passe) ; return v; }
char * CProprietaire :: getPseudo(char * v)           { strcpy(v,_pseudo) ; return v; }
char * CProprietaire :: getNom(char * v)              { strcpy(v,_nom) ; return v; }
char * CProprietaire :: getPrenom(char * v)           { strcpy(v,_prenom) ; return v; }
char * CProprietaire :: getAdresse1(char * v)         { strcpy(v,_adresse1) ; return v; }
char * CProprietaire :: getAdresse2(char * v)         { strcpy(v,_adresse2) ; return v; }
char * CProprietaire :: getTelephoneFixe(char * v)    { strcpy(v,_telephoneFixe) ; return v; }
char * CProprietaire :: getTelephonePortable(char * v){ strcpy(v,_telephonePortable) ; return v; }
char * CProprietaire :: getFax(char * v)              { strcpy(v,_fax) ; return v; }
char * CProprietaire :: getEmail(char * v)            { strcpy(v,_email) ; return v; }
char * CProprietaire :: getWeb(char * v)              { strcpy(v,_web) ; return v; }
char * CProprietaire :: getNote(char * v)             { strcpy(v,_note) ; return v; }


char * CProprietaire :: getCouleurFond(char * v)      { strcpy(v,_couleurFond) ; return v; }
char * CProprietaire :: getCouleurTexte(char * v)     { strcpy(v,_couleurTexte) ; return v; }

/* Setters */
void  CProprietaire :: setMotDePasse(char * v)        { strcpy(_mot_de_passe,v); }
void  CProprietaire :: setPseudo(char * v)            { strcpy(_pseudo,v); }
void  CProprietaire :: setNom(char * v)               { strcpy(_nom,v); }
void  CProprietaire :: setPrenom(char * v)            { strcpy(_prenom,v); }
void  CProprietaire :: setAdresse1(char * v)          { strcpy(_adresse1,v); }
void  CProprietaire :: setAdresse2(char * v)          { strcpy(_adresse2,v); }
void  CProprietaire :: setTelephoneFixe(char * v)     { strcpy(_telephoneFixe,v); }
void  CProprietaire :: setTelephonePortable(char * v) { strcpy(_telephonePortable,v); }
void  CProprietaire :: setFax(char * v)               { strcpy(_fax,v); }
void  CProprietaire :: setEmail(char * v)             { strcpy(_email,v); }
void  CProprietaire :: setWeb(char * v)               { strcpy(_web,v); }
void  CProprietaire :: setNote(char * v)              { strcpy(_note,v); }

void CProprietaire :: setCouleurFond(char * v)        { strcpy(_couleurFond,v); }
void CProprietaire :: setCouleurTexte(char * v)       {  strcpy(_couleurTexte,v); }

// Redéfinition de l'opérateur << pour l'affichage
ostream& operator<< (ostream& o,CProprietaire c) {
	char tmp[MAX];
	
	if(strcmp(c.getNom(tmp),"") != 0) cout << "Nom : " << c.getNom(tmp) <<endl;
	if(strcmp(c.getPrenom(tmp),"") != 0) cout << "Prenom : " << c.getPrenom(tmp) <<endl;
	if(strcmp(c.getPseudo(tmp),"") != 0) cout << "Pseudo : " << c.getPseudo(tmp) <<endl;
	if(strcmp(c.getAdresse1(tmp),"") != 0) cout << "Adresse 1 : " << c.getAdresse1(tmp) <<endl;
	if(strcmp(c.getAdresse2(tmp),"") != 0) cout << "Adresse 2 : " << c.getAdresse2(tmp) << endl;
	if(strcmp(c.getTelephoneFixe(tmp),"") != 0) cout << "Telephone Fixe : " << c.getTelephoneFixe(tmp) << endl;
	if(strcmp(c.getTelephonePortable(tmp),"") != 0) cout << "Telephone portable : " << c.getTelephonePortable(tmp) <<endl;
	if(strcmp(c.getFax(tmp),"") != 0) cout << "Fax : " << c.getFax(tmp) <<endl;
	if(strcmp(c.getEmail(tmp),"") != 0) cout << "E-mail : " << c.getEmail(tmp) <<endl;
	if(strcmp(c.getWeb(tmp),"") != 0) cout << "Adresse web ou blog : " << c.getWeb(tmp) <<endl;
	if(strcmp(c.getNote(tmp),"") != 0) cout << "Note ou commentaires : " << c.getNote(tmp) <<endl;

return o;
}

// Redéfinition de l'opérateur>> pour le chargement
ifstream& operator>> (ifstream& entree,CProprietaire& p) {	
	
	char mdp[MAX]; char n[MAX] ;char pr[MAX] ;char ps[MAX] ;char ad1[MAX] ;char ad2[MAX] ;char telf[MAX] ;
	char telp[MAX] ;char fax[MAX] ;char mail[MAX] ;char web[MAX] ;char note[MAX] ;
	
	entree.getline(mdp,MAX);
	entree.getline(n,MAX);
	entree.getline(pr,MAX);
	entree.getline(ps,MAX);	
	entree.getline(ad1,MAX);
	entree.getline(ad2,MAX);
	entree.getline(telf,MAX);
	entree.getline(telp,MAX);
	entree.getline(fax,MAX);
	entree.getline(mail,MAX);
	entree.getline(web,MAX);
	entree.getline(note,MAX);

	p.setMotDePasse(mdp);
	p.setNom(n);
	p.setPrenom(pr);
	p.setAdresse1(ad1);
	p.setAdresse2(ad2);
	p.setTelephoneFixe(telf);
	p.setTelephonePortable(telp);
	p.setFax(fax);
	p.setEmail(mail);
	p.setWeb(web);
	p.setNote(note);

return entree;
}
// Redéfinition de l'opérateur << pour la sauvegarde
ofstream& operator<< (ofstream& sortie,CProprietaire p) {
	char tmp[MAX];

	sortie << "\n" << p.getMotDePasse(tmp) ;
	sortie << "\n" << p.getNom(tmp) ;
	sortie << "\n" << p.getPrenom(tmp) ;
	sortie << "\n" << p.getPseudo(tmp) ;
	sortie << "\n" << p.getAdresse1(tmp) ;
	sortie << "\n" << p.getAdresse2(tmp);
	sortie << "\n" << p.getTelephoneFixe(tmp) ;
	sortie << "\n" << p.getTelephonePortable(tmp) ;
	sortie << "\n" << p.getFax(tmp) ;
	sortie << "\n" << p.getEmail(tmp);
	sortie << "\n" << p.getWeb(tmp);
	sortie << "\n" << p.getNote(tmp) ;
return sortie;
}