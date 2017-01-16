/********************************************
	CListeContact.h : Hérite de CListe
	et apporte les méthodes de recherche
	ainsi qu'une méthode statistique, spécifique 
	à la gestion d'une liste de CContact
  ********************************************/
#include "CListe.cpp"
#include "CContact.cpp"
class CListeContact : public CListe<CContact> {


public :
	/* Constructeur : Pas besoin.....*/

	/* Méthodes de recherche */
	bool rechercher(char *,bool); 		// recherche le nom ou le prenom
	void rechercher(char *,char *);
	void rechercherPseudo(char *);
	void rechercherType(char *);
	void rechercherTelephone(char *);

	/* Autres Méthodes */
	void statistiques(void); 			// Donne différentes statistiques sur la liste de contacts

	/* Sauvegarde de la liste de contact */
	void sauvegarder(void);

	/* Chargement de la liste de contact */
	void charger(void);
};