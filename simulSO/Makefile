
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

all: program.exe

########################################################################
# Pràctica "Simulació d'un SO".
########################################################################

program.exe: program.o so.o programa.o dispositiu.o processador.o memoriaBST.o
	g++ -o program.exe program.o so.o programa.o dispositiu.o processador.o memoriaBST.o

program.o: program.cpp programa.hpp dispositiu.hpp memoriaBST.hpp BST.hpp
	g++ -c program.cpp $(OPCIONS)
	
so.o: so.cpp so.hpp 
	g++ -c so.cpp $(OPCIONS)	
	
processador.o: processador.cpp processador.hpp programa.hpp dispositiu.hpp PriorityQueue.hpp
	g++ -c processador.cpp $(OPCIONS)	
	
programa.o: programa.cpp programa.hpp dispositiu.hpp memoriaBST.hpp BST.hpp BST.cpp
	g++ -c programa.cpp $(OPCIONS)	

dispositiu.o: dispositiu.cpp dispositiu.hpp 
	g++ -c dispositiu.cpp -o dispositiu.o $(OPCIONS)

memoriaBST.o: memoriaBST.cpp memoriaBST.hpp BST.cpp BST.hpp
	g++ -c memoriaBST.cpp -o memoriaBST.o $(OPCIONS)

clean:
	rm *.o *.exe *.gv *.pdf *.cor

