
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11


########################################################################
# TEST de la classe Dispositiu.
########################################################################

program.exe: program.o dispositiu.o
	g++ -o program.exe program.o dispositiu.o	

program.o: program.cpp 
	g++ -c program.cpp $(OPCIONS)
	
dispositiu.o: dispositiu.cpp dispositiu.hpp 
	g++ -c dispositiu.cpp -o dispositiu.o $(OPCIONS)

clean:
	rm *.o *.exe *.gv *.pdf *.cor
