#include "_Com.h"
#include "Menu.h"

void initPlayerVsCom(Player &player, Location &old);

void Control(Player &player, Location &old, bool &control, char chessBoard[maxRow][maxColum], int &luot_danh, bool &PlayerWin, bool &EndGame, int &point, stack<Node> &MOVE, bool &quit, bool &sound);

void Update(Player player, Location old, char chessBoard[maxRow][maxColum], int luot_danh, int count, bool PlayerWin, bool EndGame, bool &restart, bool sound);

long long Max(long long a, long long b);

void _1vsCom(Player &player, char chessBoard[maxRow][maxColum], int selectLV, int selectTurn, bool &restart, bool &sound);

