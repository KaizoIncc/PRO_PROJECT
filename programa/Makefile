
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

all: program.exe

########################################################################
# TEST de la classe Dispositiu.
########################################################################

program.exe: program.o programa.o dispositiu.o memoriaBST.o
	g++ -o program.exe program.o programa.o dispositiu.o memoriaBST.o

program.o: program.cpp programa.hpp dispositiu.hpp memoriaBST.hpp BST.hpp
	g++ -c program.cpp $(OPCIONS)
	
programa.o: programa.cpp programa.hpp dispositiu.hpp memoriaBST.hpp BST.hpp BST.cpp
	g++ -c programa.cpp $(OPCIONS)	

dispositiu.o: dispositiu.cpp dispositiu.hpp 
	g++ -c dispositiu.cpp -o dispositiu.o $(OPCIONS)

memoriaBST.o: memoriaBST.cpp memoriaBST.hpp BST.cpp BST.hpp
	g++ -c memoriaBST.cpp -o memoriaBST.o $(OPCIONS)

clean:
	rm *.o *.exe *.gv *.pdf *.cor
