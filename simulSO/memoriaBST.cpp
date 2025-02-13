
/// -----------------------------------------
///
///  	Implementació classe Memoria
///
/// -----------------------------------------

#include "memoriaBST.hpp"

/* Cal que implementeu tots els mètodes, llevat de l'operator<< */

// PRE: Cert.
// POST: Crea una instància de la classe `Memoria` amb una memòria buida.
Memoria::Memoria() {

}

// PRE: Cert
// POST: Crea una còpia de la memòria de l'objecte `m`.
Memoria::Memoria (const Memoria &m) {
	this->memoria = m.memoria;
}

// PRE: Cert
// POST: Allibera els recursos de la instància de la classe `Memoria`.
Memoria::~Memoria() {

}

// PRE: Cert
// POST: Assigna la memòria de l'objecte `m` a la memòria de l'objecte actual.
Memoria& Memoria::operator= (const Memoria& m) {
	if (this != &m) {
        this->memoria = m.memoria;
    }
    return *this;
}

// PRE: Cert
// POST: Si la variable `c` ja existeix a la memòria, li assigna el valor `v`. Si no existeix, afegeix una nova tupla amb la variable `c` i el valor `v`.
void Memoria::set(const string& c, int v) {
	TUPLA t(c, v);
    
    auto result = memoria.find(t);

    if (result.first) {
        memoria.setValue(result.second, t);
    } 
    else {
        memoria.insert(t);
    }
}

// PRE: Cert
// POST: Retorna el valor associat a la variable `c` a la memòria. Si la variable no existeix, retorna `0`.
int Memoria::get (const string& c) {
	TUPLA t(c, 0);
    auto result = memoria.find(t);
    if (result.first) {
        return result.second.valor;
    } else {
        return 0;
    }
}

ostream& operator<<(ostream& os, const Memoria& m) {
	vector<Memoria::TUPLA> pre;
	
	m.memoria.preOrdre(pre);
	
	for (Memoria::TUPLA t : pre)	os << t << endl;
	
	return os;
}


