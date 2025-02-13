
/// -----------------------------------------
///
///  	Implementació classe Dispositiu
///
/// -----------------------------------------

#include "dispositiu.hpp"

// PRE: Cert
// POST: Crea un objecte Dispositiu amb capacitat màxima per defecte (10) i buit.
Dispositiu::Dispositiu() {
	_id = 0;
	capacitat_maxima = 10;
}

// PRE: capacitat_maxima ha de ser un enter positiu.
// POST: Crea un objecte Dispositiu amb l'identificador `_id` i capacitat màxima `capacitat_maxima` especificats i buit.
Dispositiu::Dispositiu(int i, int c) {
	_id = i;
	capacitat_maxima = c;
}

// PRE: Cert
// POST: Destrueix l'objecte Dispositiu.
Dispositiu::~Dispositiu() {

}

// PRE: Cert
// POST: Retorna true si el dispositiu està buit, false altrament.
bool Dispositiu::buit() const {
    return cua.empty();
}

// PRE: Cert
// POST: Si el dispositiu no està ple, afegeix el valor `i` al dispositiu i retorna true. Altrament, no modifica el dispositiu i retorna false.
bool Dispositiu::operator << (int i) {
	// Afegeix i al dispositiu si no està ple
    if (cua.size() < capacitat_maxima) {
        cua.push_back(i);
        return true;
    } else {
        // No es pot afegir, dispositiu ple
        return false;
    }
}

// PRE: Cert
// POST: Si el dispositiu no està buit, treu un element del dispositiu i el posa a `i` i retorna true. Altrament, no modifica `i` i retorna false.
bool Dispositiu::operator >> (int& i) {
	// Treu un element del dispositiu i el posa a la variable i si no està buit
    if (!cua.empty()) {
        i = cua.front();
        cua.pop_front();
        return true;
    } else {
        // No es pot treure, dispositiu buit
        return false;
    }
}

// PRE: Cert
// POST: Escriu la representació en cadena del dispositiu a la sortida estàndard.
ostream& operator<<(ostream& os, const Dispositiu& d) {
	
	os << "DISPOSITIU_ID: " << d._id << " : ";
	
	deque<int>::const_iterator it = d.cua.begin();
	
	while (it != d.cua.end())
	{
		os << *it << " ";
		it++;
	}
	
	return os;
}