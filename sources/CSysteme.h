/*CSysteme.h*/
	
#include "CProprietaire.cpp" 

class CSysteme {


private :
	CProprietaire _proprietaire; // définition du proprietaire

public :
	/* Constructeur */
	CSysteme(void); 
	/* Setters */
	void setCouleurFond(void); 	// pour définir la couleur du fond (info stocké dans CProprietaire)
	void setCouleurTexte(void);	// pour définir la couleur du texte (info stocké dans CProprietaire)
	void setMotDePasse(bool); 	// pour définir rapidement un nouveau mot de passe sans passé par setProprietaire
	void setProprietaire(void);

	/* Getters */
	char * getCouleurFond(char *);
	char * getCouleurTexte(char *);
	char * getMotDePasse(char *);
	char * getPseudo(char *);

	/* Autres Méthodes */
	void afficherProprietaire(void);
 
	bool charger(void);
	void sauvegarder(void);
	void menu(void);
	void aide(void);
	
	
};
