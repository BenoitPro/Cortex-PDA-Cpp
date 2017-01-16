/**********************************
		CContact.cpp
	Gestion d'un contact
(nom,prenom,date de naissance, etc)
***********************************/
#include "CContact.h"
#include <iostream.h>
#include <string.h>

/* Constructeurs */ 
CContact :: CContact(void) { // constructeur par defaut
	strcpy(_nom,"");
	strcpy(_prenom,"");
	strcpy(_pseudo,"");
	strcpy(_telephone,"");
	strcpy(_fax,"");
	strcpy(_naissance,"");
	strcpy(_adresse,"");
	strcpy(_email,"");
	strcpy(_web,"");
	strcpy(_type,"");
	strcpy(_note,"");
}

CContact :: CContact(char * nom,char * prenom) {
	strcpy(_nom,nom);
	strcpy(_prenom,prenom);
	strcpy(_pseudo,"");
	strcpy(_telephone,"");
	strcpy(_fax,"");
	strcpy(_naissance,"");
	strcpy(_adresse,"");
	strcpy(_email,"");
	strcpy(_web,"");
	strcpy(_type,"");
	strcpy(_note,"");
}

/* Méthodes */
// Les Getters
char * CContact :: getNom(char * nom) { strcpy(nom,_nom); return nom; }
char * CContact :: getPrenom(char * prenom) { strcpy(prenom,_prenom); return prenom; }
char * CContact :: getPseudo(char * pseudo) { strcpy(pseudo,_pseudo); return pseudo; }
char * CContact :: getTelephone(char * telephone) {strcpy(telephone,_telephone); return telephone; }
char * CContact :: getFax(char * fax) { strcpy(fax,_fax); return fax ;}
char * CContact :: getNaissance(char * naissance) { strcpy(naissance,_naissance); return naissance; }
char * CContact :: getAdresse(char * adresse) { strcpy(adresse,_adresse); return adresse; }
char * CContact :: getEmail(char * email) { strcpy(email,_email); return email; }
char * CContact :: getWeb(char * web) { strcpy(web,_web); return web; }
char * CContact :: getType(char * type) { strcpy(type,_type); return type; }
char * CContact :: getNote(char * note) { strcpy(note,_note); return note; } 

// Les Setters
void CContact :: setNom(char * nom) { strcpy(_nom,nom) ; }
void CContact :: setPrenom(char * prenom) { strcpy(_prenom,prenom) ; }
void CContact :: setPseudo(char * pseudo) { strcpy(_pseudo,pseudo) ; }
void CContact :: setTelephone(char * telephone) { strcpy(_telephone,telephone) ; }
void CContact :: setFax(char * fax) { strcpy(_fax,fax) ; }
void CContact :: setNaissance(char * naissance) { strcpy(_naissance,naissance) ; }
void CContact :: setAdresse(char * adresse) { strcpy(_adresse,adresse) ; }
void CContact :: setEmail(char * email) { strcpy(_email,email) ; }
void CContact :: setWeb(char * web) { strcpy(_web,web) ; }
void CContact :: setType(char * type) { strcpy(_type,type) ; }
void CContact :: setNote(char * note) { strcpy(_note,note) ; }


// Surdéfinition de l'opérateur > pour l'ajout trié
bool CContact :: operator> (CContact c) {
	char tmp1[255],tmp2[255],tmp3[255];
	
	strcpy(tmp1,_nom); 
	
	char * mot1 = strcat(tmp1,_prenom);
	char * mot2 = strcat( c.getNom(tmp2),c.getPrenom(tmp3) );
	strupr(mot1);
	strupr(mot2);
	return (strcmp(mot1,mot2)>0);
}

// Redéfinition de l'opérateur>> pour le chargement
ifstream& operator>> (ifstream& entree,CContact& c) {	
	
	char n[MAX] ;char p[MAX] ;char t[MAX] ;char ps[MAX] ;char tel[MAX] ;char f[MAX] ;
	char na[MAX] ;char ad[MAX] ;char e[MAX] ;char w[MAX] ;char note[MAX] ;
	
	entree.getline(n,MAX);
	entree.getline(p,MAX);
	entree.getline(t,MAX);	
	entree.getline(ps,MAX);
	entree.getline(tel,MAX);
	entree.getline(f,MAX);
	entree.getline(na,MAX);
	entree.getline(ad,MAX);
	entree.getline(e,MAX);
	entree.getline(w,MAX);
	entree.getline(note,MAX);


	c.setNom(n);
	c.setPrenom(p);
	c.setType(t);
	c.setPseudo(ps);
	c.setTelephone(tel);
	c.setFax(f);
	c.setEmail(na);
	c.setAdresse(ad);
	c.setWeb(e);
	c.setWeb(w);
	c.setNote(note);

return entree;
}

// Redéfinition de l'opérateur << pour l'affichage
ostream& operator<< (ostream& o,CContact c) {
	char tmp[MAX];
	
	if(strcmp(c.getNom(tmp),"") != 0) cout << "Nom : \t\t\t" << c.getNom(tmp) << endl;
	if(strcmp(c.getPrenom(tmp),"") != 0) cout << "Prenom : \t\t" << c.getPrenom(tmp) << endl;
	if(strcmp(c.getType(tmp),"") != 0) cout << "Type : \t\t\t" << c.getType(tmp) << endl;
	if(strcmp(c.getPseudo(tmp),"") != 0) cout << "Pseudo : \t\t" << c.getPseudo(tmp) << endl;
	if(strcmp(c.getTelephone(tmp),"") != 0) cout << "Telephone : \t\t" << c.getTelephone(tmp) << endl;
	if(strcmp(c.getFax(tmp),"") != 0) cout << "Fax : \t\t" << c.getFax(tmp) << endl;
	if(strcmp(c.getNaissance(tmp),"") != 0) cout << "Date de naissance : \t\t" << c.getNaissance(tmp) <<endl;
	if(strcmp(c.getAdresse(tmp),"") != 0) cout << "Adresse : \t\t" << c.getAdresse(tmp) <<endl;
	if(strcmp(c.getEmail(tmp),"") != 0) cout << "E-mail : \t\t" << c.getEmail(tmp) <<endl;
	if(strcmp(c.getWeb(tmp),"") != 0) cout << "Adresse web ou blog : \t" << c.getWeb(tmp) <<endl;
	if(strcmp(c.getNote(tmp),"") != 0) cout << "Note ou commentaires : \t\t" << c.getNote(tmp) <<endl;

return o;
}


// Redéfinition de l'opérateur << pour la sauvegarde
ofstream& operator<< (ofstream& sortie,CContact c) {
	sortie << "\n" << c._nom ;
	sortie << "\n" << c._prenom ;
	sortie << "\n" << c._type ;
	sortie << "\n" << c._pseudo ;
	sortie << "\n" << c._telephone;
	sortie << "\n" << c._fax ;
	sortie << "\n" << c._naissance ;
	sortie << "\n" << c._adresse ;
	sortie << "\n" << c._email ;
	sortie << "\n" << c._web ;
	sortie << "\n" << c._note ;
return sortie;
}

