/********************************************
	CListeContact.h : H�rite de CListe
	et apporte les m�thodes de recherche
	ainsi qu'une m�thode statistique, sp�cifique 
	� la gestion d'une liste de CContact
  ********************************************/
#include "CListe.cpp"
#include "CContact.cpp"
class CListeContact : public CListe<CContact> {


public :
	/* Constructeur : Pas besoin.....*/

	/* M�thodes de recherche */
	bool rechercher(char *,bool); 		// recherche le nom ou le prenom
	void rechercher(char *,char *);
	void rechercherPseudo(char *);
	void rechercherType(char *);
	void rechercherTelephone(char *);

	/* Autres M�thodes */
	void statistiques(void); 			// Donne diff�rentes statistiques sur la liste de contacts

	/* Sauvegarde de la liste de contact */
	void sauvegarder(void);

	/* Chargement de la liste de contact */
	void charger(void);
};