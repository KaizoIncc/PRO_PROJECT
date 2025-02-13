
/// -----------------------------------------
///
///  	Implementació classe Processador
///
/// -----------------------------------------

#include "processador.hpp"

Processador::Processador()			// Implementat
{
	_id = -1;
	program_n = 0;
};

Processador::Processador(int i)		// Implementat
{
	_id = i;
	program_n = 0;
};

Processador::~Processador()			// Implementat
{};

int Processador::id() const {return _id;};	// Implementat

/********************************************************/
/*              Implementeu el que queda                */
/********************************************************/

// POST: encua el programa `p` a la cua de prioritat del processador.
void Processador::encuaPrograma(Programa& p)
{
	PROGRAMES.push(p);
};

//	PRE: t és un enter positiu sempre. `t = (0, +inf)`
//	POST: executa t unitats de temps (instruccions) del programa amb més prioritat
void Processador::executa (int t) {

	int t4 = t;
	int i = 0;

	while(!PROGRAMES.empty() && t > 0) {
		
		int t2 = 0;

		Programa P = PROGRAMES.front();
		PROGRAMES.pop();

		cout << "PROC: " << _id << " CARREGA " << P.id() << " PRIORITAT " << P.prioritat() << endl;
		
		int status = P.executa();
		--t;
		++t2;
		++i;

		while(status >= 0 && t > 0) {
			status = P.executa();
			--t;
			++t2;
			++i;
		}

		cout << "PROC: " << _id << " EXECUTAT " << t2 << " PASSOS: " << i << " de " << t4 << " STATUS " << status << endl;

		if(status == -10) P.escriuDispositiu(cout); // Escriu dispositiu si el programa finalitza correctament.

		if(t <= 0 && status == 0) {
			
			cout << "PROGRAMA " << P.id() << " PRIORITAT " << P.prioritat() << " a ";
						
			if(P.prioritat() - 10 <= 0) {
				P.prioritat(0);
				cout << 0 << endl;
			}
			else {
				P.prioritat(P.prioritat() - 10);
				cout << P.prioritat() << endl;
			}
			encuaPrograma(P);
		}
	}
};

/*************************************************************/
/*           l'operador >> ja està implementat               */
/*************************************************************/

ostream& operator<<(ostream& os, const Processador& p) 
{
	os << "PROCESSADOR: " << p._id << " #PROG: " << p.PROGRAMES.size() << endl;

	Queue<Programa> 	copia = p.PROGRAMES;

	while (not copia.empty())
	{
		Programa prog = copia.front();	
		copia.pop();
		os << prog.status() << endl;
	}

	return os;
};

