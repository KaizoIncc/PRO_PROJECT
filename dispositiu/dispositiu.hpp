#ifndef DISPOSITIU_HPP
#define DISPOSITIU_HPP

#include <cassert>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <cassert>
#include <deque>

using namespace std;

/// INVARIANT DE LA CLASSE:

/// ------------------------------------------------------
///  Declaració operacions tipus Dispositiu
/// ------------------------------------------------------


class Dispositiu
{

	private:
		int _id;
		int capacitat_maxima;
		deque<int> cua;

	public:

		Dispositiu();							
		Dispositiu(int,int);					
		~Dispositiu();							

		bool buit() const;

		bool operator << (int);						
		bool operator >> (int&);						
		
		friend ostream& operator<< (ostream&, const Dispositiu&);	
};

#endif
