##
# Build hello

all : test

test : test.o
	g++ test.o -o test

test.o : test.cpp
	g++ -c test.cpp -std=c++0x

clean :
	rm -f test.o test
