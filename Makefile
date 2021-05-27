################################
#
# MAKEFILE - Stack_LL
#
################################
StackTest: main.o StackTester.o
	g++ main.o StackTester.o -o StackTest

main.o: main.cpp StackTester.h
	g++ -g -c main.cpp

StackTester.o: StackTester.cpp Stack.h LinkedList.h Node.h
	g++ -g -c StackTester.cpp

.PHONY: clean
clean:
	rm *.o StackTest