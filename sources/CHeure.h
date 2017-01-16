#define MAX 255

class CHeure {
private :
	int _heure;
	int _min;

public :
	CHeure(void);
	CHeure(char *);					// prend en param�tre la date sous la forme fourni par l'utilisateur (char * : jj mm aaaa)
	
	/* M�thodes */
	bool verifierHeureC(char *);	// v�rifie si l'heure donn�e existe
	void recupererHeureC(char *);	// r�cupere l'heure et les minutes � partir du char * fournit
		
	// Les Getters
	int getHeure();
	int getMin();

	// Les Setters
	void setHeure(int);
	void setMin(int);

	// Surd�finition de l'op�rateur > pour l'ajout tri�
	bool operator > (CHeure &) ;
};
