/* Noeud.h : 
 * D�finie l'objet � ins�r�
 * et les 2 pointeurs
 * sur le noeud suivant et pr�c�dent
*/


template <class T> 
class Noeud {

	 
private :
	/* Variables de classe */
	T _objet ; 				// objet � ins�r� dans la liste
	Noeud<T> * _suiv ; 		// pointeur sur le suivant
	Noeud<T> * _prec; 		// pointeur sur le pr�c�dent

	
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