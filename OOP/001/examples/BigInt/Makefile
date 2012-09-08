##
# Build BigInt

.PHONY : all
all : BigInt_s BigInt_t

BigInt_s : BigInt_s.o BigInt.o
	g++ $^ -o $@

BigInt_t : BigInt_t.o BigInt.o
	g++ $^ -o $@

BigInt_s.o : BigInt_s.cpp BigInt.hpp
	g++ -c $<

BigInt_t.o : BigInt_t.cpp BigInt.hpp
	g++ -c $<

BigInt.o : BigInt.cpp BigInt.hpp
	g++ -c $<

.PHONY : syntax
syntax : BigInt_s
	./BigInt_s

.PHONY : text
test : BigInt_t
	./BigInt_t

.PHONY : clean
clean :
	rm -f BigInt_s BigInt_s.o BigInt_t BigInt_t.o BigInt.o

