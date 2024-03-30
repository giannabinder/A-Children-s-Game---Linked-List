// include libraries and header files
#include <cmath>
#include <iostream>
#include "Child.hpp"
#include "List.hpp"

// define member variables
Child::Child(double x, double y, Child *p_next) {
  this-> _x = x;
  this-> _y = y;
  this-> _p_next = p_next;
  this-> _distance_updated = false;
  return;
}

void Child::_compute_distance() {
  this-> _distance = sqrt(pow(this->_x, 2) + pow(this->_y, 2));
  this-> _distance_updated = true; // update tracker
  return;
}