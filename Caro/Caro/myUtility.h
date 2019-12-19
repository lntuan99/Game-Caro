#include "console.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#pragma once

#define maxRow 19
#define maxColum 32

#define FrameMenuWidth 130
#define FrameMenuHeight 40

#define player1_color 64
#define player2_color 96
#define defautl_color 0

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER 13
#define ESC 27
#define SPACE 32

struct Node
{
	int row;
	int colum;
	long max;
};

struct Location
{
	int x;
	int y;
};

struct Player {
	Location local;
	int color = 7;
	int point = 0;
	std::string name = "";
};

void resizeConsole(int width, int height);

void XoaManHinhNho();

void Nocursortype(); // Xóa con trỏ

void FixConsoleWindow();

char getCharacterInChessBoard(char chessBoard[maxRow][maxColum], int y, int x);

void setCharacterInChessBoard(char chessBoard[maxRow][maxColum], int y, int x, char ch);

void GetDesktopResolution(int &horizontal, int &vertical);





