/*
  trajectory_t.cpp

  Test of trajectory functions.

  Michael L. Collard
  collard@uakron.edu
*/

#include <iostream>
#include "trajectory.hpp"
#include <cassert>

int main() {

  assert(height(0, 0, 0) == 0);
  assert(height(0, 80, 0) == 0);
  assert(height(0, 800000000, 0) == 0);

  assert(height(5, 0, 0) == 5);

  return 0;
}
