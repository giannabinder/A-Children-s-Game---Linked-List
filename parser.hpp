// encircle in define conditionals to ensure it is only run once
#ifndef _PARSER_HPP_
#define _PARSER_HPP_

// include libraries and header files
#include <iostream>
#include "Child.hpp"

class Parser {
  public:
    Parser();
  private:
    void _parse();
};

#endif // end definition