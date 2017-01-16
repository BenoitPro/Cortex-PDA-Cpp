/*******************************************
	CListeRendezVous.h : H�rite de CListe
	et apporte les m�thodes de recherche,
	sp�cifique � la gestion d'une liste de 
	CRendezVous
********************************************/

#include "CListe.cpp"
#include "CRendezVous.cpp"
class CListeRendezVous : public CListe<CRendezVous> {


public :

	/* M�thodes de recherche */
	bool rechercherParDate(char *,bool); 
	bool rechercherParType(char *,bool);

	/* Sauvegarde de la liste de rendez-vous */
	void sauvegarder(void);

	/* Chargement de la liste de rendez-vous */
	void charger(void);
};