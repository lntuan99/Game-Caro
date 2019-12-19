#include "Frame.h"

void External_Frame()
{
	TextColor(11);

	gotoXY(0, 0); putchar(201);

	gotoXY(External_Frame_Width, 0); putchar(187);

	gotoXY(External_Frame_Width, External_Frame_Height); putchar(188);

	gotoXY(0, External_Frame_Height); putchar(200);

	int i, j;

	for (i = 1; i < External_Frame_Height; ++i)
	{
		gotoXY(0, i); putchar(186);

		gotoXY(External_Frame_Width, i); putchar(186);
	}

	for (j = 1; j < External_Frame_Width; ++j)
	{
		gotoXY(j, 0); putchar(205);

		gotoXY(j, External_Frame_Height); putchar(205);
	}

	TextColor(225); gotoXY(External_Frame_Width / 2 - 2, 0); printf("NHOM 5");
}

void Inner_Frame()
{
	TextColor(13);
	// 4 Góc ở trong

	gotoXY(1, 1); putchar(201);

	gotoXY(External_Frame_Width - 1, 1); putchar(187);

	gotoXY(External_Frame_Width - 1, External_Frame_Height - 1); putchar(188);

	gotoXY(1, External_Frame_Height - 1); putchar(200);

	// Khung trong
	int i, j;

	for (i = 2; i < External_Frame_Height - 1; ++i)
	{
		gotoXY(1, i); putchar(186);

		gotoXY(External_Frame_Width - 1, i); putchar(186);
	}

	for (j = 2; j < External_Frame_Width - 1; ++j)
	{
		gotoXY(j, 1); putchar(205);

		gotoXY(j, External_Frame_Height - 1); putchar(205);
	}

	TextColor(13);
	for (j = 2; j < External_Frame_Width - 1; ++j)
	{
		gotoXY(j, 5); putchar(205);

		gotoXY(External_Frame_Width - j, 5); putchar(205);
	}

	for (i = 2; i < 5; ++i)
	{
		gotoXY(15, i); putchar(186);

		gotoXY(External_Frame_Width - 15, i); putchar(186);
	}

	// Bo các đầu nôi màu tím
	gotoXY(15, 5);  putchar(202);

	gotoXY(External_Frame_Width - 15, 5); putchar(202);

	gotoXY(1, 5); putchar(204);

	gotoXY(External_Frame_Width - 1, 5); putchar(185);

	gotoXY(15, 1); putchar(203);

	gotoXY(External_Frame_Width - 15, 1); putchar(203);

	// bên trong khung lượt đánh và số nước đi
	TextColor(10);

	gotoXY(4, 2);
	printf("LUOT DANH");

	gotoXY(External_Frame_Width - 12, 2);
	printf("SO NUOC DI");

	TextColor(4);
	gotoXY(External_Frame_Width - 11, 3);
	putchar('X');

	TextColor(6);
	gotoXY(External_Frame_Width - 5, 3);
	putchar('O');

	TextColor(8);
	gotoXY(External_Frame_Width - 8, 3);
	putchar(186);

	gotoXY(External_Frame_Width - 8, 4);
	putchar(186);

}

void DrawChessBoard()
{
	int i, j;

	TextColor(8);
	for (i = 6; i < External_Frame_Height - 1; ++i)
		for (j = 2; j < External_Frame_Width - 1; ++j)
		{
			if (i % 2 == 1)
				if (j % 2 == 1 && j % 4 == 1)
				{
					gotoXY(j, i);
					putchar(197);
				}
				else
				{
					gotoXY(j, i);
					putchar(196);
				}
			else
				if (j % 2 == 1 && j % 4 == 1)
				{
					gotoXY(j, i);
					putchar(179);
				}
		}
}

void Display()
{
	External_Frame();
	Inner_Frame();
	DrawChessBoard();
}
