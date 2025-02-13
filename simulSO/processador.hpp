#ifndef PROCESSADOR_HPP
#define PROCESSADOR_HPP

#include <cassert>
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

#include "programa.hpp"

#include "PriorityQueue.hpp"

/// ------------------------------------------------------
///  Declaració operacions tipus Processador
/// ------------------------------------------------------

class Processador
{

	private:

		Queue<Programa> 		PROGRAMES;
		
		int								program_n;
		int								_id;
			
	public:

		Processador						();							
		Processador						(int);						
		~Processador					();							
		
		int id							() const;
		void encuaPrograma				(Programa&);				
		void executa					(int);						
		
		friend ostream& operator<<		(ostream&, const Processador&);
};

#endif
