
/// -----------------------------------------
///
///  	Implementació classe So
///
/// -----------------------------------------

#include "so.hpp"

So::So()
{
};

So::~So()
{	
};

/*
 * INICI_PROGRAMA programa processador prioritat
 * EXECUTA processador temps
 * DISPOSITIU processador programa int
 * ESCRIU_PROCESSADOR processador
 *
 */

istream& operator>>(istream& is, So& so)
{
	int n_cpu, n_disp;
	is >> n_cpu >> n_disp;
	
	so.DISPOSITIUS = vector<Dispositiu>(n_disp);
	
	for (int i = 0 ; i < n_cpu ; i++) so.PROCESSADORS.push_back(Processador(i));
	
	string s;
	
	while (is >> s)
	{	
		if (s == "INICI_PROGRAMA")
		{
			int id, proc, prio, disp;
			is >> id >> proc >> prio >> disp;
			is.ignore();

			assert(disp < so.DISPOSITIUS.size());
			Programa P(id, proc, prio,so.DISPOSITIUS[disp]);
			is >> P;
			assert(proc < so.PROCESSADORS.size());
			so.PROCESSADORS[proc].encuaPrograma(P);
		}
			
		if (s == "EXECUTA")
		{
			int proc,t;
			cin >> proc >> t;
			assert(proc < so.PROCESSADORS.size());
			cout << "EXECUTA PROCESSADOR " << proc << " amb " << t << " unitats" << endl; 
			so.PROCESSADORS[proc].executa(t);
		}
		
		if (s == "DISPOSITIU")
		{
			int id, n;
			is >> id >> n;
			so.DISPOSITIUS[id] = Dispositiu(id,n);
			for (int i = 0 ; i < n ; i++)
			{
				int x;
				is >> x;
				so.DISPOSITIUS[id] << x;
			}
		}
		
		if (s == "ESCRIU_PROCESSADOR")
		{
			int p;
			is >> p;
			cout << so.PROCESSADORS[p] << endl;
		}		
	}
	
	return is;
}

ostream& operator<<(ostream& os, const So& so) 
{
	os << "SO. # Processadors: " << so.PROCESSADORS.size() << " ";
	os << " # Dispositius: " << so.DISPOSITIUS.size() << endl;
	
	return os;
};

