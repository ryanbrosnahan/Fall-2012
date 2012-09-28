##
# Build hello

all : main

main : main.o
	g++ main.o -o main

main.o : main.cpp
	g++ -c main.cpp -std=c++0x

clean :
	rm -f main.o main
