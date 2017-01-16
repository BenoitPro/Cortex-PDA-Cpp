/* CContact.h : Définition d'un objet CContact */
#define MAX 255			// constante
#include <ostream.h>	// pour les flux de sortie
#include <fstream.h>	// pour le flux de vers les fichiers

class CContact {

private :
	/* Variables de classe */

	// Au moin une de ces deux variables doit être donné pour créer l'objet CContact
	char _nom[MAX] ;		// nom du contact
	char _prenom[MAX]  ;	// prenom du contact

	// Variables facultatives
	char _pseudo[MAX] ;		// pseudo du contact
	char  _telephone[MAX] ;	// n° de téléphone du contact
	char _fax[MAX];			// n° de fax du contact
	char _naissance[MAX] ;	// date de naissance du contact
	char _adresse[MAX] ;	// adresse du contact
	char _email[MAX] ;		// adresse email du contact
	char _web[MAX] ;		// adresse web ou blog du contact
	char _type[MAX] ;		// choix entre plusieur type : collegue,famille, ami, personnalisé... 
							// (Utile pour une eventuel représentation par icone si on devais porté
							//  le programme en interface graphique)
	char _note[MAX] ;		// infos complémentaires sur le contact

public :
	/* Constructeurs */
	CContact(void);			// constructeur par défaut
	CContact(char * nom,char * prenom) ; // constructeur
	
	/* Méthodes */
	// Les Getters (pour récupéré les champs privé de la classe)
	char * getNom(char *);
	char * getPrenom(char *);
	char * getPseudo(char *);
	char * getTelephone(char *);
	char * getFax(char *);
	char * getNaissance(char *);
	char * getAdresse(char *);
	char * getEmail(char *);
	char * getWeb(char *);
	char * getType(char *);
	char * getNote(char *);

	// Les setters (pour définir les champs de la classe)
	void setNom(char *);
	void setPrenom(char *);
	void setPseudo(char *);
	void setTelephone(char *);
	void setFax(char *);
	void setNaissance(char *);
	void setAdresse(char *);
	void setEmail(char *);
	void setWeb(char *);
	void setType(char *); 
	void setNote(char *);

	// Surdéfinition de l'opérateur > pour l'ajout trié
	bool operator > (CContact) ;

	// Redéfinition de l'opérateur >> pour la saisie
	friend ifstream& operator>>(ifstream&,CContact&);

	// Redéfinition de l'opérateur << pour l'affichage
	friend ostream& operator<<(ostream&,CContact);	
	
	// Redéfinition de l'opérateur << pour la sauvegarde
	friend ofstream& operator<<(ofstream&,CContact);

};