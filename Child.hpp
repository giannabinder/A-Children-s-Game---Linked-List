// encircle in define conditionals to ensure it is only run once
#ifndef _CHILD_HPP_
#define _CHILD_HPP_

// include libraries and header files
#include <iostream>
#include "Child.hpp"

class Child {
  private:
    Child(double x, double y, Child *p_next_child); // declare custom constructor   
    void _compute_distance(); // make helper function to compute distance 

    // declare member variables
    double _x, _y;
    double _distance = 0;
    bool _distance_updated;
    Child *_p_next;

  friend class List; // allow List class to access all members
};

#endif // end definition