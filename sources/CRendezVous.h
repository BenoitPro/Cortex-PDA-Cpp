/* CRendezVous.h : Définition d'un objet CRendezVous */
#define MAX 255
#include "CDate.cpp"
#include "CHeure.cpp"

class CRendezVous {

private :
	/* Variables de classe */
	// Ces deux variables doivent être données pour créer un objet CRendezVous
	CDate *_date; 
	CHeure *_heureDeDebut;

	// Variables facultatives
	CHeure *_heureDeFin;
	char _repetition[MAX];		// tous les jours, jour de la semaine, mois, ans.
	char _type[MAX];			// anniversaire (repetition année automatique), rendez-vous, réunion, évènement, congé, déplacement,autre.
	char _description[MAX] ;	// description du rendez (lieu etc...)

public :
	/* Constructeurs */
	CRendezVous(void);
	CRendezVous(char * date,char * heureDeDebut) ;

	/* Méthodes */
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
	
	// Surdéfinition de l'opérateur > pour l'ajout trié
	bool operator > (CRendezVous &) ;

	// Redéfinition de l'opérateur << pour l'affichage
	friend ostream& operator<<(ostream&,CRendezVous);	
	
};