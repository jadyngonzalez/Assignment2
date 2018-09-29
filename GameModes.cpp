#include <iostream>
#include "GameModes.h"

using namespace std;

GameModes::GameModes() //setting default to Random board on classic mode with terminal output
{
  setType('C');
  setMode('R');
  setOutput('P');
}

GameModes::GameModes(char t, char m, char o)
{
  setType(t);
  setMode(m);
  setOutput(o);
}

GameModes::~GameModes()
{

}

//functions to set the game type mode and output
void GameModes::setType(char t)
{
  if(t == 'C' || t == 'D' || t == 'M')
  {
    this->boardType = t;
  }
  else
  {
    cout << "Invalid response." << endl;
    exit(0);
  }
}

void GameModes::setMode(char m)
{
  if(m == 'R' || m == 'F')
  {
    this->gameType = m;
  }
  else
  {
    cout << "Invalid response." << endl;
    exit(0);
  }
}

void GameModes::setOutput(char o)
{
  if(o == 'E' || o == 'F' || o == 'P')
  {
    this->outputType = o;
  }
  else
  {
    cout << "Invalid response." << endl;
    exit(0);
  }
}

char GameModes::type()
{
  return this->boardType;
}

char GameModes::mode()
{
  return this->gameType;
}

char GameModes::output()
{
  return this->outputType;
}
