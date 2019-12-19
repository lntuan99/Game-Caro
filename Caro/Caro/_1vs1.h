#include "CheckWin.h"
#include "Menu.h"
#include <stack>

#pragma once
using namespace std;

void initPlayer(Player &player1, Player &player2, Location &old1, Location &old2);

void Update(Player player1, Player player2, Location old1, Location old2, char chessBoard[maxRow][maxColum], int luot_danh, bool Xwin, bool Owin, bool EndGame, bool &restart);

void Control(Player &player1, Player &player2, Location &old1, Location &old2, bool &control, char chessBoard[maxRow][maxColum], int &luot_danh, bool &Xwin, bool &Owin, bool &EndGame, bool &restart, stack<Node> &Move, bool &quit, bool &sound);

void _1vs1(char chessBoard[maxRow][maxColum], bool &restart, bool &sound);