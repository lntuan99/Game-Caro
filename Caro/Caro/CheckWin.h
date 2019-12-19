#include "myUtility.h"
#pragma once 

#define maxRow 19
#define maxColum 32

int Up(char chessBoard[maxRow][maxColum], int y, int x, char ch, int &check);

int Up_Left(char chessBoard[maxRow][maxColum], int y, int x, char ch, int &check);

int Up_Right(char chessBoard[maxRow][maxColum], int y, int x, char ch, int &check);

int Down(char chessBoard[maxRow][maxColum], int y, int x, char ch, int &check);

int Down_Left(char chessBoard[maxRow][maxColum], int y, int x, char ch, int &check);

int Down_Right(char chessBoard[maxRow][maxColum], int y, int x, char ch, int &check);

int Left(char chessBoard[maxRow][maxColum], int y, int x, char ch, int &check);

int Right(char chessBoard[maxRow][maxColum], int y, int x, char ch, int &check);

bool WinGame(char chessBoard[maxRow][maxColum], Player player, char ch);

