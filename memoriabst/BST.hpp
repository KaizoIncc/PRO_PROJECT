#ifndef BST_HPP
#define BST_HPP
#include <iostream>
#include <vector>

using namespace std;

/*  
 * Representació d'un arbre binari cerca o
 * BST (binary search tree). Un arbre binari 
 * de cerca és un arbre binari en què el subarbre
 * esquerre de qualsevol node (si no està buit)
 * conté valors menors que el que conté aquest node, 
 * i el subarbre dret (si no està buit) conté valors
 * més grans.
 */ 
template <typename T>
class BST 
{
	
private:
	struct Item {
		T data;
		Item *left;
		Item *right;
		Item(const T& d, Item *l, Item *r) {
			data = d;
			left = l;
			right = r;
		}
	};

	Item *root;
	
	
	///--------------------------
	// Mètodes privats auxiliars
	//--------------------------

	/* Pre: cert */
	/* Post: no fa res si item és NULL, sinó allibera
       espai de la jerarquia de nodes apuntada per item */
	void clear(Item *node);

	/* Pre: cert */
	/* Post: afegeix un node amb el valor rebut 
	   per paràmetre a la jerarquia de nodes apuntada
	   per item, mantenint les propietats de BST */
	Item* insert(Item *node, const T& d);
	
	/* Pre: cert */
	/* Post: esborra el node amb el valor rebut 
	   per paràmetre de la jerarquia de nodes apuntada
	   per item, mantenint les propietats de BST */	
	Item* remove(Item *node, const T& d);
	
	/* Pre: la jerarquia de nodes apuntada per item
	   conté un node amb el primer valor rebut per
	   paràmetre (d) */
	/* Post: s'ha modificat el valor del node amb el
	   segon valor rebut per paràmetre (newData), de
       la jerarquia de nodes apuntada per item */
	void setValue(Item *node, const T& d, const T& newData);
	
	Item* copia(Item *node);

	void preOrdre(Item*, vector<T>&) const;
	
public:

	//-------------
	// Constructors
	//-------------
	
	/* Pre: cert */
	/* Post: el resultat és un bst sense cap element */	
	BST();
	
	BST(const BST&);

	//-------------
	// Destructor
	//-------------
	
	/* esborra automàticament els objectes locals
	   en sortir d'un àmbit de visibilitat */
	~BST();

	BST& operator=(const BST&);

	//-------------
	// Modificadors
	//-------------

	/* Pre: cert */
	/* Post: afegeix un element, amb el valor rebut
	   per paràmetre, al paràmetre implícit */
	void insert(const T& d);

	/* Pre: cert */
	/* Post: esborra l'element, que té el valor rebut
	   per paràmetre, del paràmetre implícit */
	void remove(const T& d);

	/* Pre: el paràmetre implícit conté un element amb
	   el primer valor rebut per paràmetre (d) */
	/* Post: s'ha modificat el valor de l'element amb
	   el segon valor rebut per paràmetre (newData), del
       paràmetre implícit */
	void setValue(const T& d, const T& newData);
	
	/* Pre: cert */
	/* Post: el resultat és el node, de la jerarquia
	   de nodes apuntada per item, amb el mateix
	   valor que el valor rebut per paràmetre */
	Item* find(Item *node, const T& d) const;
	
	//-----------
	// Consultors
	//-----------
	
	/* Pre: cert */
	/* Post: el primer component del resultat indica
	   si el paràmetre implícit conté un element amb
	   el valor rebut per paràmetre; en cas afirmatiu,
	   el segon component conté l'element del paràmetre
	   implícit amb aquest valor, altrament conté un
	   element buit */
	pair<bool, T> find(const T& d) const;
	
	/* 
	 * PRE: cert.
	 * POST: torna en un vector el recorregut en PREordre de l'arbre.
	 */
	void preOrdre(vector<T>&) const;
	
};

#include "BST.cpp"

#endif
