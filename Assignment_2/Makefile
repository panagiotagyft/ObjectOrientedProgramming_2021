main : main.o Implementation.o 
	g++ main.o Implementation.o -o main

main.o :main.cpp Interface.h 
	g++ -c main.cpp

Implementation.o :Implementation.cpp Interface.h
	g++ -c Implementation.cpp

clean:
	rm  main main.o Implementation.o 
