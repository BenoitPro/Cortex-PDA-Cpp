/*************
CProprietaire.h
**************/
#define MAX 255
class CProprietaire {

private :
	char _mot_de_passe[MAX];
	char _pseudo[MAX];
	char _nom[MAX];
	char _prenom[MAX];
	char _adresse1[MAX];
	char _adresse2[MAX];
	char _telephoneFixe[MAX];
	char _telephonePortable[MAX];
	char _fax[MAX];
	char _email[MAX];
	char _web[MAX];
	char _note[MAX];
	char _couleurFond[MAX] ; 	// couleur d'arriere plan console
	char _couleurTexte[MAX] ; 	// couleur texte console

public :
	/* Constructeur */
	CProprietaire(void);
	
	/* Getters */
	char * getMotDePasse(char *);
	char * getPseudo(char *);
	char * getNom(char *);
	char * getPrenom(char *);
	char * getAdresse1(char *);
	char * getAdresse2(char *);
	char * getTelephoneFixe(char *);
	char * getTelephonePortable(char *);
	char * getFax(char *);
	char * getEmail(char *);
	char * getWeb(char *);
	char * getNote(char *);

	char * getCouleurFond(char *);
	char * getCouleurTexte(char *);

	/* Setters */
	void setMotDePasse(char *);
	void setPseudo(char *);
	void setNom(char *);
	void setPrenom(char *);
	void setAdresse1(char *);
	void setAdresse2(char *);
	void setTelephoneFixe(char *);
	void setTelephonePortable(char *);
	void setFax(char *);
	void setEmail(char *);
	void setWeb(char *);
	void setNote(char *);

	void setCouleurFond(char *);
	void setCouleurTexte(char *);

	// Redéfinition de l'opérateur>> pour le chargement
	friend ifstream& operator>> (ifstream&,CProprietaire&) ;

	// Redéfinition de l'opérateur << pour la sauvegarde
	friend ofstream& operator<<(ofstream&,CProprietaire);
};