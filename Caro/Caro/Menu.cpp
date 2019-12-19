#include "Menu.h"

void FrameMenu()
{
	Nocursortype();
	TextColor(2);
	gotoXY(25, 3); printf("             CCCCCCCCCCC      AAAAA      RRRRRRRRRRRR    OOOOOOOOOOO          \n");
	gotoXY(25, 4); printf("           CCCCCCCCCCCCC   AAAAAAAAAAA   RRRR    RRRRR  OOOOOO OOOOOO         \n"); TextColor(3);
	gotoXY(25, 5); printf("          CCCCCCC         AAAAA   AAAAA  RRRR  RRRRRR  OOOOOO   OOOOOO        \n");
	gotoXY(25, 6); printf("          CCCCCCC         AAAAA   AAAAA  RRRRRRRRR     OOOOO     OOOOO        \n");
	gotoXY(25, 7); printf("          CCCCCCC         AAAAAAAAAAAAA  RRRR  RRRRR   OOOOOO   OOOOOO        \n"); TextColor(4);
	gotoXY(25, 8); printf("           CCCCCCCCCCCCC  AAAAA   AAAAA  RRRR   RRRRR   OOOOOO OOOOOO         \n");
	gotoXY(25, 9); printf("             CCCCCCCCCCC  AAAAA   AAAAA  RRRR     RRRR   OOOOOOOOOOO          \n");

	TextColor(13);

	gotoXY(0, 0); putchar(201);

	gotoXY(FrameMenuWidth, 0); putchar(187);

	gotoXY(FrameMenuWidth, FrameMenuHeight); putchar(188);

	gotoXY(0, FrameMenuHeight); putchar(200);

	int i, j;

	for (i = 1; i < FrameMenuHeight; ++i)
	{
		gotoXY(0, i); putchar(186);

		gotoXY(FrameMenuWidth, i); putchar(186);
	}

	for (j = 1; j < FrameMenuWidth; ++j)
	{
		gotoXY(j, 0); putchar(205);

		gotoXY(j, FrameMenuHeight); putchar(205);
	}

	TextColor(11);
	gotoXY(1, 1); putchar(201);

	gotoXY(FrameMenuWidth + 1, 1); putchar(187);

	gotoXY(FrameMenuWidth + 1, FrameMenuHeight + 1); putchar(188);

	gotoXY(1, FrameMenuHeight + 1); putchar(200);

	for (i = 2; i <= FrameMenuHeight; ++i)
	{
		gotoXY(1, i); putchar(186);

		gotoXY(FrameMenuWidth + 1, i); putchar(186);
	}

	for (j = 2; j <= FrameMenuWidth; ++j)
	{
		gotoXY(j, 1); putchar(205);

		gotoXY(j, FrameMenuHeight + 1); putchar(205);
	}

	TextColor(2);
	for (i = FrameMenuHeight / 2 - 9; i <= FrameMenuHeight / 2 + 15; ++i)
	{
		gotoXY(FrameMenuWidth / 2 - 45, i);
		putchar(221);

		gotoXY(FrameMenuWidth / 2 + 45, i);
		putchar(222);
	}

	for (j = FrameMenuWidth / 2 - 45; j <= FrameMenuWidth / 2 + 45; ++j)
	{
		gotoXY(j, FrameMenuHeight / 2 - 9);
		putchar(220);

		gotoXY(j, FrameMenuHeight / 2 + 15);
		putchar(223);
	}
}

void ContentMenu(int chooseStart, bool sound)
{
	Nocursortype();

	if (sound)
	{
		if (chooseStart == 1)
		{
			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 4);
			TextColor(3);
			printf("%c START   ", 175);

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 2);
			TextColor(7);
			printf("HELP   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2);
			TextColor(12);
			printf("INFORMATION   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 2);
			TextColor(11);
			printf("Sound: OFF   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 4);
			TextColor(14);
			printf("EXIT   ");
		}
		if (chooseStart == 2)
		{
			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 4);
			TextColor(3);
			printf("START   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 2);
			TextColor(7);
			printf("%c HELP   ", 175);

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2);
			TextColor(12);
			printf("INFORMATION   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 2);
			TextColor(11);
			printf("Sound: OFF   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 4);
			TextColor(14);
			printf("EXIT   ");
		}
		else if (chooseStart == 3)
		{
			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 4);
			TextColor(3);
			printf("START   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 2);
			TextColor(7);
			printf("HELP   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2);
			TextColor(12);
			printf("%c INFORMATION   ", 175);

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 2);
			TextColor(11);
			printf("Sound: OFF   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 4);
			TextColor(14);
			printf("EXIT   ");
		}
		else if (chooseStart == 4)
		{
			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 4);
			TextColor(3);
			printf("START   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 2);
			TextColor(7);
			printf("HELP   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2);
			TextColor(12);
			printf("INFORMATION   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 2);
			TextColor(11);
			printf("%c Sound: OFF   ", 175);

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 4);
			TextColor(14);
			printf("EXIT   ");
		}
		else if (chooseStart == 5)
		{
			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 4);
			TextColor(3);
			printf("START   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 2);
			TextColor(7);
			printf("HELP   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2);
			TextColor(12);
			printf("INFORMATION   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 2);
			TextColor(11);
			printf("Sound: OFF   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 4);
			TextColor(14);
			printf("%c EXIT", 175);
		}
	}

	else
	{
		if (chooseStart == 1)
		{
			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 4);
			TextColor(3);
			printf("%c START   ", 175);

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 2);
			TextColor(7);
			printf("HELP   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2);
			TextColor(12);
			printf("INFORMATION   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 2);
			TextColor(11);
			printf("Sound: ON   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 4);
			TextColor(14);
			printf("EXIT   ");
		}
		if (chooseStart == 2)
		{
			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 4);
			TextColor(3);
			printf("START   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 2);
			TextColor(7);
			printf("%c HELP   ", 175);

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2);
			TextColor(12);
			printf("INFORMATION   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 2);
			TextColor(11);
			printf("Sound: ON   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 4);
			TextColor(14);
			printf("EXIT   ");
		}
		else if (chooseStart == 3)
		{
			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 4);
			TextColor(3);
			printf("START   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 2);
			TextColor(7);
			printf("HELP   ");
	
			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2);
			TextColor(12);
			printf("%c INFORMATION   ", 175);

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 2);
			TextColor(11);
			printf("Sound: ON   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 4);
			TextColor(14);
			printf("EXIT   ");
		}
		else if (chooseStart == 4)
		{
			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 4);
			TextColor(3);
			printf("START   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 2);
			TextColor(7);
			printf("HELP   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2);
			TextColor(12);
			printf("INFORMATION   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 2);
			TextColor(11);
			printf("%c Sound: ON   ", 175);

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 4);
			TextColor(14);
			printf("EXIT   ");
		}
		else if (chooseStart == 5)
		{
			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 4);
			TextColor(3);
			printf("START   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 - 2);
			TextColor(7);
			printf("HELP   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2);
			TextColor(12);
			printf("INFORMATION   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 2);
			TextColor(11);
			printf("Sound: ON   ");

			gotoXY(FrameMenuWidth / 2 - 2, FrameMenuHeight / 2 + 4);
			TextColor(14);
			printf("%c EXIT", 175);
		}
	}

	

	TextColor(5);
	gotoXY(FrameMenuWidth / 2 - 9, FrameMenuHeight / 2 + 10);
	printf("FINISHED: 31/03/2019");
}

void ControlMenu(int &chooseStart, int &selectStart, bool sound)
{
	if (_kbhit())
	{
		int key = _getch();
		switch (key)
		{
		case 'W': case 'w': case KEY_UP:
		{
			if (sound)
			{
				PlaySound("move.wav", NULL, SND_ASYNC);
			}

			if (chooseStart == 1) chooseStart = 5;
			else --chooseStart;
			break;
		}
		case 'S': case 's': case KEY_DOWN:
		{
			if (sound)
			{
				PlaySound("move.wav", NULL, SND_ASYNC);
			}

			if (chooseStart == 5) chooseStart = 1;
			else ++chooseStart;
			break;
		}
		case ENTER:
		{
			if (sound)
			{
				PlaySound("Danh_co.wav", NULL, SND_ASYNC);
			}
			selectStart = chooseStart;
		}
		}
	}
}

void Help()
{
	Nocursortype();
	XoaManHinhNho();

	TextColor(7);
	gotoXY(FrameMenuWidth / 2 - 44, FrameMenuHeight / 2 - 7);
	printf("Co hai che do choi: ");

	gotoXY(FrameMenuWidth / 2 - 44, FrameMenuHeight / 2 - 6);
	printf(" - 1 vs 1");

	gotoXY(FrameMenuWidth / 2 - 44, FrameMenuHeight / 2 - 5);
	printf(" - 1 vs Computer");

	TextColor(7);
	gotoXY(FrameMenuWidth / 2 - 6, FrameMenuHeight / 2 - 3);
	printf("Dieu khien: ");

	TextColor(4);

	gotoXY(FrameMenuWidth / 2 - 34, FrameMenuHeight / 2 - 1);
	printf("Nguoi choi X: ");

	gotoXY(FrameMenuWidth / 2 - 30, FrameMenuHeight / 2 + 1);
	printf("Qua Trai    : A");

	gotoXY(FrameMenuWidth / 2 - 30, FrameMenuHeight / 2 + 2);
	printf("Qua Phai    : D");

	gotoXY(FrameMenuWidth / 2 - 30, FrameMenuHeight / 2 + 3);
	printf("Len Tren    : W");

	gotoXY(FrameMenuWidth / 2 - 30, FrameMenuHeight / 2 + 4);
	printf("Xuong Duoi  : S");

	gotoXY(FrameMenuWidth / 2 - 30, FrameMenuHeight / 2 + 5);
	printf("Danh Co     : SPACE");

	//

	TextColor(6);
	gotoXY(FrameMenuWidth / 2 + 17, FrameMenuHeight / 2 - 1);
	printf("Nguoi choi O: ");

	gotoXY(FrameMenuWidth / 2 + 11, FrameMenuHeight / 2 + 1);
	printf("Qua Trai    : VK_LEFT");

	gotoXY(FrameMenuWidth / 2 + 11, FrameMenuHeight / 2 + 2);
	printf("Qua Phai    : VK_RIGHT");

	gotoXY(FrameMenuWidth / 2 + 11, FrameMenuHeight / 2 + 3);
	printf("Len Tren    : VK_UP");

	gotoXY(FrameMenuWidth / 2 + 11, FrameMenuHeight / 2 + 4);
	printf("Xuong Duoi  : VK_DOWN");

	gotoXY(FrameMenuWidth / 2 + 11, FrameMenuHeight / 2 + 5);
	printf("Danh Co     : ENTER");

	TextColor(7);
	gotoXY(FrameMenuWidth / 2 - 28, FrameMenuHeight / 2 + 9);
	printf("Tuy theo luot danh ma");
	TextColor(4);
	printf(" \"\X\"\ ");
	TextColor(7);
	printf("hay");
	TextColor(6);
	printf(" \"\O\"\ ");
	TextColor(7);
	printf("Se duoc dien vao ban co");

	TextColor(10);
	gotoXY(FrameMenuWidth / 2 - 13, FrameMenuHeight / 2 + 12);
	printf("Nhan ENTER de tro ve MENU");
}

void Infor()
{
	Nocursortype();
	XoaManHinhNho();

	TextColor(241);
	gotoXY(FrameMenuWidth / 2 - 29, FrameMenuHeight / 2 - 5);
	printf("TRUONG DAI HOC KHOA HOC TU NHIEN - KHOA CONG NGHE THONG TIN");

	TextColor(7);
	gotoXY(FrameMenuWidth / 2 - 10, FrameMenuHeight / 2 - 3);
	printf("LOP 18CTT5 - NHOM 5");

	TextColor(11);

	gotoXY(FrameMenuWidth / 2 - 30, FrameMenuHeight / 2 - 1);
	printf("HO VA TEN: ");

	TextColor(2);
	gotoXY(FrameMenuWidth / 2 - 28, FrameMenuHeight / 2 + 1);
	printf("LE NHAT TUAN");

	TextColor(3);
	gotoXY(FrameMenuWidth / 2 - 28, FrameMenuHeight / 2 + 2);
	printf("NGUYEN TAN VINH");

	TextColor(4);
	gotoXY(FrameMenuWidth / 2 - 28, FrameMenuHeight / 2 + 3);
	printf("VO DUC THANG");

	TextColor(5);
	gotoXY(FrameMenuWidth / 2 - 28, FrameMenuHeight / 2 + 4);
	printf("BUI VAN THANH");

	TextColor(6);
	gotoXY(FrameMenuWidth / 2 - 28, FrameMenuHeight / 2 + 5);
	printf("NGUYEN PHUC HUNG THINH");

	//

	TextColor(14);
	gotoXY(FrameMenuWidth / 2 + 17, FrameMenuHeight / 2 - 1);
	printf("MA SO SINH VIEN");

	gotoXY(FrameMenuWidth / 2 + 20, FrameMenuHeight / 2 + 1);
	printf("18120632");

	gotoXY(FrameMenuWidth / 2 + 20, FrameMenuHeight / 2 + 2);
	printf("18120650");

	gotoXY(FrameMenuWidth / 2 + 20, FrameMenuHeight / 2 + 3);
	printf("18120557");

	gotoXY(FrameMenuWidth / 2 + 20, FrameMenuHeight / 2 + 4);
	printf("18120559");

	gotoXY(FrameMenuWidth / 2 + 20, FrameMenuHeight / 2 + 5);
	printf("18120577");

	TextColor(10);
	gotoXY(FrameMenuWidth / 2 - 13, FrameMenuHeight / 2 + 12);
	printf("Nhan ENTER de tro ve MENU");
}

void ControlStart(int &chooseStart, int &selectStart, bool sound)
{
	if (_kbhit())
	{
		int key = _getch();
		switch (key)
		{
		case 'W': case 'w': case KEY_UP:
		{
			if (sound)
			{
				PlaySound("move.wav", NULL, SND_ASYNC);
			}

			if (chooseStart == 1) chooseStart = 3;
			else --chooseStart;
			break;
		}
		case 'S': case 's': case KEY_DOWN:
		{
			if (sound)
			{
				PlaySound("move.wav", NULL, SND_ASYNC);
			}

			if (chooseStart == 3) chooseStart = 1;
			else ++chooseStart;
			break;
		}
		case ENTER: case SPACE:
		{
			if (sound)
			{
				PlaySound("Danh_co.wav", NULL, SND_ASYNC);
			}

			selectStart = chooseStart;
		}
		}
	}
}

void Start(int chooseStart)
{
	Nocursortype();
	if (chooseStart == 1)
	{
		TextColor(3);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2);
		printf("%c 1 vs 1", 175);

		TextColor(13);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 2);
		printf("1 vs Computer   ");

		TextColor(11);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 4);
		printf("BACK   ");
	}

	if (chooseStart == 2)
	{
		TextColor(3);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2);
		printf("1 vs 1   ");

		TextColor(13);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 2);
		printf("%c 1 vs Computer", 175);

		TextColor(11);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 4);
		printf("BACK   ");
	}

	if (chooseStart == 3)
	{
		TextColor(3);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2);
		printf("1 vs 1   ");

		TextColor(13);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 2);
		printf("1 vs Computer   ");

		TextColor(11);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 4);
		printf("%c BACK   ", 175);
	}
}

void ControlLV(int &chooseLV, int &selectLV, bool sound)
{
	if (_kbhit())
	{
		int key = _getch();
		switch (key)
		{
		case 'W': case 'w': case KEY_UP:
		{
			if (sound)
			{
				PlaySound("move.wav", NULL, SND_ASYNC);
			}

			if (chooseLV == 1) chooseLV = 3;
			else --chooseLV;
			break;
		}
		case 'S': case 's': case KEY_DOWN:
		{
			if (sound)
			{
				PlaySound("move.wav", NULL, SND_ASYNC);
			}

			if (chooseLV == 3) chooseLV = 1;
			else ++chooseLV;
			break;
		}
		case ENTER: case SPACE:
		{
			if (sound)
			{
				PlaySound("Danh_co.wav", NULL, SND_ASYNC);
			}

			selectLV = chooseLV;
		}
		}
	}
}

void Level(int chooseLV)
{
	Nocursortype();
	if (chooseLV == 1)
	{
		TextColor(3);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2);
		printf("%c Easy   ", 175);

		TextColor(13);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 2);
		printf("Hard   ");

		TextColor(11);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 4);
		printf("Back   ");
	}

	if (chooseLV == 2)
	{
		TextColor(3);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2);
		printf("Easy   ");

		TextColor(13);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 2);
		printf("%c Hard   ", 175);

		TextColor(11);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 4);
		printf("Back   ");
	}
	
	if (chooseLV == 3)
	{
		TextColor(3);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2);
		printf("Easy   ");

		TextColor(13);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 2);
		printf("Hard   ");

		TextColor(11);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 4);
		printf("%c Back   ", 175);
	}
}

void ControlTurn(int &chooseTurn, int &selectTurn, bool sound)
{
	if (_kbhit())
	{
		int key = _getch();
		switch (key)
		{
		case 'W': case 'w': case KEY_UP:
		{
			if (sound)
			{
				PlaySound("move.wav", NULL, SND_ASYNC);
			}

			if (chooseTurn == 1) chooseTurn = 3;
			else --chooseTurn;
			break;
		}
		case 'S': case 's': case KEY_DOWN:
		{
			if (sound)
			{
				PlaySound("move.wav", NULL, SND_ASYNC);
			}

			if (chooseTurn == 3) chooseTurn = 1;
			else ++chooseTurn;
			break;
		}
		case ENTER: case SPACE:
		{
			if (sound)
			{
				PlaySound("Danh_co.wav", NULL, SND_ASYNC);
			}

			selectTurn = chooseTurn;
		}
		}
	}
}

void Turn(int chooseTurn)
{
	Nocursortype();
	if (chooseTurn == 1)
	{
		TextColor(3);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2);
		printf("%c Ban Danh Truoc   ", 175);

		TextColor(13);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 2);
		printf("May Danh Truoc   ");

		TextColor(11);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 4);
		printf("BACK   ");
	}

	if (chooseTurn == 2)
	{
		TextColor(3);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2);
		printf("Ban Danh Truoc  ");

		TextColor(13);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 2);
		printf("%c May Danh Truoc   ", 175);

		TextColor(11);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 4);
		printf("BACK   ");
	}

	if (chooseTurn == 3)
	{
		TextColor(3);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2);
		printf("Ban Danh Truoc  ");

		TextColor(13);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 2);
		printf("May Danh Truoc   ");

		TextColor(11);
		gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 4);
		printf("%c BACK   ", 175);
	}
}

void ControlEsc(int &chooseEsc, int &selectEsc, bool sound)
{
	if (_kbhit())
	{
		int key = _getch();
		switch (key)
		{
		case 'W': case 'w': case KEY_UP:
		{
			if (sound)
			{
				PlaySound("move.wav", NULL, SND_ASYNC);
			}

			if (chooseEsc == 1) chooseEsc = 3;
			else --chooseEsc;
			break;
		}
		case 'S': case 's': case KEY_DOWN:
		{
			if (sound)
			{
				PlaySound("move.wav", NULL, SND_ASYNC);
			}

			if (chooseEsc == 3) chooseEsc = 1;
			else ++chooseEsc;
			break;
		}
		case ENTER: case SPACE:
		{
			if (sound)
			{
				PlaySound("Danh_co.wav", NULL, SND_ASYNC);
			}

			selectEsc = chooseEsc;
		}
		}
	}
}

void Esc(int chooseEsc, bool sound)
{
	Nocursortype();
	if (sound)
	{
		if (chooseEsc == 1)
		{
			TextColor(3);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2);
			printf("%c RESUME   ", 175);

			TextColor(11);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 2);
			printf("SOUND: OFF   ");

			TextColor(13);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 4);
			printf("QUIT   ");

		}

		if (chooseEsc == 2)
		{
			TextColor(3);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2);
			printf("RESUME   ");

			TextColor(11);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 2);
			printf("%c SOUND: OFF   ", 175);

			TextColor(13);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 4);
			printf("QUIT   ");
		}

		if (chooseEsc == 3)
		{
			TextColor(3);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2);
			printf("RESUME   ");

			TextColor(11);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 2);
			printf("SOUND: OFF   ");

			TextColor(13);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 4);
			printf("%c QUIT   ", 175);
		}
	}
	else
	{
		if (chooseEsc == 1)
		{
			TextColor(3);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2);
			printf("%c RESUME   ", 175);

			TextColor(11);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 2);
			printf("SOUND: ON   ");

			TextColor(13);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 4);
			printf("QUIT   ");

		}

		if (chooseEsc == 2)
		{
			TextColor(3);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2);
			printf("RESUME   ");

			TextColor(11);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 2);
			printf("%c SOUND: ON   ", 175);

			TextColor(13);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 4);
			printf("QUIT   ");
		}

		if (chooseEsc == 3)
		{
			TextColor(3);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2);
			printf("RESUME   ");

			TextColor(11);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 2);
			printf("SOUND: ON   ");

			TextColor(13);
			gotoXY(FrameMenuWidth / 2 - 5, FrameMenuHeight / 2 + 4);
			printf("%c QUIT   ", 175);
		}
	}
	
}

void mainEsc(char chessBoard[maxRow][maxColum], bool &quit, bool &sound, bool Com)
{
	TextColor(2);

	int i, j;
	for (i = FrameMenuHeight / 2 - 9; i <= FrameMenuHeight / 2 + 15; ++i)
	{
		gotoXY(FrameMenuWidth / 2 - 45, i);
		putchar(221);

		gotoXY(FrameMenuWidth / 2 + 45, i);
		putchar(222);
	}

	for (j = FrameMenuWidth / 2 - 45; j <= FrameMenuWidth / 2 + 45; ++j)
	{
		gotoXY(j, FrameMenuHeight / 2 - 9);
		putchar(220);

		gotoXY(j, FrameMenuHeight / 2 + 15);
		putchar(223);
	}

	XoaManHinhNho();

	int chooseEsc = 1, selectEsc = 0;
	do
	{
		Esc(chooseEsc, sound);
		ControlEsc(chooseEsc, selectEsc, sound);
		if (selectEsc == 2)
		{
			selectEsc = 0;
			sound = !sound;
		}
	} while (selectEsc == 0);

	if (selectEsc == 1)
		if (Com)
		{
			DrawChessBoard();
			for (i = 0; i < maxRow; ++i)
				for (j = 0; j < maxColum; ++j)
				{
					if (chessBoard[i][j] == 'O')
						TextColor(6);
					else if (chessBoard[i][j] == 'X')
						TextColor(7);
					else TextColor(0);

					gotoXY((j * 4) + 2, (i * 2) + 6);
					printf(" %c ", chessBoard[i][j]);
				}
		}

		else
		{
			DrawChessBoard();
			for (i = 0; i < maxRow; ++i)
				for (j = 0; j < maxColum; ++j)
				{
					if (chessBoard[i][j] == 'O')
						TextColor(6);
					else if (chessBoard[i][j] == 'X')
						TextColor(4);
					else TextColor(0);

					gotoXY((j * 4) + 2, (i * 2) + 6);
					printf(" %c ", chessBoard[i][j]);
				}
		}

	else if (selectEsc == 3)
		quit = true;
}

