/******************************
		    Liste.h 
Définition des méthodes de la liste 
*******************************/

#include "Noeud.cpp"
#include "CException.cpp"
template <class T>
class CListe {

protected :
	/* Variables de classe */
	Noeud<T> * _tete ;
	int nbe ;
	
public :
	/* Constructeur */
	CListe();
	/* Méthodes de la classe */
	void ajoutTete(Noeud<T> *) ;
	void ajoutQueue(Noeud<T> *) ;
	void ajoutAvtPos(Noeud<T> *,Noeud<T> *) ;
	void ajout(T,int i); 			// throw Exception ajoute un objet sur la position i ;
	void ajoutTrie(T);
	
	
	void supprTete(void); 			// throw Exception 
	void supprQueue(void);			// throw Exception 
	void supprPos(Noeud<T> *);		// throw Exception
	void suppr(int i) ; 			// throw Exception. Supprime le Noeud de la i ieme position

	Noeud<T> * getNoeud(int n) ; 	// throw Exception. Renvoie le Noeud qui est à la i ieme position

	T get(int n) ; 					// throw Exception. Renvoi l'objet du Noeud qui est à la i ieme position

	void afficher(bool); 			// affiche tous les elements de la liste
	bool estVide(); 				// renvoie true si la liste est vide
	int taille() ; 					// renvoie la taille de la liste
		

};