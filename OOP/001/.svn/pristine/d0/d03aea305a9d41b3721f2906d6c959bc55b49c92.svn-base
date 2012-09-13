##
# Build Polynomial

.PHONY : all
all : Polynomial_s Polynomial_t

Polynomial_s : Polynomial_s.o Polynomial.o
	g++ $^ -o $@

Polynomial_t : Polynomial_t.o Polynomial.o
	g++ $^ -o $@

Polynomial_s.o : Polynomial_s.cpp Polynomial.hpp
	g++ -c $<

Polynomial_t.o : Polynomial_t.cpp Polynomial.hpp
	g++ -c $<

Polynomial.o : Polynomial.cpp Polynomial.hpp
	g++ -c $<

.PHONY : syntax
syntax : Polynomial_s
	./Polynomial_s

.PHONY : text
test : Polynomial_t
	./Polynomial_t

.PHONY : clean
clean :
	rm -f Polynomial_s Polynomial_s.o Polynomial_t Polynomial_t.o Polynomial.o

