// include libraries and header files
#include <cmath>
#include <iostream>
#include "Child.hpp"
#include "List.hpp"

using namespace std;

// initialize list with no contents
List::List() {
  this-> _p_head = nullptr;
  this-> _num_children = 0;
  return;
}

List::~List() {
  Child *p_temp = _p_head;

  // go through the list and delete all nodes
  while (p_temp) {
    _p_head = _p_head-> _p_next;
    delete p_temp;
    p_temp = _p_head;
  }

  // set pointers to null to avoid dangling pointers
  _p_head = nullptr;
  p_temp = nullptr;
  return;
}

void List::spawn(double x, double y){

  // check if child is out of bounds
  if ( (x <= 0) || (y <= 0) ) {
    cout << "failure\n";
    return;
  }

  else {

    // if the list is empty, make this child the head of the list
    // initialize their pointer to null as there are no other children
    if ( !(_p_head)) { _p_head = new Child(x, y, nullptr); }

    // if the list is populated, push them to the front of the list
    else {
      Child *p_new_child = new Child(x, y, _p_head);
      _p_head = p_new_child;
      p_new_child = nullptr; // set pointers to null to avoid dangling pointers
    }

    cout << "success\n"; 
    ++_num_children; // increment child counter
    return;
  }
}

void List::_pop(Child **p_traverse, Child **p_trail) {

  // if the child needs to be removed from the front of the list
  // do not move the list by moving p_head to the next node
  if (*p_traverse == _p_head){
    _p_head = _p_head-> _p_next;
    delete *p_traverse;
    *p_traverse = _p_head;
    *p_trail = _p_head;
  }

  // if the child to be removed is not at the front of the list
  // ensure the previous node points to the second next node
  else{
    (*p_trail)-> _p_next = (*p_traverse)-> _p_next;
    delete *p_traverse;
    *p_traverse = (*p_trail)-> _p_next;
  } 

  --_num_children; // decrement child counter
  return;
}


void List::time(double t) {

  // if there are children left in the game and time is not zero, updates need to be computed
  if ( t && _num_children ) { 
    
    // declare pointers to help go through the list
    Child* p_traverse = _p_head;
    Child* p_trail = _p_head;
  
    // if time is strictly negative
    if (t < 0){

      // go through the entire list     
      while ( p_traverse){
  
        // calculate the child's distance from the wolf if their data is not updated
        if (p_traverse-> _distance_updated == false){ p_traverse-> _compute_distance(); }

         // remove the child from the list if they are strictly less than a metre from the wolf
        if (p_traverse-> _distance < 1) { _pop(&p_traverse, &p_trail); }
        
        // if the child is still in the game, move the pointers along the list
        else { 
          p_trail = p_traverse;
          p_traverse = p_traverse-> _p_next;
        }
      }
    }
  
    // if time is positive, update all the children's distances
    else {
  
      // go through the entire list and update the children's status
      while ( p_traverse ){

        // determine how much the children must move in both directions
        double temporary = atan2(p_traverse->_y, p_traverse->_x);
        double move_x = t * cos(temporary);
        double move_y = t * sin(temporary);
  
        // if the child moves out of bounds, remove them from the game
        if ((move_x >= (p_traverse->_x)) || (move_y >= (p_traverse->_y))) { _pop(&p_traverse, &p_trail); }
  
        // update the children's positions
        else{
          p_traverse-> _x -= move_x;
          p_traverse-> _y -= move_y;
          p_traverse-> _distance_updated = false; // update the boolean for whether the new distance was updated
  
          // move the pointers along
          p_trail = p_traverse;
          p_traverse = p_traverse->_p_next;
        }
      }
    } 

    // set pointers to null to avoid dangling pointers
    p_trail = nullptr;
    p_traverse = nullptr;
  }

  number(); // print the number of children remaining in the game
  return;
}

void List::number() {
  cout << "number of children still playing: " << _num_children << endl; // print the number of children in the game
  return;
}

void List::print(double D) {

  bool in_range = false; // create a boolean to determine is there were children within the distance after the while loop
  
  // if there are children in the game and D is poicitive, indicating a position in quadrant 1
  if ( (_num_children) || (D > 0) ) {
    
    Child *p_traverse = _p_head; // create a function to go through the list
  
    // go through the linked list
    while (p_traverse != nullptr) {
  
      if ( !(p_traverse-> _distance_updated)) { p_traverse->_compute_distance(); } // update the child's distance is needed
  
      // if the child is within D, print their coordinates and update the boolean
      if ( (p_traverse-> _distance) < D) {
        cout << p_traverse-> _x << " " << p_traverse-> _y << " ";
        in_range = true;
      }
  
      p_traverse = (p_traverse-> _p_next); // move the pointer along the list
    }

    p_traverse = nullptr; // set pointer to null to avoid dangling pointers
  }
 
  // if there are no children in the game, D is not a valid distance from the wolf, or all the children's distances are greater than D
  if ( !(in_range) || !(_num_children) || (D <= 0) ) { cout << "no children within distance"; }

  cout << endl; // ensure the next output prints to the next line
  return;
}

void List::over() {
  if (_num_children > 0) { cout << "the players win\n"; } 
  else { cout << "the wolf wins\n";}
  return;
}