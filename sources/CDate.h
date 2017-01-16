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
	CDate(char *);				// prend en param�tre la date sous la forme fourni par l'utilisateur (char * : jj mm aaaa)
	
	/* M�thodes */
	bool bissextile(int);		// retourne vrai si l'ann�e donn�e en param�tre est bissextile
	bool verifierDate(char *);	// v�rifie si la date donn�e existe
	void recupererDate(char *);	// r�cupere l'ann�e le mois et le jour a partir du char * fournit
		
	// Les Getters
	int getAnnee();
	int getMois();
	int getJour();
	char * getDateS(char *);
	
	// Les Setters
	void setAnnee(int);
	void setMois(int);
	void setJour(int);

	// Surd�finition de l'op�rateur > pour l'ajout tri�
	bool operator > (CDate &) ;
	
	bool egalite(char*);


};