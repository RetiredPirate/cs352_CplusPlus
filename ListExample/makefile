all: test

test: main.o IntList.o IntListNode.o
	g++ -o test main.o IntList.o IntListNode.o

main.o: main.cpp IntList.h debug.h
	g++ -c main.cpp

IntList.o: IntList.cpp IntList.h IntListNode.h debug.h
	g++ -c IntList.cpp

IntListNode.o: IntListNode.cpp IntListNode.h debug.h
	g++ -c IntListNode.cpp

clean:
	rm -f *.o test
