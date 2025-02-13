
/// -----------------------------------------
///  	Implementació classe Programa
/// -----------------------------------------

#include "programa.hpp"

/*--------------------------------------------------------------------*/
/*                       Mètodes privats                              */
/*--------------------------------------------------------------------*/

// PRE: s és un string que correspon a una línia de codi.
// POST: torna un vector d'strings, un string per ítem a s.
// Exemple: si s = "GOTO 30"
// torna el vector ["GOTO", "30"]

vector<string> Programa::parse(const string& s)
{
	int N = s.size();
	int i = 0;
	int inici = 0, fi = 0;
	vector<string> r;
	
	while (i < N)
	{
		while (s[i] == ' ' and i < N)	i++;
		inici = i;
		while (s[i] != ' ' and i < N)	i++;
		fi = i - 1;
		if (inici <= fi)	r.push_back(s.substr(inici,fi - inici + 1));
	}

	return r;
}

bool Programa::totDigits(const string& s)		// Implementat
{
	if (s.size() == 0)							return false;
	
	if (s[0] != '-' and (not isdigit(s[0])))	return false;
	
	for (int i = 1 ; i < s.size() ; i++)
		if (not isdigit(s[i])) return false;
		
	return true;
}

/*--------------------------------------------------------------------*/

Programa::Programa(int id, int proc, int pri, Dispositiu d)
{
	_id 		= id;
	_proc 		= proc;
	_prioritat 	= pri;
	
	AC 			= 0;
	PC 			= 0;
	STATUS 		= 0;
	COMPARACIO	= 0;
	dispositiu	= d;
};

Programa::Programa()
{};

Programa::Programa(const Programa& P)
{
	_id 		= P._id;
	_proc 		= P._proc;
	_prioritat 	= P._prioritat;
	
	AC 			= P.AC;
	PC 			= P.PC;
	STATUS 		= P.STATUS;
	COMPARACIO	= P.COMPARACIO;
	
	dispositiu 	= P.dispositiu;
	
	pila		= P.pila;
	llistat		= P.llistat;
	memoria		= P.memoria;
};

/*********************************************************************/
/************* IMPLEMENTEU ELS MÈTODES A CONTINUACIÓ *****************/
/*********************************************************************/

Programa::~Programa() {};

//	PRE: CERT
//	POST: Retorna el `_id` del objecte `Programa` implícit.
int Programa::id() const {
	return _id;
}

//	PRE: CERT
//	POST: Retorna la `_prioritat` del objecte `Programa` implícit.
int Programa::prioritat() const {
	return _prioritat;
}

//	PRE: `p` és un int on el seu valor està entre `0` i `100`.
//	POST: Modifica l'atribut `_priotitat` del objecte `Programa` implícit pel valor de `p`.
void Programa::prioritat (int p) {
	_prioritat = p;
}

//	PRE: `i` es un int
//	POST: Afegeix `i` al dispositiu del programa.
void Programa::afegeixDispositiu (int i) {
	dispositiu << i;
}

//	PRE: CERT
//	POST: Escriu el dispositiu del programa pel canal `os`.
void Programa::escriuDispositiu (ostream& os) const {
	os << dispositiu << endl;
}

//	PRE: CERT
//	POST: Torna true si el paràmetre implícit `_prioritat` és menor que el paràmetre `_prioritat` del objecte Programa pro2. Un programa és més gran que l'altre si la prioritat és superior. En cas de tenir la mateixa prioritat, és qui té `_id` menor.
bool Programa::compare(const Programa& prog2) const {
	if (_prioritat > prog2._prioritat) return true;
    else if (_prioritat == prog2._prioritat) return _id > prog2._id;
    else return false;
}

/* interfície de compare*/
bool Programa::operator<(const Programa& prog2) const
{
	return compare(prog2);
}

Programa& Programa::operator=(const Programa& P)	// Implementat
{
    if (this == &P)        return *this;

	_id 		= P._id;
	_proc 		= P._proc;
	_prioritat 	= P._prioritat;
	
	AC 			= P.AC;
	PC 			= P.PC;
	STATUS 		= P.STATUS;
	COMPARACIO	= P.COMPARACIO;
 
	pila		= P.pila;
	llistat		= P.llistat;
	memoria		= P.memoria; 
 
	dispositiu	= P.dispositiu;

    return *this;
}

void Programa::escriuMemoria(ostream& os) const		// Implementat
{
	os << "Programa id: " << _id << " STATUS:" << STATUS << 
			" COMP: " << COMPARACIO << 
			" PC: " << (PC + 1) * 10 << endl;
			
	os << memoria << endl;

	return;
}

/*******************************************************
 * 				instruccions.
********************************************************/
/*
Totes les funcions següents implementen les instr[0]s
que han estat especificades a l'enunciat.
*/

//	PRE: `instr` és un vector de strings on `|instr| >= 1`.
//	POST: Aquesta funció fa operacions aritmètiques (suma, resta, multiplicació, divisió) i el resultat ho empila a la `pila` del programa. Pot retornar 2 valors, 0 o -2. Retornarà `0` en cas de que la funció s'hagi executat amb éxit. Altrament, retornarà `-2` si al fer una divisió el segon operand és 0.
int Programa::opAritmetica(const vector<string>& instr) {

    int op1, op2;

	if(totDigits(instr[1])) op1 = stoi(instr[1]);
	else op1 = memoria.get(instr[1]);

	if(totDigits(instr[2])) op2 = stoi(instr[2]);
	else op2 = memoria.get(instr[2]);

    if (instr[0] == "SUMA") pila.push(op1 + op2);
	if (instr[0] == "RESTA") pila.push(op1 - op2);
    if (instr[0] == "MULT") pila.push(op1 * op2);
    if (instr[0] == "DIV") {
        
		if (op2 == 0) {
            STATUS = -2;
            return STATUS;
        }
        
		pila.push(op1 / op2);
    }
	
	++PC;

    return STATUS;
}

//	PRE: `instr` és un vector de strings on `|instr| >= 1`.
//	POST: Aquesta funció empila i desempila valors de la `pila` del programa. Pot retornar 3 valors. Retornarà `0` si l'execució ha sigut un éxit. Retornarà `-1` si `|pila| >= CAPACITAT`. Retornarà `-3` si la `pila` està buída.
int Programa::opPila(const vector<string>& instr) {

    if (instr[0] == "EMPILA") {
        
        if (pila.size() >= CAPACITAT) {
            STATUS = -1;
            return STATUS;
        }

        int op;
        if (totDigits(instr[1])) op = stoi(instr[1]);
        else op = memoria.get(instr[1]);

        pila.push(op);
    }

	else if (instr[0] == "DESEMPILA") {
       
        if (pila.empty()) {
            STATUS = -3; 
            return STATUS;
        }

        string var = instr[1];
        int valor = pila.top();
        pila.pop();
        memoria.set(var, valor);
    }

	++PC;

    return STATUS;
}

//	PRE: `instr` és un vector de strings on `|instr| >= 1`.
//	POST: Aquesta funció llegeix i escriu sobre el `dispositiu` del programa. Pot retornar 3 valors. Retornarà `0` si l'execució ha sigut un éxit. Retornarà `-8` si el dispositiu està buit en cas de voler llegir i retornarà `-9` si el dispositiu està ple i s'intenta escriure.
int Programa::opDispositiu(const vector<string>& instr) {

    if (instr[0] == "LLEGEIX") {

        if (dispositiu.buit()) {
            STATUS = -8;
			return STATUS;
        }

        int valor;
        dispositiu >> valor;
		memoria.set(instr[1], valor);
    } 
	
	if (instr[0] == "ESCRIU") {
        
        int valor;

        if (totDigits(instr[1])) valor = stoi(instr[1]);
        else valor = memoria.get(instr[1]);

        if(!(dispositiu << valor)) STATUS = -9;
    }

	++PC;
	
	return STATUS;
}

//	PRE: `instr` és un vector de strings on `|instr| >= 1`.
//	POST: Aquesta funció cerca elements en la memoria del programa i si no existeix, el crea. Retorna sempre `0`.
int Programa::opMemoria(const vector<string>& instr) {

    int valor;
    if (totDigits(instr[2])) valor = stoi(instr[2]); 
	else valor = memoria.get(instr[2]);

    memoria.set(instr[1], valor);

    ++PC;
	
	return STATUS;
}

//	PRE: `instr` és un vector de strings on `|instr| >= 1`.
//	POST: Aquesta funció fa salts condicionals i incondicionals (GOTO). Retorna `0` en cas d'éxit i `-5` si la linea no existeix.
int Programa::opSalt(const vector<string>& instr) {

    int op = stoi(instr[1]);

    if (op % 10 != 0) {
        STATUS = -5;
        return STATUS;
    }

    if (instr[0] == "GOTO") PC = (op/10) - 1;
    else if (instr[0] == "MESGRAN" && COMPARACIO == 1) PC = (op/10) - 1;
    else if (instr[0] == "MESPETIT" && COMPARACIO == 2) PC = (op/10) - 1;
    else if (instr[0] == "IGUAL" && COMPARACIO == 3) PC = (op/10) - 1;
    else if (instr[0] == "PILABUIDA" && pila.empty()) PC = (op/10) - 1;
    else if (instr[0] == "DISPBUIT" && dispositiu.buit()) PC = (op/10) - 1;
    else ++PC;

	if (PC >= llistat.size()) STATUS = -10;
    
	return STATUS;
}

//	PRE: `instr` és un vector de strings on `|instr| >= 1`.
//	POST: Aquesta funció compara 2 valors que poden ser enters o valors en la memoria. Retorna sempre `0`.
int Programa::opComparacio(const vector<string>& instr) {

	int op1, op2;

	if(totDigits(instr[1])) op1 = stoi(instr[1]);
	else op1 = memoria.get(instr[1]);

	if(totDigits(instr[2])) op2 = stoi(instr[2]);
	else op2 = memoria.get(instr[2]);

	if(op1 > op2) COMPARACIO = 1;
	else if(op1 < op2) COMPARACIO = 2;
	else COMPARACIO = 3;

	++PC;

	return STATUS;
}

//	PRE: `instr` és un vector de strings on `|instr| >= 1`.
//	POST: Aquesta funció incrementa i decrementa en 1 un valor en memoria. Retorna sempre `0`. 
int Programa::opIncrement(const vector<string>& instr) {
	
	int valor = memoria.get(instr[1]);

	if(instr[0] == "INCREMENTA") memoria.set(instr[1], valor + 1);
	else if(instr[0] == "DECREMENTA") memoria.set(instr[1], valor - 1);
	
	++PC;

	return STATUS;
}

//	PRE: `instr` és un vector de strings on `|instr| >= 1`.
//	POST: Incrementa la PC del programa i retorna `0`.
int Programa::opNofares(const vector<string>& instr) {
	if (instr[0] == "NOFARES")		PC++;	// per evitar error de compilació 

	return STATUS;
}

int Programa::executa ()		// Implementat
{
	if (STATUS < 0 )			return STATUS;
	if (PC >= llistat.size())	{STATUS = -10; return STATUS;} // programa acabat
	
	int RETORN = 0;
	
	assert (PC < llistat.size());

	string instr = llistat[PC][0];

	if (instr == "SUMA" or 
		instr == "RESTA" or 
		instr == "MULT" or 
		instr == "DIV")				RETORN = opAritmetica(llistat[PC]);
		
	if (instr == "EMPILA" or 
		instr == "DESEMPILA")		RETORN = opPila(llistat[PC]);

	if (instr == "LLEGEIX" or 
		instr == "ESCRIU")			RETORN = opDispositiu(llistat[PC]);

	if (instr == "MOU")				RETORN = opMemoria(llistat[PC]);
	
	if (instr == "GOTO" or 
		instr == "MESGRAN" or 
		instr == "MESPETIT" or 
		instr == "IGUAL" or
		instr == "PILABUIDA" or
		instr == "DISPBUIT")		RETORN = opSalt(llistat[PC]);
	
	if (instr == "CMP")				RETORN = opComparacio(llistat[PC]);
	
	if (instr == "INCREMENTA" or
		instr == "DECREMENTA")		RETORN = opIncrement(llistat[PC]);	

	if (instr == "NOFARES")			RETORN = opNofares(llistat[PC]);
			
	return RETORN;
};

string Programa::status() const		// Implementat
{
	string s;
	s = "PROGRAM ID: " 	+ to_string(_id) +
		" PRIO: " 	 	+ to_string(_prioritat) +
		" PROC#: " 	 	+ to_string(_proc) +
		" AC: " 		+ to_string(AC) +
		" PC: "			+ to_string( (PC + 1) * 10) +
		" STATUS: "		+ to_string(STATUS) +
		" STACK: " 		+ to_string(pila.size()) + "/" + to_string(CAPACITAT);

	return s;
};

/* Els operadors << i >> també us els donem implementats */

ostream& operator<<(ostream& os, const Programa& p) 
{
	os << "--------------------------------" << endl;
	os  << p.status() << endl;
	
	for (int i = 0 ; i < p.llistat.size() ; i++)
	{
		os << (i + 1) * 10 << ": ";
		
		for (int j = 0 ; j < p.llistat[i].size() ; j++)	
			os << p.llistat[i][j] << " ";
		
		if (p.PC == i)				os << " <- PC";

		os << endl;
	}
	
	os << "--------------------------------" << endl;
	
	return os;
};

istream& operator>>(istream& is, Programa& programa)
{	
	string linia;
	
	getline(is,linia);
	while (linia != "FINAL_PROGRAMA")
	{
		vector<string> llista = programa.parse(linia);		
		programa.llistat.push_back(llista);
		getline(is,linia);
	}
	
	return is;
};