all: test

test: main.o instantiate.o
	g++ -o test main.o instantiate.o

instantiate.o: instantiate.cpp map.cpp map.h treeNode.cpp treeNode.h 
	g++ -c instantiate.cpp

main.o: main.cpp map.h
	g++ -c main.cpp

clean:
	/bin/rm -rf test *.o
