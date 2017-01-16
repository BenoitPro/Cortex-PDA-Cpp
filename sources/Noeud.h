/* Noeud.h : 
 * Définie l'objet à inséré
 * et les 2 pointeurs
 * sur le noeud suivant et précédent
*/


template <class T> 
class Noeud {

	 
private :
	/* Variables de classe */
	T _objet ; 				// objet à inséré dans la liste
	Noeud<T> * _suiv ; 		// pointeur sur le suivant
	Noeud<T> * _prec; 		// pointeur sur le précédent

	
public :
	/* Constructeurs */
	Noeud(void);
	Noeud(T); 
	
	/* Getters */
	T getObjet() ;
	Noeud<T> * getPrec(void) ;
	Noeud<T> * getSuiv(void) ;

	/* Setters */
	void setObjet(T); 
	void setPrec(Noeud<T> *); 
	void setSuiv(Noeud<T> *);

	void afficher() ;
};