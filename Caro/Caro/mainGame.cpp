#include "mainGame.h"
#include <Windows.h>
#include <iostream>
using namespace std;

void initChessBoard(char chessBoard[maxRow][maxColum])
{
	int i, j;
	for (i = 0; i < maxRow; ++i)
		for (j = 0; j < maxColum; ++j)
			chessBoard[i][j] = ' ';
}

void play()
{
	bool restart, sound = true;
	Player player1, player2;
	int chooseMenu = 1, selectMenu = 0, chooseStart = 1, selectStart = 0, chooseLV = 1, selectLV = 0, chooseTurn = 1, selectTurn = 0;
	do
	{
		Nocursortype();
		FrameMenu();
		do
		{
			Nocursortype();
			ContentMenu(chooseMenu, sound);
			ControlMenu(chooseMenu, selectMenu, sound);

			if (selectMenu == 2)
			{
				Nocursortype();
				Help();
				while (_getch() != ENTER);
				XoaManHinhNho();
				selectMenu = 0;
			}

			if (selectMenu == 3)
			{
				Nocursortype();
				Infor();
				while (_getch() != ENTER);
				XoaManHinhNho();
				selectMenu = 0;
			}

			if (selectMenu == 4)
			{
				sound = !sound;
				selectMenu = 0;
			}
				

			while (selectMenu == 1)
			{
				Nocursortype();
				XoaManHinhNho();
				do
				{
					Start(chooseStart);
					ControlStart(chooseStart, selectStart, sound);
				} while (selectStart == 0);

				if (selectStart != 3)
				{
					char chessBoard[maxRow][maxColum];

					while (selectStart == 1)
					{
						XoaManHinhNho();

						TextColor(7);
						gotoXY(FrameMenuWidth / 2 - 25, FrameMenuHeight / 2);
						printf("Nhap ten nguoi choi 1: ");
						fflush(stdin);
						TextColor(4);
						getline(cin ,player1.name);

						TextColor(7);
						gotoXY(FrameMenuWidth / 2 - 25, FrameMenuHeight / 2 + 2);
						printf("Nhap ten nguoi choi 2: ");
						fflush(stdin);
						TextColor(6);
						getline(cin, player2.name);

						do
						{
							initChessBoard(chessBoard);
							_1vs1(chessBoard, restart, sound);
						} while (restart == true);

						if (restart == false)
						{
							selectMenu = 0;
							selectStart = 0;
							chooseStart = 1;
							chooseMenu = 1;
						}
					}

					while (selectStart == 2)
					{
						XoaManHinhNho();

						do
						{
							Level(chooseLV);
							ControlLV(chooseLV, selectLV, sound);
						} while (selectLV == 0);

						if (selectLV != 3)
						{
							XoaManHinhNho();

							do
							{
								Turn(chooseTurn);
								ControlTurn(chooseTurn, selectTurn, sound);
							} while (selectTurn == 0);

							if (selectTurn != 3)
							{
								XoaManHinhNho();
								TextColor(7);
								gotoXY(FrameMenuWidth / 2 - 25, FrameMenuHeight / 2);
								printf("Nhap ten nguoi choi : ");
								fflush(stdin);
								TextColor(6);
								getline(cin, player1.name);

								do
								{
									initChessBoard(chessBoard);
									_1vsCom(player1, chessBoard, selectLV, selectTurn, restart, sound);
								} while (restart == true);

								if (restart == false)
								{
									selectTurn = 0;
									selectMenu = 0;
									selectStart = 0;
									selectLV = 0;
									chooseStart = 1;
									chooseMenu = 1;
									chooseTurn = 1;
									chooseLV = 1;
								}
							}
							else
							{
								XoaManHinhNho();
								selectTurn = 0;
								chooseTurn = 1;
								selectLV = 0;
								chooseLV = 1;
							}

						}
						else
						{
							XoaManHinhNho();
							selectLV = 0;
							chooseLV = 1;
							selectStart = 0;
							chooseStart = 1;
						}
					}
				}

				else
				{
					XoaManHinhNho();
					selectStart = 0;
					chooseStart = 1;
					selectMenu = 0;
					chooseMenu = 1;
				}
			}

		} while (selectMenu != 1 && selectMenu != 5);
		system("cls");
	} while (selectMenu != 5);
}