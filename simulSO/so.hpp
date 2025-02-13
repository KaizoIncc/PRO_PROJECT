#ifndef SO_HPP
#define SO_HPP

#include <cassert>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <cassert>
#include <deque>

#include "processador.hpp"
#include "dispositiu.hpp"
#include "programa.hpp"

using namespace std;

/// INVARIANT DE LA CLASSE:

/// ------------------------------------------------------
///  Declaració operacions tipus So
/// ------------------------------------------------------


class So{

	private:

		vector<Processador> 			PROCESSADORS;
		vector<Dispositiu> 				DISPOSITIUS;


	public:

		So								();
		~So								();

		friend istream& operator>>		(istream&, So&);	
		friend ostream& operator<<		(ostream&, const So&);
};

#endif
