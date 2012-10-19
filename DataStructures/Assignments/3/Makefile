##
# Build hello

all : test

test : test.o
	g++ test.o -o test

test.o : test.cpp
	g++ -c test.cpp

clean :
	rm -f test.o test
