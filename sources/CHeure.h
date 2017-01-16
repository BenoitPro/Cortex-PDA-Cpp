#define MAX 255

class CHeure {
private :
	int _heure;
	int _min;

public :
	CHeure(void);
	CHeure(char *);					// prend en paramètre la date sous la forme fourni par l'utilisateur (char * : jj mm aaaa)
	
	/* Méthodes */
	bool verifierHeureC(char *);	// vérifie si l'heure donnée existe
	void recupererHeureC(char *);	// récupere l'heure et les minutes à partir du char * fournit
		
	// Les Getters
	int getHeure();
	int getMin();

	// Les Setters
	void setHeure(int);
	void setMin(int);

	// Surdéfinition de l'opérateur > pour l'ajout trié
	bool operator > (CHeure &) ;
};
