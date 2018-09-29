#include <iostream>
#include "Board.h"

using namespace std;

Board::Board() //Default
{
  rows = 3;
  cols = 3;
  build(rows, cols);
}

Board::Board(int r, int c) //Random field constructor
{
  setRow(r);
  setCol(c);
  build(rows, cols);
}

Board::~Board()
{
  for(int i = 0; i < rows; i++)
  {
    delete playBoard[i];
  }
  delete playBoard;
  cout << "Board Deleted." << endl;
}

//need a function build that will build our game board and initialize all indices to '-'
void Board::build(int r, int c)
{
  playBoard = new char*[r];
  for(int i = 0; i < r; ++i)
  {
    playBoard[i] = new char[c];
    for(int j = 0; j < c; ++j)
    {
      playBoard[i][j] = '-';
    }
  }
}

//prints board, will use to display in terminal or output to file
void Board::print()
{
  for(int i = 0; i < rows; ++i)
  {
    for(int j = 0; j < cols; ++j)
    {
      cout << playBoard[i][j];
    }
    cout << "\n"; //new line to show board in a grid-like output
  }
}

//defining the rest of the functions from Board.h
int Board::getRow()
{
  return rows;
}

int Board::getCol()
{
  return cols;
}

void Board::setRow(int r)
{
  this->rows = r;
  build(rows, cols);
}

void Board::setCol(int c)
{
  this->cols = c;
  build(rows, cols);
}

char Board::pull(int r, int c)
{
  return playBoard[r][c];
}

void Board::set(int r, int c, char e)
{
  playBoard[r][c] = e;
}

//Methods for checking for neighbors on the board
bool Board::cEmpty()
{
  for(int i = 0; i < rows; ++i)
  {
    for(int j = 0; j < cols; ++j)
    {
      if(!(playBoard[i][j] == '-'))
      {
        return false;
      }
    }
  }
  return true;
}

bool Board::cRight(int r, int c)
{
  return (playBoard[r][c + 1] == 'X');
}

bool Board::cLeft(int r, int c)
{
  return (playBoard[r][c - 1] == 'X');
}

bool Board::cUp(int r, int c)
{
  return (playBoard[r - 1][c] == 'X');
}

bool Board::cDown(int r, int c)
{
  return (playBoard[r + 1][c] == 'X');
}

bool Board::cDiagRight_U(int r, int c)
{
  return (playBoard[r - 1][c + 1] == 'X');
}

bool Board::cDiagRight_D(int r, int c)
{
  return (playBoard[r + 1][c + 1] == 'X');
}

bool Board::cDiagLeft_U(int r, int c)
{
  return (playBoard[r - 1][c - 1] == 'X');
}

bool Board::cDiagLeft_D(int r, int c)
{
  return (playBoard[r + 1][c - 1] == 'X');
}

//Counting neighbors in Classic Mode
int Board::countClassic(Board b, int i, int j)
{
  int cells = 0;
  if(i == 0 && j == 0)
  {
    if(b.cRight(i, j))
    {
      ++cells;
    }
    if(b.cDown(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_D(i, j))
    {
      ++cells;
    }
  }

  else if(i == 0 && j == (b.getCol() - 1))
  {
    if(b.cLeft(i, j))
    {
      ++cells;
    }
    if(b.cDown(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_D(i, j))
    {
      ++cells;
    }
  }

  else if(i == 0)
  {
    if(b.cLeft(i, j))
    {
      ++cells;
    }
    if(b.cRight(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_D(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_D(i, j))
    {
      ++cells;
    }
    if(b.cDown(i, j))
    {
      ++cells;
    }
  }

  else if(i == (b.getRow() - 1) && j == 0)
  {
    if(b.cUp(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_U(i, j))
    {
      ++cells;
    }
    if(b.cRight(i, j))
    {
      ++cells;
    }
  }

  else if(i == (b.getRow() - 1) && j == (b.getCol() - 1))
  {
    if(b.cUp(i, j))
    {
      ++cells;
    }
    if(b.cLeft(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_U(i, j))
    {
      ++cells;
    }
  }

  else if(i == (b.getRow() - 1))
  {
    if(b.cUp(i, j))
    {
      ++cells;
    }
    if(b.cRight(i, j))
    {
      ++cells;
    }
    if(b.cLeft(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_U(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_U(i, j))
    {
      ++cells;
    }
  }

  else if(j == 0)
  {
    if(b.cUp(i, j))
    {
      ++cells;
    }
    if(b.cDown(i, j))
    {
      ++cells;
    }
    if(b.cRight(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_U(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_D(i, j))
    {
      ++cells;
    }
  }

  else if(j == (b.getCol() - 1))
  {
    if(b.cUp(i, j))
    {
      ++cells;
    }
    if(b.cDown(i, j))
    {
      ++cells;
    }
    if(b.cLeft(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_U(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_D(i, j))
    {
      ++cells;
    }
  }

  else
  {
    if(b.cUp(i, j))
    {
      ++cells;
    }
    if(b.cDown(i, j))
    {
      ++cells;
    }
    if(b.cRight(i, j))
    {
      ++cells;
    }
    if(b.cLeft(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_U(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_D(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_U(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_D(i, j))
    {
      ++cells;
    }
  }
  return cells;
}

//Counting Neighbors in Doughnut Mode
int Board::countDoughnut(Board b, int i, int j)
{
  int cells = 0;
  if(i == 0 && j == 0)
  {
    if(b.cRight(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_D(i, j))
    {
      ++cells;
    }
    if(b.cDown(i, j))
    {
      ++cells;
    }

    if(b.pull(b.getRow() - 1, j) == 'X')
    {
      ++cells;
    }
    if(b.pull(i, b.getCol() - 1) == 'X')
    {
      ++cells;
    }
    if(b.pull(b.getRow() - 1, j + 1) == 'X')
    {
      ++cells;
    }
    if(b.pull(b.getRow() - 1, b.getCol() - 1) == 'X')
    {
      ++cells;
    }
    if(b.pull(i + 1, b.getCol() - 1) == 'X')
    {
      ++cells;
    }
  }

  else if(i == 0 && j == (b.getCol() - 1))
  {
    if(b.cLeft(i, j))
    {
      ++cells;
    }
    if(b.cDown(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_D(i, j))
    {
      ++cells;
    }

    if(b.pull(b.getRow() - 1, j) == 'X')
    {
      ++cells;
    }
    if(b.pull(i, 0) == 'X')
    {
      ++cells;
    }
    if(b.pull(b.getRow() - 1, 0) == 'X')
    {
      ++cells;
    }
    if(b.pull(b.getRow() - 1, j - 1) == 'X')
    {
      ++cells;
    }
    if(b.pull(i + 1, 0) == 'X')
    {
      ++cells;
    }
  }

  else if(i == 0)
  {
    if(b.cLeft(i, j))
    {
      ++cells;
    }
    if(b.cRight(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_D(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_D(i, j))
    {
      ++cells;
    }
    if(b.cDown(i, j))
    {
      ++cells;
    }

    if(b.pull(b.getRow() - 1, j) == 'X')
    {
      ++cells;
    }
    if(b.pull(b.getRow() - 1, j + 1) == 'X')
    {
      ++cells;
    }
    if(b.pull(b.getRow() - 1, j - 1) == 'X')
    {
      ++cells;
    }
  }

  else if(i == (b.getRow() - 1) && j == 0)
  {
    if(b.cUp(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_U(i, j))
    {
      ++cells;
    }
    if(b.cRight(i, j))
    {
      ++cells;
    }

    if(b.pull(0,0) == 'X')
    {
      ++cells;
    }
    if(b.pull(i, b.getCol() - 1) == 'X')
    {
      ++cells;
    }
    if(b.pull(i - 1, b.getCol() - 1) == 'X')
    {
      ++cells;
    }
    if(b.pull(0,1) == 'X')
    {
      ++cells;
    }
    if(b.pull(0, b.getCol() - 1) == 'X')
    {
      ++cells;
    }
  }

  else if(i == (b.getRow() - 1) && j == (b.getCol() - 1))
  {
    if(b.cUp(i, j))
    {
      ++cells;
    }
    if(b.cLeft(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_U(i, j))
    {
      ++cells;
    }

    if(b.pull(0, j) == 'X')
    {
      ++cells;
    }
    if(b.pull(i, 0) == 'X')
    {
      ++cells;
    }
    if(b.pull(i - 1, 0) == 'X')
    {
      ++cells;
    }
    if(b.pull(0, 0) == 'X')
    {
      ++cells;
    }
    if(b.pull(0, j - 1) == 'X')
    {
      ++cells;
    }
  }

  else if(i == (b.getRow() - 1))
  {
    if(b.cUp(i, j))
    {
      ++cells;
    }
    if(b.cRight(i, j))
    {
      ++cells;
    }
    if(b.cLeft(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_U(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_U(i, j))
    {
      ++cells;
    }

    if(b.pull(0, j) == 'X')
    {
      ++cells;
    }
    if(b.pull(0, j + 1) == 'X')
    {
      ++cells;
    }
    if(b.pull(0, j - 1) == 'X')
    {
      ++cells;
    }
  }

  else if(j == 0)
  {
    if(b.cUp(i, j))
    {
      ++cells;
    }
    if(b.cDown(i, j))
    {
      ++cells;
    }
    if(b.cRight(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_U(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_D(i, j))
    {
      ++cells;
    }

    if(b.pull(i, b.getCol() - 1) == 'X')
    {
      ++cells;
    }
    if(b.pull(i - 1, b.getCol() - 1) == 'X')
    {
      ++cells;
    }
    if(b.pull(i + 1, b.getCol() - 1) == 'X')
    {
      ++cells;
    }
  }

  else if(j == (b.getCol() - 1))
  {
    if(b.cUp(i, j))
    {
      ++cells;
    }
    if(b.cDown(i, j))
    {
      ++cells;
    }
    if(b.cLeft(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_U(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_D(i, j))
    {
      ++cells;
    }

    if(b.pull(i, 0) == 'X')
    {
      ++cells;
    }
    if(b.pull(i - 1, 0) == 'X')
    {
      ++cells;
    }
    if(b.pull(i + 1, 0) == 'X')
    {
      ++cells;
    }
  }

  else
  {
    if(b.cUp(i, j))
    {
      ++cells;
    }
    if(b.cDown(i, j))
    {
      ++cells;
    }
    if(b.cRight(i, j))
    {
      ++cells;
    }
    if(b.cLeft(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_U(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_D(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_U(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_D(i, j))
    {
      ++cells;
    }
  }
  return cells;
}

//Counting Neighbors in MirrorMode
int Board::countMirror(Board b, int i, int j)
{
  int cells = 0;
  if(i == 0 && j == 0)
  {
    if(b.cRight(i, j))
    {
      cells += 2;
    }
    if(b.cDown(i, j))
    {
      cells += 2;
    }
    if(b.cDiagRight_D(i, j))
    {
      ++cells;
    }
    if(b.pull(0,0) == 'X')
    {
      cells += 3;
    }
  }

  else if(i == 0 && j == (b.getCol() - 1))
  {
    if(b.cLeft(i, j))
    {
      cells += 2;
    }
    if(b.cDown(i, j))
    {
      cells += 2;
    }
    if(b.cDiagLeft_D(i, j))
    {
      ++cells;
    }
    if(b.pull(i, j) == 'X')
    {
      cells += 3;
    }
  }

  else if(i == 0)
  {
    if(b.cLeft(i, j))
    {
      cells += 2;
    }
    if(b.cRight(i, j))
    {
      cells += 2;
    }
    if(b.cDiagLeft_D(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_D(i, j))
    {
      ++cells;
    }
    if(b.cDown(i, j))
    {
      ++cells;
    }
    if(b.pull(i, j) == 'X')
    {
      ++cells;
    }
  }

  else if(i == (b.getRow() - 1) && j == 0)
  {
    if(b.cUp(i, j))
    {
      cells += 2;
    }
    if(b.cDiagRight_U(i, j))
    {
      ++cells;
    }
    if(b.cRight(i, j))
    {
      cells += 2;
    }
    if(b.pull(i, j) == 'X')
    {
      cells += 3;
    }
  }

  else if(i == (b.getRow() - 1) && j == (b.getCol() - 1))
  {
    if(b.cUp(i, j))
    {
      cells += 2;
    }
    if(b.cLeft(i, j))
    {
      cells += 2;
    }
    if(b.cDiagLeft_U(i, j))
    {
      ++cells;
    }
    if(b.pull(i, j) == 'X')
    {
      cells += 3;
    }
  }

  else if(i == (b.getRow() - 1))
  {
    if(b.cUp(i, j))
    {
      ++cells;
    }
    if(b.cRight(i, j))
    {
      cells += 2;
    }
    if(b.cLeft(i, j))
    {
      cells += 2;
    }
    if(b.cDiagRight_U(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_U(i, j))
    {
      ++cells;
    }
    if(b.pull(i, j) == 'X')
    {
      ++cells;
    }
  }

  else if(j == 0)
  {
    if(b.cUp(i, j))
    {
      cells += 2;
    }
    if(b.cDown(i, j))
    {
      cells += 2;
    }
    if(b.cRight(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_U(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_D(i, j))
    {
      ++cells;
    }
    if(b.pull(i, j) == 'X')
    {
      ++cells;
    }
  }

  else if(j == (b.getCol() - 1))
  {
    if(b.cUp(i, j))
    {
      cells += 2;
    }
    if(b.cDown(i, j))
    {
      cells += 2;
    }
    if(b.cLeft(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_U(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_D(i, j))
    {
      ++cells;
    }
    if(b.pull(i, j) == 'X')
    {
      ++cells;
    }
  }

  else
  {
    if(b.cUp(i, j))
    {
      ++cells;
    }
    if(b.cDown(i, j))
    {
      ++cells;
    }
    if(b.cRight(i, j))
    {
      ++cells;
    }
    if(b.cLeft(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_U(i, j))
    {
      ++cells;
    }
    if(b.cDiagRight_D(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_U(i, j))
    {
      ++cells;
    }
    if(b.cDiagLeft_D(i, j))
    {
      ++cells;
    }
  }
  return cells;
}
