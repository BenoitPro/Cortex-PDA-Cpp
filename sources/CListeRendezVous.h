/*******************************************
	CListeRendezVous.h : Hérite de CListe
	et apporte les méthodes de recherche,
	spécifique à la gestion d'une liste de 
	CRendezVous
********************************************/

#include "CListe.cpp"
#include "CRendezVous.cpp"
class CListeRendezVous : public CListe<CRendezVous> {


public :

	/* Méthodes de recherche */
	bool rechercherParDate(char *,bool); 
	bool rechercherParType(char *,bool);

	/* Sauvegarde de la liste de rendez-vous */
	void sauvegarder(void);

	/* Chargement de la liste de rendez-vous */
	void charger(void);
};