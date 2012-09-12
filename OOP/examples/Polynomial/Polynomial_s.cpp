/*
  Polynomial_s.cpp

  Syntax checking program for Polynomial class

  Michael L. Collard
  collard@uakron.edu
*/

#include "Polynomial.hpp"
#include <iostream>

int main() {

  Polynomial q;
  Polynomial q2 = q;
  Polynomial q3(q);

  q2 = q;

  Polynomial c(5);

  std::cout << c << '\n';

  c == c;

  c != c;

  return 0;
}
