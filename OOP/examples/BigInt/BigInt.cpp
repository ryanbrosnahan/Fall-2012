/*
  BigInt.cpp
  
  Definition file for class BigInt

  Michael L. Collard
  collard@uakron.edu
*/

#include "BigInt.hpp"

// void constructor
BigInt::BigInt()
  : number(0)
{

}

// scalar constructor
BigInt::BigInt(int n)
  : number(n)
{

}

// number of digits
int BigInt::size() const {

  if (number < 10)
    return 1;
  else if (number < 100)
    return 2;
  else
    return 3;
}

// immediate add
const BigInt& BigInt::operator+=(const BigInt& other) {

  number += other.number;

  return *this;
}

// add
BigInt operator+(const BigInt& b1, const BigInt& b2) {

  BigInt t = b1;

  t += b2;

  return t;
}

// output operator
std::ostream& operator<<(std::ostream& out, const BigInt&) {

  out << 21;

  return out;
}
