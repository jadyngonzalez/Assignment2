#ifndef RunGame_H
#define RunGame_H
#include <string>
#include "Board.h"
#include "GameModes.h"

using namespace std;

class RunGame
{
  public:
    RunGame();
    ~RunGame();
    void startGame();

  private:
    void randomize(int, int, double);
    void inputFile(string);

    int generation;
    Board current;
    Board copy;
    Board next;
};
#endif
