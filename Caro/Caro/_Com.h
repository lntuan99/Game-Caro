#include "CheckWin.h"
#include <stack>

using namespace std;

#define maxBreadth 12

Node getMaxNode();

void Computer(char chessBoard[maxRow][maxColum], int point, bool &EndGame, int maxDepth, stack<Node> &MOVE);

void resetMatrix(long maxtrixpoint[maxRow][maxColum]);

void scoreBoard(char chessBoard[maxRow][maxColum], char player);

void Move(char chessBoard[maxRow][maxColum], int maxDepth);

void getGenResult(char chessBoard[maxRow][maxColum], int maxDepth);
