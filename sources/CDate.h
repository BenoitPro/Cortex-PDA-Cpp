/**************
	CDate.h 
***************/
#define MAX 255

class CDate {
private :
	int _annee;
	int _mois;
	int _jour;
	char _dateS[11];	

public :
	CDate();
	CDate(char *);				// prend en paramètre la date sous la forme fourni par l'utilisateur (char * : jj mm aaaa)
	
	/* Méthodes */
	bool bissextile(int);		// retourne vrai si l'année donnée en paramètre est bissextile
	bool verifierDate(char *);	// vérifie si la date donnée existe
	void recupererDate(char *);	// récupere l'année le mois et le jour a partir du char * fournit
		
	// Les Getters
	int getAnnee();
	int getMois();
	int getJour();
	char * getDateS(char *);
	
	// Les Setters
	void setAnnee(int);
	void setMois(int);
	void setJour(int);

	// Surdéfinition de l'opérateur > pour l'ajout trié
	bool operator > (CDate &) ;
	
	bool egalite(char*);


};