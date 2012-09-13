/*
  BigInt.hpp
  
  Include file for class BigInt

  Michael L. Collard
  collard@uakron.edu
*/

#ifndef INCLUDED_BIGINT_HPP
#define INCLUDED_BIGINT_HPP

#include <iostream>

class BigInt {
public:

  // void constructor
  BigInt();

  // scalar constructor
  BigInt(int);

  // number of digits
  int size() const;

  // immediate add
  const BigInt& operator+=(const BigInt&);
  
private:
  friend std::ostream& operator<<(std::ostream&, const BigInt&);
  int number;
};

// add
BigInt operator+(const BigInt&, const BigInt&);

// output operator
std::ostream& operator<<(std::ostream&, const BigInt&);

#endif
