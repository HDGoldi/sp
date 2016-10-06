all: beispiell beispielll

clean:
	rm -f beispiell

beispiell: beispiel.cpp matrixcoo.hpp matrixcoo.cpp matrixcsr.hpp matrixcsr.cpp vector.hpp vector.cpp matrixcds.hpp matrixcds.cpp
	g++ -std=c++11 -Wall -ggdb -O3 -o beispiell beispiel.cpp matrixcoo.cpp matrixcsr.cpp vector.cpp matrixcds.cpp

beispielll: beispiel1.cpp matrixcoo.hpp matrixcoo.cpp matrixcsr.hpp matrixcsr.cpp vector.hpp vector.cpp matrixcds.hpp matrixcds.cpp
	g++ -std=c++11 -Wall -ggdb -O3 -o beispielll beispiel1.cpp matrixcoo.cpp matrixcsr.cpp vector.cpp matrixcds.cpp