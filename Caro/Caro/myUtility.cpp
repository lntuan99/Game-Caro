#include "myUtility.h"

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void Nocursortype()  //Xóa con trỏ
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void XoaManHinhNho()
{
	int i, j;
	for (i = FrameMenuHeight / 2 - 8; i < FrameMenuHeight / 2 + 15; ++i)
		for (j = FrameMenuWidth / 2 - 44; j < FrameMenuWidth / 2 + 45; ++j)
		{
			gotoXY(j, i);
			printf(" ");
		}
}

char getCharacterInChessBoard(char chessBoard[maxRow][maxColum], int y, int x)
{
	return chessBoard[(y - 6) / 2][(x - 2) / 4];
}

void setCharacterInChessBoard(char chessBoard[maxRow][maxColum], int y, int x, char ch)
{
	chessBoard[(y - 6) / 2][(x - 2) / 4] = ch;
}

void GetDesktopResolution(int &horizontal, int &vertical)
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	horizontal = desktop.right;
	vertical = desktop.bottom;
}
