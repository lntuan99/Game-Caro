#include <stdio.h>
#include <conio.h>
#include "myUtility.h"
#include "Frame.h"
#include "console.h"

#define FrameMenuWidth 130
#define FrameMenuHeight 40

void FrameMenu();

void ContentMenu(int chooseMenu, bool sound);

void ControlMenu(int &chooseMenu, int &selectMenu, bool sound);

void Help();

void Infor();

void ControlStart(int &chooseStart, int &selectStart, bool sound);

void Start(int chooseStart);

void ControlLV(int &chooseLV, int &selectLV, bool sound);

void Level(int chooseLV);

void ControlTurn(int &chooseTurn, int &selectTurn, bool sound);

void Turn(int chooseTurn);

void ControlEsc(int &chooseEsc, int &selectEsc, bool sound);

void Esc(int chooseEsc, bool sound);

void mainEsc(char chessBoard[maxRow][maxColum], bool &quit, bool &sound, bool Com);