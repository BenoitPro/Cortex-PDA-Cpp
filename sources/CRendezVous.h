/* CRendezVous.h : D�finition d'un objet CRendezVous */
#define MAX 255
#include "CDate.cpp"
#include "CHeure.cpp"

class CRendezVous {

private :
	/* Variables de classe */
	// Ces deux variables doivent �tre donn�es pour cr�er un objet CRendezVous
	CDate *_date; 
	CHeure *_heureDeDebut;

	// Variables facultatives
	CHeure *_heureDeFin;
	char _repetition[MAX];		// tous les jours, jour de la semaine, mois, ans.
	char _type[MAX];			// anniversaire (repetition ann�e automatique), rendez-vous, r�union, �v�nement, cong�, d�placement,autre.
	char _description[MAX] ;	// description du rendez (lieu etc...)

public :
	/* Constructeurs */
	CRendezVous(void);
	CRendezVous(char * date,char * heureDeDebut) ;

	/* M�thodes */
	// Les Getters
	CDate * getDate();
	CHeure* getHeureDeDebut();
	CHeure* getHeureDeFin();
	char * getType(char *);
	char * getDescription(char *);

	// Les Setters
	void setDate(char *);
	void setHeureDeDebut(char *);
	void setHeureDeFin(char *);
	void setType(char *);
	void setDescription(char *);
	
	// Surd�finition de l'op�rateur > pour l'ajout tri�
	bool operator > (CRendezVous &) ;

	// Red�finition de l'op�rateur << pour l'affichage
	friend ostream& operator<<(ostream&,CRendezVous);	
	
};