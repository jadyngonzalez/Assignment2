#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include "GameModes.h"
#include "GameDriver.h"
#include "RunGame.h"

using namespace std;

RunGame::RunGame()
{

}

RunGame::~RunGame()
{

}

void RunGame::randomize(int r, int c, double p) //randomly fills the board
{
  current.setRow(r);
  current.setCol(c);
  copy.setRow(r);
  copy.setCol(c);
  next.setRow(r);
  next.setCol(c);

  for(int i = 0; i < current.getRow(); ++i)
  {
    for(int j = 0; j < current.getCol(); ++j)
    {
      double c = ((double) rand() / (RAND_MAX));
      if(c < p)
      {
        current.set(i, j, 'X');
      }
      else
      {
        current.set(i, j, '-');
      }
    }
  }
}

void RunGame::inputFile(string fileName) //get file from user
{
  if(!ifstream(fileName))
  {
    cout << "Invalid response, exiting." << endl;
    exit(0);
  }
  else
  {
    ifstream fileName;
    int r, c;
    string p;
    fileName >> r;
    fileName >> c;

    current.setRow(r);
    current.setCol(c);
    copy.setRow(r);
    copy.setCol(c);
    next.setRow(r);
    next.setCol(c);

    for(int i = 0; i < current.getRow(); ++i)
    {
      fileName >> p;
      for(int j = 0; j < current.getCol(); ++j)
      {
        current.set(i, j, p[j]);
      }
    }
    fileName.close();
  }
}

void RunGame::startGame() //This Method handles all the classes and runs the entire game based on the users input
{
  GameModes myGamemode;
  GameDriver driver;
  generation = 0;
  char input;

  cout << "This program simulates Conway's Game of Life." << endl;
  cout << "Do you want a random world (R) or do you want to provide one (F)?" << endl;
  cin >> input;
  myGamemode.setMode(input);

  switch(myGamemode.mode())
  {
    case 'R':
      int r, c;
      double p;
      cout << "Enter the rows." << endl;
      cin >> r;
      cout << "Enter the columns." << endl;
      cin >> c;
      cout << "Enter the population density." << endl;
      cin >> p;

      randomize(r, c, p);
      current.print();
      break;
    case 'F':
      cout << "Enter the text file name." << endl;
      string fileName;
      cin >> fileName;
      inputFile(fileName);
      break;
  }

  cout << "Enter the game type (C)lassic, (D)oughnut, (M)irror." << endl;
  cin >> input;
  myGamemode.setType(input);
  cout << "Enter the output mode (E)nter, (P)ause, (F)ile." << endl;
  cin >> input;
  myGamemode.setOutput(input);

  switch(myGamemode.type())
  {
    case 'C':
      if(myGamemode.output() != 'F')
      {
        cout << generation << endl;
        current.print();
      }
      driver.buildAll(current.getRow(), current.getCol());
      driver.createBoard(current);
      driver.startClassic(myGamemode);
      break;
    case 'D':
      if(myGamemode.output() != 'F')
      {
        cout << generation << endl;
        current.print();
      }
      driver.buildAll(current.getRow(), current.getCol());
      driver.createBoard(current);
      driver.startDoughnut(myGamemode);
    case 'M':
      if(myGamemode.output() != 'F')
      {
        cout << generation << endl;
        current.print();
      }
      driver.buildAll(current.getRow(), current.getCol());
      driver.createBoard(current);
      driver.startMirror(myGamemode);
  }
}
