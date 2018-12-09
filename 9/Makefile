CXXFLAGS=-std=c++11

main: main.o funcs.o
	g++ -o main main.o funcs.o

main.o: main.cpp funcs.h
	g++ $(CXXFLAGS) -c main.cpp

funcs.o: funcs.cpp funcs.h
	g++ $(CXXFLAGS) -c funcs.cpp

clean:
	rm -f *.o main
