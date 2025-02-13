#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "memoriaBST.hpp"

int main ()
{
	Memoria m;
	string s;
	
	while (cin >> s)
	{
		if (s == "SET")
		{
			string var;
			int val;
			
			cin >> var >> val;
			m.set(var,val);
		}
		
		if (s == "GET")
		{
			string var;
			cin >> var;
			cout << "GET: " << var << ": " << m.get(var) << endl;
		}
		
		if (s == "WRITE")		cout << m << endl;		
	}

	return 0;
};







