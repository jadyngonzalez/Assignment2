//this class will be running the simulation for the game and all its modes
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include "GameDriver.h"
#include "GameModes.h"

using namespace std;

GameDriver::GameDriver()
{

}

GameDriver::~GameDriver()
{

}

void GameDriver::buildAll(int r, int c)//creates all three boards that we need for updating generations
{
  current.setRow(r);
  current.setCol(c);
  copy.setRow(r);
  copy.setCol(c);
  next.setRow(r);
  next.setCol(c);
}

void GameDriver::createBoard(Board aBoard)
{
  for(int i = 0; i < aBoard.getRow(); ++i)
  {
    for(int j = 0; j < aBoard.getCol(); ++j)
    {
      this->current.set(i, j, aBoard.pull(i, j));
    }
  }
}

void GameDriver::updateGame()//updates the boards for the next generation
{
  for(int i = 0; i < current.getRow(); ++i)
  {
    for(int j = 0; i < current.getCol(); ++i)
    {
      current.set(i, j, next.pull(i, j));
    }
  }
  ++generation;
}


//Methods to set the different output types
void GameDriver::proceedEnter()
{
  if(generation > 1)
  {
    cout << "Hit Enter to start next generation." << endl;
  }
  getchar();
  cout << generation << endl;
  current.print();
}

void GameDriver::proceedPause()
{
  usleep(1000000);
  cout << generation << endl;
  current.print();
}

void GameDriver::toFile()
{
  ofstream outputFile;

  outputFile.open("GameOfLife.txt");
  outputFile << generation << "\n";

  for(int i = 0; i < current.getRow(); ++i)
  {
    for(int j = 0; j < current.getCol(); j++)
    {
      outputFile << current.pull(i, j);
    }
    outputFile << "\n";
  }
  outputFile.close();
}


//starts Classic gamemode
void GameDriver::startClassic(GameModes myGamemode)
{
  do
  {
    int copies = 0;
    int cells = 0;

    for(int i = 0; i < current.getRow(); ++i)
    {
      for(int j = 0; j < current.getCol(); ++j)
      {
        if(copy.pull(i, j) == current.pull(i, j))
        {
          copies++;
        }

        cells = current.countClassic(current, i, j);

        if(cells < 2 || cells >= 4)
        {
          next.set(i, j, '-');
        }
        else if(cells == 3)
        {
          next.set(i, j, 'X');
        }
        else
        {
          next.set(i, j, current.pull(i, j));
        }
      }
    }

    for(int i = 0; i < current.getRow(); ++i)
    {
      for(int j = 0; j < current.getCol(); ++j)
      {
        copy.set(i, j, current.pull(i, j));
      }
    }
    updateGame();
    if(copies == current.getCol() * current.getRow())
    {
      cout << "Repeated Generation." << endl;
      break;
    }

    switch(myGamemode.output())
    {
      case 'E':
        proceedEnter();
        break;
      case 'P':
        proceedPause();
        break;
      case 'F':
        toFile();
        break;
    }
  }while(!current.cEmpty());

  cout << "Hit enter to exit the game." << endl;
  getchar();
}

//starts Doughnut GameMode
void GameDriver::startDoughnut(GameModes myGamemode)
{
  do
  {
    int copies = 0;
    int cells = 0;

    for(int i = 0; i < current.getRow(); ++i)
    {
      for(int j = 0; j < current.getCol(); ++i)
      {
        if(copy.pull(i, j) == current.pull(i, j))
        {
          ++copies;
        }

        cells = current.countDoughnut(current, i, j);

        if(cells < 2 || cells >= 4)
        {
          next.set(i, j, '-');
        }
        else if(cells == 3)
        {
          next.set(i, j, 'X');
        }
        else
        {
          next.set(i, j, current.pull(i, j));
        }
      }
    }

    for(int i = 0; i < current.getRow(); ++i)
    {
      for(int j = 0; j < current.getCol(); ++j)
      {
        copy.set(i, j, current.pull(i, j));
      }
    }
    updateGame();
    if(copies == current.getCol() * current.getRow())
    {
      cout << "Repeated Generation." << endl;
      break;
    }

    switch(myGamemode.output())
    {
      case 'E':
        proceedEnter();
        break;
      case 'P':
        proceedPause();
        break;
      case 'F':
        toFile();
        break;
    }
  }while(!current.cEmpty());
  cout << "Hit enter to exit the game." << endl;
  getchar();
}

//Starts Mirror Game Mode
void GameDriver::startMirror(GameModes myGamemode)
{
  generation = 0;

  do
  {
    int copies = 0;
    int cells = 0;

    for(int i = 0; i < current.getRow(); ++i)
    {
      for(int j = 0; j < current.getCol(); ++j)
      {
        if(copy.pull(i, j) == current.pull(i, j))
        {
          copies++;
        }

        cells = current.countMirror(current, i, j);

        if(cells < 2 || cells >= 4)
        {
          next.set(i, j, '-');
        }
        else if(cells == 3)
        {
          next.set(i, j, 'X');
        }
        else
        {
          next.set(i, j, current.pull(i, j));
        }
      }
    }

    for(int i = 0; i < current.getRow(); ++i)
    {
      for(int j = 0; j < current.getCol(); ++j)
      {
        copy.set(i, j, current.pull(i, j));
      }
    }
    updateGame();
    if(copies == current.getCol() * current.getRow())
    {
      cout << "Repeated Generation." << endl;
      break;
    }

    switch(myGamemode.output())
    {
      case 'E':
        proceedEnter();
        break;
      case 'P':
        proceedPause();
        break;
      case 'F':
        toFile();
        break;
    }
  }while(!current.cEmpty());

  cout << "Hit enter to exit the game." << endl;
  getchar();
}
