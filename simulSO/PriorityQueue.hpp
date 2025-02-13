#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>

using namespace std;

/** Representació d'una cua amb prioritat.
 *
 *  Els seus elements s'encuen en funció de la seva prioritat
 *  de manera que els elements amb més prioritat se serveixen
 *  primer. Si apareixen elements amb la mateixa prioritat, 
 *  s'encuen segons el seu ordre ordre d'arribada.
 */

template <typename T>
class Queue {

private:
	struct Item {
		T value;
		Item *next;
	};

	Item *first;
	Item *last;
	int _size;

	///--------------------------
	// Mètodes privats auxiliars
	//--------------------------
	
    /* Pre: cert */
    /* Post: fa una còpia de la cadena de nodes
       apuntats	per item per permetre assignar cues (=) i
	   crear cues fent servir el constructor còpia */
	void copyItems(const Item *item, Item *(&first), Item *(&last), int &_size);

	/* Pre: cert */
    /* Post: no fa res si item és NULL, sinó allibera
       espai de la cadena de nodes apuntada per item */
	void deleteItems(Item *item);
  
public:

	//-------------
	// Constructors
	//-------------
	
	/* Pre: cert */
	/* Post: el resultat és una cua amb prioritat sense cap element */
	Queue();

	/* Pre: cert */
	/* Post: el resultat és una cua amb prioritat còpia de la
	   cua rebuda */
	Queue(const Queue &q);

	//-------------
	// Destructor
	//-------------
	
	/* esborra automàticament els objectes locals
	   en sortir d'un àmbit de visibilitat */
	~Queue();

	//-------------
	// Modificadors
	//-------------

    /* Pre: cert */
    /* Post: operació d'assignació de cues  */
	Queue &operator=(const Queue &q);

    /* Pre: el paràmetre implícit no és buit */
    /* Post: elimina el primer element del paràmetre
       implícit	*/
	void pop();

    /* Pre: cert */
    /* Post: afegeix el valor rebut per paràmetre en el
	   paràmetre implícit, tenint en compte la seva prioritat */
	void push(T value);
	
    /* Pre: el paràmetre implícit no és buit */
    /* Post: elimina el valor rebut per paràmetre del
	   paràmetre implícit */
	void remove(T value);

	//-----------
	// Consultors
	//-----------	

    /* Pre: el paràmetre implícit no és buit */
    /* Post: el resultat és el primer element 
	   del paràmetre implícit */
	T front() const;

    /* Pre: cert */
    /* Post: el resultat és el nombre d'elements
	   del paràmetre implícit */  
	int size() const;
  
    /* Pre: cert */
    /* Post: el resultat indica si el paràmetre
       implícit	és buit o no */
	bool empty() const;

	//-----------
	// L/E
	//-----------
		
	/* Pre: cert */
    /* Post: s'han escrit al canal estàndard de sortida els elements
       de q */
	template<typename U> friend ostream &operator<<(ostream &os, Queue<U> &q);

    /* Pre: q està buida; el canal estàndard d'entrada els elements
      d'una cua Q */
    /* Post: q = Q */
	template<typename U> friend istream &operator>>(istream &is, Queue<U> &q);
};

#include "PriorityQueue.cpp"

#endif
