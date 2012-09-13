/*
  heightf1.cpp

  Timing for straightforward implementation of height function

  Michael L. Collard
  collard@uakron.edu
*/

#include <iostream>

double height(double starting_height, double initial_velocity, double time) {
  return starting_height + initial_velocity * time + -16 * time * time;
}

int main() {

  // height of object of time seconds
  for (int i = 0; i < 100000000; ++i)
    height(0, 80, 2.5);

  return 0;
}
