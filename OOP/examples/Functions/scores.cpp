/*
  scores.cpp

  Reports the result of taking two tests

  Michael L. Collard
  collard@uakron.edu
*/

#include <iostream>
#include "math.hpp"

int main() {

  // input the two test scores
  std::cout << "Enter the two test scores:  ";
  int test1;
  int test2;
  std::cin >> test1 >> test2;

  // output the result
  std::cout << "The result of your two tests is " << add(test1, test2) << '\n';

  return 0;
}

