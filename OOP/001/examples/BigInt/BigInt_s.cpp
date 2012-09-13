/*
  BigInt_s.cpp

  Syntax checking program for BigInt class

  Michael L. Collard
  collard@uakron.edu
*/

#include "BigInt.hpp"
#include <iostream>

int main() {

  BigInt b;
  BigInt b2 = b;
  BigInt b3(b2);

  b2 = b3;

  BigInt c(21);

  std::cout << c;

  int s = c.size();

  // immediate add
  b2 += b3;

  b2 += b3 += c;

  // plain old add
  b2 + b3;
  c = b2 + b3;
  b2 + b3 + b3;

  return 0;
}
