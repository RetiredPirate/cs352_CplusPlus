all: test

test: main.o map.o treeNode.o
	g++ -o test main.o map.o treeNode.o

map.o: map.cpp map.h treeNode.h
	g++ -c map.cpp

treeNode.o: treeNode.cpp treeNode.h
	g++ -c treeNode.cpp

main.o: main.cpp map.h
	g++ -c main.cpp

clean:
	/bin/rm -rf test *.o
