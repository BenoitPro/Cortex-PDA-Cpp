/*CSysteme.h*/
	
#include "CProprietaire.cpp" 

class CSysteme {


private :
	CProprietaire _proprietaire; // d�finition du proprietaire

public :
	/* Constructeur */
	CSysteme(void); 
	/* Setters */
	void setCouleurFond(void); 	// pour d�finir la couleur du fond (info stock� dans CProprietaire)
	void setCouleurTexte(void);	// pour d�finir la couleur du texte (info stock� dans CProprietaire)
	void setMotDePasse(bool); 	// pour d�finir rapidement un nouveau mot de passe sans pass� par setProprietaire
	void setProprietaire(void);

	/* Getters */
	char * getCouleurFond(char *);
	char * getCouleurTexte(char *);
	char * getMotDePasse(char *);
	char * getPseudo(char *);

	/* Autres M�thodes */
	void afficherProprietaire(void);
 
	bool charger(void);
	void sauvegarder(void);
	void menu(void);
	void aide(void);
	
	
};
