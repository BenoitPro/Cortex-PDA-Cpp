/************************************
	             CRepertoire.h
	     Gère la liste de contacts 
 de l'utilisateur, grâce à la CListeContact.
************************************/

#include "CListeContact.cpp"

class CRepertoire {
private :
	CListeContact _listeContact ;

public :
	CRepertoire(void);
	void menu(void) ;
	void afficher(void);
	void ajouter(void);
	void supprimer(void);
	void modifier(void);
	void rechercher(void);
	void statistiques(void);
	void aide(void);

	void definirContact(CContact &,char *);

	void sauvegarderListe(void);
	void chargerListe(void);

};