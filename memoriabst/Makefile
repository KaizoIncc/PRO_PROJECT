
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11


########################################################################
# TEST de la classe memoriaBST.
########################################################################

program.exe: program.o memoria.o
	g++ -o program.exe program.o memoria.o	

program.o: program.cpp 
	g++ -c program.cpp $(OPCIONS)
	
memoria.o: memoriaBST.cpp memoriaBST.hpp BST.hpp BST.cpp 
	g++ -c memoriaBST.cpp -o memoria.o $(OPCIONS)

clean:
	rm *.o *.exe *.gv *.pdf *.cor
