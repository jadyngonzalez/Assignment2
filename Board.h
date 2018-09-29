#ifndef Board_H
#define Board_H

using namespace std;

class Board
{
public:
  //constructors for the game board
  Board();
  Board(int, int); //used for random board of r rows and c columns
  ~Board();

  void print();
  //need getters and setters for the indices
  int getRow();
  int getCol();
  void setRow(int);
  void setCol(int);
  char pull(int, int); //return the element of specefied index
  void set(int, int, char); //place an element at the specified index

  //using bool return methods to check up,down,L,R and Diag of board rather than using an array of bools to track cells
  //(was running into issues setting values and printing board)
  //should return true if an 'X' is found in the check index

  bool cRight(int, int);
  bool cLeft(int, int);
  bool cUp(int, int);
  bool cDown(int, int);
  bool cDiagRight_U(int, int);
  bool cDiagRight_D(int, int);
  bool cDiagLeft_U(int, int);
  bool cDiagLeft_D(int, int);
  bool cEmpty();

  //methods to count neighbors in each gamemode
  int countClassic(Board b, int i, int j);
  int countDoughnut(Board b, int i, int j);
  int countMirror(Board b, int i, int j);

private:
  int rows;
  int cols;
  void build(int, int);
  char **playBoard;

};
#endif
