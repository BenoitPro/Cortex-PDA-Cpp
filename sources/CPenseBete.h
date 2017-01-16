/******************
	CPenseBete.h
D�finit un pense bete
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
	char _type[MAX]; // diff�rents choix entre course, travail, id�e, ou personnalis�

public :
	/* Constructeurs */
	CPenseBete(void);
	CPenseBete(char * titre);

	/* M�thodes */
	// Getters 
	char * getTitre(char *);
	char * getDescription(char *);
	char * getType(char *);

	// Setters
	void setTitre(char *);
	void setDescription(char *);
	void setType(char *);

	// Surd�finition de l'op�rateur > pour l'ajout tri�
	bool operator > (CPenseBete) ;

	// Red�finition de l'op�rateur >> pour la saisie
	friend ifstream& operator>>(ifstream&,CPenseBete);

	// Red�finition de l'op�rateur << pour l'affichage
	friend ostream& operator<<(ostream&,CPenseBete);	
	
	// Red�finition de l'op�rateur << pour la sauvegarde
	friend ofstream& operator<<(ofstream&,CPenseBete);

};

