#ifndef MEMORIA_HPP
#define MEMORIA_HPP

#include <cassert>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

#include "BST.hpp"

/// ------------------------------------------------------
///  Declaració operacions tipus Memoria
/// ------------------------------------------------------

class Memoria
{
	private:
	
		struct TUPLA {
			string clau;
			int valor;

			//	PRE: CERT
			//	POST: Crea una struct TUPLA amb una `clau` buïda i un `valor` amb valor equivalent a 0.
			TUPLA() {
				clau = "";
				valor = 0;
			}

			//	PRE: CERT
			//	POST: Crea una struct TUPLA amb una `clau` i un `valor`.
			TUPLA(const string& c, int v) {
				clau = c;
				valor = v;
			}

			// Operadors de comparació per a TUPLA
			
			//	PRE: CERT
			//	POST: Retorna true si la clau de la struct `TUPLA` implícit es menor a la clau de la struct TUPLA `other`.
			bool operator<(const TUPLA& other) const {
				return clau < other.clau;
			}
			
			//	PRE: CERT
			//	POST: Retorna true si la clau de la struct `TUPLA` implícit es major a la clau de la struct TUPLA `other`.
			bool operator>(const TUPLA& other) const {
				return clau > other.clau;
			}

			//	PRE: CERT
			//	POST: Retorna true si la clau de la struct `TUPLA` implícit es igual a la clau de la struct TUPLA `other`.
			bool operator==(const TUPLA& other) const {
				return clau == other.clau;
			}

			// Operador d'inserció per a TUPLA
			friend ostream& operator<<(ostream& os, const TUPLA& tupla) {
				os << tupla.clau << ": " << tupla.valor;
				return os;
			}
		};

		BST<Memoria::TUPLA> memoria;

	public:

		Memoria();								
		Memoria(const Memoria &);		
		~Memoria();						

		void set(const string&, int);
		int get (const string&);	
		
		Memoria& operator=(const Memoria&);		
		
		friend ostream& operator<<(ostream&, const Memoria&);

};

#endif
