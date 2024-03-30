// include libraries and header files
#include <iostream>
#include "List.hpp"
#include "parser.hpp"

using namespace std;

Parser::Parser(){
    _parse();
    return;
}

void Parser::_parse(){
  string cmd;
  List game; // create object of type List

  // PARSER: continually loop the following code, take in input, and call the appropriate functions
  while (cin >> cmd) {

    if (cmd == "SPAWN") {
      double x, y;
      cin >> x >> y;
      game.spawn(x, y);
    }

    else if (cmd == "TIME") {
      double t;
      cin >> t;
      game.time(t);
    }

    else if (cmd == "NUM") { game.number(); }

    else if (cmd == "PRT") {
      double D;
      cin >> D;
      game.print(D);
    }

    else {
      game.over();
      return; // end execution
    }
  }
}