#include <iostream>
#include "Board.H"
#include "RunGame.h"

using namespace std;

int main(int argc, char *argv[])
{
  RunGame newGame; //creates a RunGame Object
  newGame.startGame(); //Call startGame to run the Game of Life!
  return 0;
}
