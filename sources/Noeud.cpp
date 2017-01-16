/*******************************
		Noeud.cpp
Définition des méthodes de Noeud 
********************************/


/* Importation */
#include "Noeud.h"
#include <iostream.h>


/* Constructeur */
template <class T> 
Noeud<T> :: Noeud(void) {
	_suiv=_prec= NULL ;	
}
template <class T> 
Noeud<T> :: Noeud(T obj) { 
	_objet = obj ;
	_suiv=_prec=NULL;
}

/* Getteurs */
template <class T> 
T Noeud<T> :: getObjet() { 
	return _objet ;
}

template <class T> 
Noeud<T> * Noeud<T> :: getPrec() {	return _prec; }

template <class T> 
Noeud<T> * Noeud<T> :: getSuiv() {	return _suiv; }

/* Setteurs */
template <class T>
void Noeud<T> :: setObjet(T obj) { 
	_objet = obj ;
}

template <class T> 
void Noeud<T> :: setPrec(Noeud<T> * n) { _prec = n ; }

template <class T> 
void Noeud<T> :: setSuiv(Noeud<T> * n) { _suiv = n ; }

/* Méthodes */
template <class T> 
void Noeud<T> :: afficher() {	cout << getObjet() << endl; }

