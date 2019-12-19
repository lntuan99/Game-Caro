#include "_1vs1.h"

void initPlayer(Player &player1, Player &player2, Location &old1, Location &old2)
{
	player1.local.x = External_Frame_Width / 2 - 3;
	player1.local.y = (External_Frame_Height - 5) / 2 + 5;
	player1.color = player1_color;
	player1.point = 0;

	player2.local.x = External_Frame_Width / 2 + 1;
	player2.local.y = (External_Frame_Height - 5) / 2 + 5;
	player2.color = player2_color;
	player2.point = 0;

	old1.x = player1.local.x;
	old1.y = player1.local.y;

	old2.x = player2.local.x;
	old2.y = player2.local.y;
}

void Control(Player &player1, Player &player2, Location &old1, Location &old2, bool &control, char chessBoard[maxRow][maxColum], int &luot_danh, bool &Xwin, bool &Owin, bool &EndGame, stack<Node> &Move, bool &quit, bool &sound)
{
	if (_kbhit())
	{
		int key = _getch();
		switch (key)
		{
		case 'A':case 'a':
		{
			if (player1.local.x > 2)
			{
				if (sound)
				{
					PlaySound("move.wav", NULL, SND_ASYNC);
				}

				old1.x = player1.local.x;
				old1.y = player1.local.y;

				player1.local.x -= 4;
				control = true;
			}

			break;
		}
		case 'D':case 'd':
		{
			if (player1.local.x < External_Frame_Width - 5)
			{
				if (sound)
				{
					PlaySound("move.wav", NULL, SND_ASYNC);
				}

				old1.x = player1.local.x;
				old1.y = player1.local.y;

				player1.local.x += 4;
				control = true;
			}

			break;
		}
		case 'W':case 'w':
		{
			if (player1.local.y > 6)
			{
				if (sound)
				{
					PlaySound("move.wav", NULL, SND_ASYNC);
				}

				old1.x = player1.local.x;
				old1.y = player1.local.y;

				player1.local.y -= 2;
				control = true;
			}
			break;
		}
		case 'S':case 's':
		{
			if (player1.local.y < External_Frame_Height - 2)
			{
				if (sound)
				{
					PlaySound("move.wav", NULL, SND_ASYNC);
				}

				old1.x = player1.local.x;
				old1.y = player1.local.y;

				player1.local.y += 2;
				control = true;
			}
			break;
		}
		case KEY_LEFT:
		{
			if (player2.local.x > 2)
			{
				if (sound)
				{
					PlaySound("move.wav", NULL, SND_ASYNC);
				}

				old2.x = player2.local.x;
				old2.y = player2.local.y;

				player2.local.x -= 4;
				control = true;
			}
			break;
		}
		case KEY_RIGHT:
		{
			if (player2.local.x < External_Frame_Width - 5)
			{
				if (sound)
				{
					PlaySound("move.wav", NULL, SND_ASYNC);
				}

				old2.x = player2.local.x;
				old2.y = player2.local.y;

				player2.local.x += 4;
				control = true;
			}
			break;
		}
		case KEY_UP:
		{
			if (player2.local.y > 6)
			{
				if (sound)
				{
					PlaySound("move.wav", NULL, SND_ASYNC);
				}

				old2.x = player2.local.x;
				old2.y = player2.local.y;

				player2.local.y -= 2;
				control = true;
			}
			break;
		}
		case KEY_DOWN:
		{
			if (player2.local.y < External_Frame_Height - 2)
			{
				if (sound)
				{
					PlaySound("move.wav", NULL, SND_ASYNC);
				}

				old2.x = player2.local.x;
				old2.y = player2.local.y;

				player2.local.y += 2;
				control = true;
			}
			break;
		}
		case SPACE:
		{
			if (luot_danh == 1)
			{
				if (getCharacterInChessBoard(chessBoard, player1.local.y, player1.local.x) == ' ')
				{
					if (sound)
					{
						PlaySound("Danh_co.wav", NULL, SND_ASYNC);
					}

					setCharacterInChessBoard(chessBoard, player1.local.y, player1.local.x, 'X');

					Node n;
					n.row = player1.local.y;
					n.colum = player1.local.x;
					Move.push(n);

					old1.x = player1.local.x;
					old1.y = player1.local.y;

					player1.point++;

					bool Check = WinGame(chessBoard, player1, 'X');
					if (Check)
					{
						Xwin = true;
						EndGame = true;
					}

					luot_danh = 2;
				}
			}
			control = true;

			break;
		}
		case ENTER:
		{
			if (luot_danh == 2)
			{
				if (getCharacterInChessBoard(chessBoard, player2.local.y, player2.local.x) == ' ')
				{
					if (sound)
					{
						PlaySound("Danh_co.wav", NULL, SND_ASYNC);
					}

					setCharacterInChessBoard(chessBoard, player2.local.y, player2.local.x, 'O');

					Node n;
					n.row = player2.local.y;
					n.colum = player2.local.x;
					Move.push(n);

					old2.x = player2.local.x;
					old2.y = player2.local.y;

					player2.point++;

					bool Check = WinGame(chessBoard, player2, 'O');
					if (Check)
					{
						Owin = true;
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
			if (!Move.empty())
			{
				if (sound)
				{
					PlaySound("Undo.wav", NULL, SND_ASYNC);
				}

				Node n = Move.top();
				gotoXY(n.colum, n.row);
				TextColor(0);
				printf("   ");

				setCharacterInChessBoard(chessBoard, n.row, n.colum, ' ');

				if (luot_danh == 1)
				{
					player2.point--;
					luot_danh = 2;
				}

				else
				{
					player1.point--;
					luot_danh = 1;
				}

				Move.pop();
			}
			control = true;
		}
		case ESC:
		{
			mainEsc(chessBoard, quit, sound, false);
			control = true;
		}
		}
	}
}

void Update(Player player1, Player player2, Location old1, Location old2, char chessBoard[maxRow][maxColum], int luot_danh, bool Xwin, bool Owin, bool EndGame, bool &restart)
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
	printf("%2d", player1.point);

	TextColor(6);
	gotoXY(External_Frame_Width - 6, 4);
	printf("%2d", player2.point);


	char ch1 = getCharacterInChessBoard(chessBoard, old1.y, old1.x);
	char ch2 = getCharacterInChessBoard(chessBoard, old2.y, old2.x);

	gotoXY(old1.x, old1.y);
	if (ch1 == 'X')
	{
		TextColor(4);
		printf(" X ");
	}
	else if (ch1 == 'O')
	{
		TextColor(6);
		printf(" O ");
	}
	else
	{
		TextColor(0);
		printf("   ");
	}

	gotoXY(old2.x, old2.y);
	if (ch2 == 'X')
	{
		TextColor(4);
		printf(" X ");
	}
	else if (ch2 == 'O')
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

	TextColor(player1.color);
	gotoXY(player1.local.x, player1.local.y);
	printf(" %c ", getCharacterInChessBoard(chessBoard, player1.local.y, player1.local.x));

	TextColor(player2.color);
	gotoXY(player2.local.x, player2.local.y);
	printf(" %c ", getCharacterInChessBoard(chessBoard, player2.local.y, player2.local.x));

	if (EndGame)
	{
		if (Xwin)
		{
			TextColor(4);
			gotoXY((External_Frame_Width - player1.name.size() - 4) / 2, 2); std::cout << player1.name << " WIN";
		}

		else if (Owin)
		{
			TextColor(6);
			gotoXY((External_Frame_Width - player2.name.size() - 4) / 2, 2); std::cout << player2.name << " WIN";
		}

		else
		{
			TextColor(7);
			gotoXY(External_Frame_Width / 2 - 5, 2); printf("COMPUTER WIN");
		}

		TextColor(14);
		gotoXY(External_Frame_Width / 2 - 10, 3); printf("NHAN ENTER DE CHOI LAI");

		TextColor(11);
		gotoXY(External_Frame_Width / 2 - 13, 4); printf("NHAN ESC DE QUAY TRO LAI MENU");;

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

void _1vs1(char chessBoard[maxRow][maxColum], bool &restart, bool &sound)
{
	Location old1, old2;
	Player player1, player2;

	XoaManHinhNho();

	initPlayer(player1, player2, old1, old2);

	system("cls");

	Display();

	bool control = false, Xwin = false, Owin = false, EndGame = false, quit = false;
	int luot_danh = 1;

	stack<Node> Move;

	while (1)
	{
		Nocursortype();
		Update(player1, player2, old1, old2, chessBoard, luot_danh, Xwin, Owin, EndGame, restart);
		if (EndGame)
			break;

		do {
			Control(player1, player2, old1, old2, control, chessBoard, luot_danh, Xwin, Owin, EndGame, Move, quit, sound);
		} while (control == false);
		
		if (quit)
		{
			restart = false;
			system("cls");
			FrameMenu();
			break;
		}

		control = false;
	}
}