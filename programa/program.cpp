#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>

using namespace std;

#include "programa.hpp"
#include "dispositiu.hpp"

int main ()
{
	string s;
	cin >> s;
	cin.ignore();
	
	if (s != "INICI_PROGRAMA")			
	{
		cout << "ERROR" << endl;
		return -1;
	}

	Dispositiu D(0,20);			// id: 0 capacitat: 20
	for (int i = 0; i < 20; i++)	D << i + 10;

	Programa P(0,0,100,D);
	cin >> P;

	cout << P << endl;

	cout << "Abans de l'execució" << endl;
	P.escriuDispositiu(cout);
	
	int status = P.executa();
	while (status >= 0)	{status = P.executa();}
	
	cout << endl;

	cout << "Després de l'execució. Status: " << status << endl;
	P.escriuDispositiu(cout);
	
	return 0;
};







