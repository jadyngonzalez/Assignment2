//used to run each type of game and output results for the game.
#ifndef GameDriver_H
#define GameDriver_H
#include "Board.h"
#include "GameModes.h"

using namespace std;

class GameDriver
{
  public:
    GameDriver();
    ~GameDriver();

    //using these methods to start the various game modes
    void startClassic(GameModes);
    void startDoughnut(GameModes);
    void startMirror(GameModes);
    void createBoard(Board);
    void buildAll(int, int);
    void randomize(int, int, double);

  private:

    //methods for the various output settings
    void toFile();
    void proceedEnter();
    void proceedPause();
    void updateGame();

    Board current;
    Board next;
    Board copy;
    int generation;
};
#endif
