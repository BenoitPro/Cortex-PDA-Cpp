#include "CListe.cpp"
#include "CNote.cpp"
#define MAX 255
class CBlockNote {
private :
	CListe<CNote> _liste;

public :
	CBlockNote(void);
	void menu(void);
	void ajouter(void);
	void supprimer(void);
	void modifier(void);
	void afficher(void);

	void aide(void);

	void definirNote(CNote &,char *);

	void sauvegarderListe(void);
	void chargerListe(void);
};