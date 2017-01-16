/****************************************
			Liste.cpp 
Définition de la liste doublement chainée 
****************************************/


#ifndef LANCER
#define LANCER
#include "CListe.h"
#include <iostream.h>

/** Constructeur **/
template <class T>
CListe<T> :: CListe(void) {
		_tete = NULL ;
		nbe=0;
}


/** Méthodes d'ajouts **/
template <class T>
void CListe<T> :: ajoutTete(Noeud<T> * nouv) { 

		if (_tete == NULL) {
			_tete = nouv ;
		}

		else {
			nouv->setSuiv(_tete);
			_tete->setPrec(nouv);
			_tete = nouv ;
		}
		nbe++;
}


template <class T>
void CListe<T> :: ajoutQueue(Noeud<T> * nouv) {

		if (_tete != NULL) {
			Noeud<T> * tmp;
			tmp = _tete ;
			while(tmp->getSuiv() != NULL)
				tmp = tmp->getSuiv();

			tmp->setSuiv(nouv);
			nouv->setPrec(tmp) ;
			nbe++;
		}
		else
			ajoutTete(nouv);


	}


template <class T>
void CListe<T> :: ajoutAvtPos(Noeud<T> * nouv,Noeud<T> * pos) {
		if (pos->getPrec() != NULL) {

			nouv->setSuiv(pos);
			nouv->setPrec(pos->getPrec());
			
			pos->getPrec()->setSuiv(nouv);
			pos->setPrec(nouv);
			nbe++;
		}
		else 
			ajoutTete(nouv);


} 


template <class T>
void CListe<T> :: ajout(T nv,int n) {
	Noeud<T> * nouv = new Noeud<T>(nv);
	if (n<0 || n>nbe)
		throw Exception(n,1);
	else {
		if (n==0) ajoutTete(nouv);
		else if (n==nbe-1) ajoutQueue(nouv);
		else {
			cout << " Appel get() \n" ;
			Noeud<T> * tmp = getNoeud(n) ;
			cout << " Appel ajoutAvtPos() \n" ;
			ajoutAvtPos(nouv,tmp);
		}
	}
}


template <class T>
void CListe<T> :: ajoutTrie(T nouv) {
	Noeud<T> * nv = new Noeud<T>(nouv); 
	Noeud<T> * tmp = _tete;
	bool trouve= false;

	if (estVide())
		ajoutTete(nv);

	else {
		while( !trouve && (tmp != NULL) ) {
			if (tmp->getObjet() > nouv)
				trouve=true;
			else
				tmp=tmp->getSuiv();
		}

	if (trouve)
		ajoutAvtPos(nv,tmp);
	else
		ajoutQueue(nv);
	}

}


/** Méthodes de suppression **/
template <class T>
void CListe<T> :: supprTete(void) {
		if(estVide())
			throw Exception(0,2); // exception file vide
		else if (nbe==1) {
			_tete->setSuiv(NULL);
			_tete->setPrec(NULL);
			nbe--;
		}
		else {
		Noeud<T> * tuer ;
			
		tuer = _tete ;
		_tete = _tete->getSuiv() ;
		_tete->setPrec(NULL);

		delete tuer ;
		nbe--;
		}
		
	}

template <class T>
void CListe<T> :: supprQueue(void) {
		if(estVide())
			throw Exception(0,2); // exception liste vide
		else if (nbe==1) {
			delete _tete;
			nbe--;
		}
		else {
		Noeud<T> * tuer ;
		Noeud<T> * tmp ;

		tmp = _tete ;

		while(tmp->getSuiv() != NULL )
			tmp = tmp->getSuiv() ;
			
		tuer = tmp ;
		tmp = tmp->getPrec() ;

		tmp->setSuiv(NULL);
		delete tuer ;
		nbe--;
		}
}


template <class T>
void CListe<T> :: supprPos(Noeud<T> * n) {

		Noeud<T> * tmp ;

		if( n->getPrec() == NULL) 
			supprTete();	
		else if (n->getSuiv() == NULL) 
			supprQueue();			
			
		else {
			tmp = n->getPrec();
			tmp->setSuiv(n->getSuiv());
			n->getSuiv()->setPrec(tmp) ;
			
			delete n ;
			nbe--;
		}
}
template <class T>
void CListe<T> :: suppr(int i) {

	if (i<0 || i>=nbe)  
		throw Exception(i,1);
	else if (nbe==0)
		throw Exception(i,2);
	else {
		if (i==0) supprTete();
		else if (i==nbe-1) supprQueue();
		else supprPos(getNoeud(i));
	}

}


/** Méthode d'acquisition (Getters) **/
template <class T>
Noeud<T> * CListe<T> :: getNoeud(int n) {
	if (estVide()) 
		throw Exception(0,2); // exception : raison : liste vide
	else if(n<0 || n>=nbe)
		throw Exception(n,1); // exception : raison : l'indice demandé n'existe pas
	else {
		Noeud<T> * tmp = new Noeud<T>();
		tmp = _tete ;
		for(int i=0;i<n;i++) 
				tmp=tmp->getSuiv();
		return tmp ;
	}
}

template <class T>
T CListe<T> :: get(int n) {
		if (n<0 || n>= nbe)
			throw Exception(n,1);
		else
cout << getNoeud(n)->getObjet() ;
			return getNoeud(n)->getObjet() ;
}

/* Autre méthodes */ 

template <class T>
void CListe<T> :: afficher(bool indice) {
		Noeud<T> * tmp ;
		int cpt=0; // pour l'affichage de la position du noeud dans la liste
		if(!estVide()) {
			tmp = _tete ;
			while(tmp != NULL ) {			
				if (indice) 
					cout << "Id : "<< cpt<<endl; ;
				tmp->afficher();
				tmp = tmp->getSuiv();
				cpt++;
			}
		}
		else
			cout << "Aucun element a afficher." <<endl;
}
template <class T>
bool CListe<T> :: estVide() { return (nbe==0); }

template <class T>
int CListe<T> :: taille() { return nbe ; }

#endif