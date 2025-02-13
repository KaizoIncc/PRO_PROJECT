#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "dispositiu.hpp"

int main () {
	Dispositiu D(0,5);
	
	string s;
	
	while (cin >> s) {

		if (s == "PUSH") {
			int x;
			cin >> x;
			if (not (D << x)) cout << "DISPOSITIU PLE" << endl;
		}
		
		if (s == "POP") {
			
			if (not D.buit()) {
				int x;
				D >> x;
				cout << x << endl;
			}

			else cout << "DISPOSITIU BUIT " << endl;	
		}		

		if (s == "WRITE") cout << D << endl;

		if (s == "EMPTY") cout << (D.buit() ? "cert" : "fals") << endl;
	}

	return 0;
};

