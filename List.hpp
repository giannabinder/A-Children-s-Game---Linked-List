
// encircle in define conditionals to ensure it is only run once
#ifndef _LIST_HPP_
#define _LIST_HPP_

// include libraries and header files
#include <iostream>
#include "Child.hpp"

class List {
    
  // define members not accessible by main(); (helper functions and member variables)
  private:
    void _pop(Child **p_traverse, Child **p_trail); // create function to remove children from game
    Child *_p_head; // address to first child object
    std::size_t _num_children; // variable to store number of children playing

  // make these functions public so main() and Child objects' can access them
  public:
    List();
    ~List(); // destructor, de-allocate memory
    void spawn(double x, double y); // add a child into the game
    void time(double t); // update the children's position and standing in the game
    void number(); // output the number of children still playing the game
    void print(double D); // print children <D distance from wolf
    void over(); // ends all input files and the game
};

#endif // end definition