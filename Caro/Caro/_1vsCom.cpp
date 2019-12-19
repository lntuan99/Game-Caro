#include "_1vsCom.h"
#include <stack>

void initPlayerVsCom(Player &player, Location &old)
{
	player.local.x = External_Frame_Width / 2 - 3;
	player.local.y = (External_Frame_Height - 5) / 2 + 5;
	player.color = player2_color;
	player.point = 0;


	old.x = player.local.x;
	old.y = player.local.y;
}

void Control(Player &player, Location &old, bool &control, char chessBoard[maxRow][maxColum], int &luot_danh, bool &PlayerWin, bool &EndGame, int &point, stack<Node> &MOVE, bool &quit, bool &sound)
{
	if (_kbhit())
	{
		int key = _getch();
		switch (key)
		{
		case 'A':case 'a': case KEY_LEFT:
		{
			if (player.local.x > 2)
			{
				if (sound)
				{
					PlaySound("move.wav", NULL, SND_ASYNC);
				}

				old.x = player.local.x;
				old.y = player.local.y;

				player.local.x -= 4;
				control = true;
			}

			break;
		}
		case 'D':case 'd': case KEY_RIGHT:
		{
			if (player.local.x < External_Frame_Width - 5)
			{
				if (sound)
				{
					PlaySound("move.wav", NULL, SND_ASYNC);
				}

				old.x = player.local.x;
				old.y = player.local.y;

				player.local.x += 4;
				control = true;
			}

			break;
		}
		case 'W':case 'w': case KEY_UP:
		{
			if (player.local.y > 6)
			{
				if (sound)
				{
					PlaySound("move.wav", NULL, SND_ASYNC);
				}

				old.x = player.local.x;
				old.y = player.local.y;

				player.local.y -= 2;
				control = true;
			}
			break;
		}
		case 'S':case 's': case KEY_DOWN:
		{
			if (player.local.y < External_Frame_Height - 2)
			{
				if (sound)
				{
					PlaySound("move.wav", NULL, SND_ASYNC);
				}

				old.x = player.local.x;
				old.y = player.local.y;

				player.local.y += 2;
				control = true;
			}
			break;
		}
		case SPACE: case ENTER:
		{
			if (luot_danh == 2)
			{
				if (getCharacterInChessBoard(chessBoard, player.local.y, player.local.x) == ' ')
				{
					if (sound)
					{
						PlaySound("Danh_co.wav", NULL, SND_ASYNC);
					}

					setCharacterInChessBoard(chessBoard, player.local.y, player.local.x, 'O');

					old.x = player.local.x;
					old.y = player.local.y;

					Node n;
					n.row = (player.local.y - 6) / 2;
					n.colum = (player.local.x - 2) / 4;

					MOVE.push(n);

					player.point++;

					bool Check = WinGame(chessBoard, player, 'O');
					if (Check)
					{
						PlayerWin = true;
						EndGame = true;
					}

					luot_danh = 1;
				}
			}
			control = true;
			break;
		}
		case 'U': case 'u':
		{
			if (!MOVE.empty())
			{
				if (sound)
				{
					PlaySound("Undo.wav", NULL, SND_ASYNC);
				}

				chessBoard[MOVE.top().row][MOVE.top().colum] = ' ';
				TextColor(0);
				gotoXY(MOVE.top().colum * 4 + 2, MOVE.top().row * 2 + 6);
				printf("   ");
				MOVE.pop();
				player.point--;

			}

			if (!MOVE.empty())
			{
				if (sound)
				{
					PlaySound("Undo.wav", NULL, SND_ASYNC);
				}

				chessBoard[MOVE.top().row][MOVE.top().colum] = ' ';
				TextColor(0);
				gotoXY(MOVE.top().colum * 4 + 2, MOVE.top().row * 2 + 6);
				printf("   ");
				MOVE.pop();
				--point;
			}

			luot_danh = 2;
			control = true;
			break;
		}
		case ESC:
		{
			mainEsc(chessBoard, quit, sound, true);
			control = true;
		}
		}
	}
}

void Update(Player player, Location old, char chessBoard[maxRow][maxColum], int point, int luot_danh, bool PlayerWin, bool EndGame, bool &restart, bool sound)
{
	gotoXY(8, 4);
	if (luot_danh == 1)
	{
		TextColor(4);
		printf("X");
	}
	else
	{
		TextColor(6);
		printf("O");
	}

	TextColor(4);
	gotoXY(External_Frame_Width - 12, 4);
	printf("%2d", point);

	TextColor(6);
	gotoXY(External_Frame_Width - 6, 4);
	printf("%2d", player.point);

	char ch = getCharacterInChessBoard(chessBoard, old.y, old.x);

	gotoXY(old.x, old.y);
	if (ch == 'X')
	{
		TextColor(7);
		printf(" X ");
	}
	else if (ch == 'O')
	{
		TextColor(6);
		printf(" O ");
	}
	else
	{
		TextColor(0);
		printf("   ");
	}

	TextColor(14);
	gotoXY(External_Frame_Width / 2 - 6, 3); printf("NHAN U DE UNDO");

	TextColor(11);
	gotoXY(External_Frame_Width / 2 - 9, 4); printf("NHAN ESC DE LUA CHON");

	TextColor(player.color);
	gotoXY(player.local.x, player.local.y);
	printf(" %c ", getCharacterInChessBoard(chessBoard, player.local.y, player.local.x));

	if (EndGame)
	{
		if (PlayerWin)
		{
			if (sound)
				PlaySound("thang_game.wav", NULL, SND_ASYNC);
			TextColor(6);
			gotoXY((External_Frame_Width - player.name.size() - 4) / 2, 2); std::cout << player.name << " WIN";
		}

		else if (player.point >= maxRow * maxColum / 2)
		{
			TextColor(7);
			gotoXY(External_Frame_Width / 2 - 2, 2); printf("HOA CO");
		}
		else
		{
			if (sound)
				PlaySound("thua_game.wav", NULL, SND_ASYNC);
			TextColor(4);
			gotoXY(External_Frame_Width / 2 - 5, 2); printf("COMPUTER WIN");
		}

		TextColor(14);
		gotoXY(External_Frame_Width / 2 - 10, 3); printf("NHAN ENTER DE CHOI LAI");

		TextColor(11);
		gotoXY(External_Frame_Width / 2 - 13, 4); printf("NHAN ESC DE QUAY TRO LAI MENU");

		while (1)
		{
			int key = _getch();
			if (key == ESC)
			{
				restart = false;
				system("cls");
				FrameMenu();
				break;
			}

			else if (key == ENTER)
			{
				restart = true;
				break;
			}
		}
	}
}

void _1vsCom(Player &player, char chessBoard[maxRow][maxColum], int selectLV, int selectTurn, bool &restart, bool &sound)
{
	Location old;

	XoaManHinhNho();

	initPlayerVsCom(player, old);

	system("cls");

	Display();

	bool control = false, PlayerWin = false, EndGame = false, quit = false;
	int luot_danh = 2;
	int point = 0;
	int maxDepth;

	stack<Node> MOVE;

	if (selectTurn == 2)
	{
		point = 1;
		TextColor(7);
		gotoXY(External_Frame_Width / 2 + 1, (External_Frame_Height - 5) / 2 + 5);
		setCharacterInChessBoard(chessBoard, 24, 66, 'X');
		printf(" X ");
	}

	if (selectLV == 1)
		maxDepth = 1;
	else if (selectLV == 2)
		maxDepth = 100;

	while (1)
	{
		Nocursortype();

		Update(player, old, chessBoard, point, luot_danh, PlayerWin, EndGame, restart, sound);
		if (EndGame)
			break;

		do {
			Control(player, old, control, chessBoard, luot_danh, PlayerWin, EndGame, point, MOVE, quit, sound);
		} while (control == false);

		if (luot_danh == 1 && EndGame == false)
		{
			Computer(chessBoard, point, EndGame, maxDepth, MOVE);
			++point;
			luot_danh = 2;
		}
		control = false;

		if (quit)
		{
			restart = false;
			system("cls");
			FrameMenu();
			break;
		}
	}
}