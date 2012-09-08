##
# Build scores

all : scores

scores : scores.o math.o
	g++ scores.o math.o -o scores

scores.o : scores.cpp
	g++ -c scores.cpp

math.o : math.cpp
	g++ -c math.cpp

run :
	./scores

clean :
	rm -f math.o scores.o scores

