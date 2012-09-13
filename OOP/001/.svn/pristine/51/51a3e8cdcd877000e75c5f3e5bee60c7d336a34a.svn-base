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

  // equality
  c == c;

  // inequality
  c != c;

  // immediate addition
  Polynomial p1(1);
  Polynomial p2(2);

  p1 += p2;

  // addition
  p1 + p2;

  // access coefficients base on degree of term
  p1.coefficient(0);

  // linear constructor
  Polynomial linear(2, -4);

  // quadratic constructor
  Polynomial quad(2, -4, 3);

  // vector constructor
  // vector constructor
  std::vector<double> coeffs(4);
  coeffs[0] = 1; coeffs[1] = 0; coeffs[2] = -1;
  Polynomial poly(coeffs);

  return 0;
}
