/* CAideMemoire.h */

#include "CListe.cpp"
#include "CPenseBete.cpp"

class CAideMemoire {
private :
	CListe<CPenseBete> _liste;

public :
	CAideMemoire(void);
	void menu(void);
	void ajouter(void);
	void supprimer(void);
	void modifier(void);
	void afficher(void);

	void aide(void);

	void definirPenseBete(CPenseBete&,char *);

	void sauvegarderListe(void);
	void chargerListe(void);
};