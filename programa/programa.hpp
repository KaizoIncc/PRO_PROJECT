#ifndef PROGRAMA_HPP
#define PROGRAMA_HPP

#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <ctype.h>

using namespace std;

#include "dispositiu.hpp"
#include "memoriaBST.hpp"

/// ------------------------------------------------------
///  Declaració operacions tipus Programa
/// ------------------------------------------------------

class Programa
{
	const int 						CAPACITAT = 100;

	private:
	
		int							_id;
		int							_proc;
		int							_prioritat;

		int							PC;
		int 						AC;
		int							STATUS;
		int							COMPARACIO;
	
		stack<int> 					pila;
		vector<vector<string>>		llistat;
		Dispositiu					dispositiu;

		Memoria						memoria;
		
	public:

		Programa					(int, int, int, Dispositiu);	
		Programa					();								
		Programa					(const Programa&);				
	
		~Programa();												
		
		int id						() const;
		int executa					();								
		int prioritat 				() const;
		void prioritat 				(int);
		void escriuMemoria			(ostream& os) const;

		void afegeixDispositiu		(int);
		void escriuDispositiu		(ostream&) const;

		string status				() const;						
			
		// Operadors:
				
		bool compare				(const Programa&) const;		
		bool operator<				(const Programa&) const;		
		Programa& operator=			(const Programa&);				
		
		// Operacions:
		
		int opAritmetica			(const vector<string>&);
		int opPila					(const vector<string>&);
		int opDispositiu			(const vector<string>&);
		int opMemoria				(const vector<string>&);
		int opSalt					(const vector<string>&);
		int opComparacio			(const vector<string>&);
		int opIncrement				(const vector<string>&);
		int opNofares				(const vector<string>&);

		friend ostream& operator<<	(ostream&, const Programa&);	
		friend istream& operator>>	(istream&, Programa&);			


	private:
	
		vector<string> parse		(const string&);
		bool totDigits				(const string&);
};

#endif


