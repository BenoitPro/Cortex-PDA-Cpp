/*********************************************
				CAgenda 
		Gère la liste de rendez-vous
 de l'utilisateur, grâce à la CListeRendezVous
**********************************************/

#include "CListeRendezVous.cpp"

class CAgenda {
private :
	CListeRendezVous _listeRendezVous;

public :
	CAgenda(void);
	void menu(void) ;
	void afficher(void);
	void afficherJour(void);
	void afficherDate(void);
	void afficherTous(void);
	void ajouter(void);
	void rechercher(void);
	void supprimer(void);
	void modifier(void);
	void aide(void);
	void definirRendezVous(CRendezVous &,char *);
	void sauvegarderListe(void);
	void chargerListe(void);
};