/******************
	CPenseBete.h
Définit un pense bete
******************/

#define MAX 255
#include <ostream.h>
#include <fstream.h>

class CPenseBete {

	/* Variable de classe */
	// titre a remplir obligatoirement
	char _titre[MAX];
	// Autre variables a remplir facultativement
	char _description[MAX];
	char _type[MAX]; // différents choix entre course, travail, idée, ou personnalisé

public :
	/* Constructeurs */
	CPenseBete(void);
	CPenseBete(char * titre);

	/* Méthodes */
	// Getters 
	char * getTitre(char *);
	char * getDescription(char *);
	char * getType(char *);

	// Setters
	void setTitre(char *);
	void setDescription(char *);
	void setType(char *);

	// Surdéfinition de l'opérateur > pour l'ajout trié
	bool operator > (CPenseBete) ;

	// Redéfinition de l'opérateur >> pour la saisie
	friend ifstream& operator>>(ifstream&,CPenseBete);

	// Redéfinition de l'opérateur << pour l'affichage
	friend ostream& operator<<(ostream&,CPenseBete);	
	
	// Redéfinition de l'opérateur << pour la sauvegarde
	friend ofstream& operator<<(ofstream&,CPenseBete);

};

