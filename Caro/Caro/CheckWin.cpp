#include "CheckWin.h"

int Up(char chessBoard[maxRow][maxColum], int y, int x, char ch, int &check)
{
	char tmp = ch == 'X' ? 'O' : 'X';

	int i = (y - 6) / 2 - 1;
	int j = (x - 2) / 4;

	int count = 0;

	while (i >= 0 && chessBoard[i][j] == ch)
	{
		++count;
		--i;
	}

	if (chessBoard[i][j] == tmp)
		check = 1;

	return count;
}

int Up_Left(char chessBoard[maxRow][maxColum], int y, int x, char ch, int &check)
{
	char tmp = ch == 'X' ? 'O' : 'X';

	int i = (y - 6) / 2 - 1;
	int j = (x - 2) / 4 - 1;

	int count = 0;

	while (i >= 0 && j >= 0 && chessBoard[i][j] == ch)
	{
		++count;
		--i;
		--j;
	}

	if (chessBoard[i][j] == tmp)
		check = 1;

	return count;
}

int Up_Right(char chessBoard[maxRow][maxColum], int y, int x, char ch, int &check)
{
	char tmp = ch == 'X' ? 'O' : 'X';

	int i = (y - 6) / 2 - 1;
	int j = (x - 2) / 4 + 1;

	int count = 0;

	while (i >= 0 && j < maxColum && chessBoard[i][j] == ch)
	{
		++count;
		--i;
		++j;
	}

	if (chessBoard[i][j] == tmp)
		check = 1;

	return count;
}

int Down(char chessBoard[maxRow][maxColum], int y, int x, char ch, int &check)
{
	char tmp = ch == 'X' ? 'O' : 'X';

	int i = (y - 6) / 2 + 1;
	int j = (x - 2) / 4;

	int count = 0;

	while (i < maxRow && chessBoard[i][j] == ch)
	{
		++count;
		++i;
	}

	if (chessBoard[i][j] == tmp)
		check = 1;

	return count;
}

int Down_Left(char chessBoard[maxRow][maxColum], int y, int x, char ch, int &check)
{
	char tmp = ch == 'X' ? 'O' : 'X';

	int i = (y - 6) / 2 + 1;
	int j = (x - 2) / 4 - 1;

	int count = 0;

	while (i < maxRow && j >= 0 && chessBoard[i][j] == ch)
	{
		++count;
		++i;
		--j;
	}

	if (chessBoard[i][j] == tmp)
		check = 1;

	return count;
}

int Down_Right(char chessBoard[maxRow][maxColum], int y, int x, char ch, int &check)
{
	char tmp = ch == 'X' ? 'O' : 'X';

	int i = (y - 6) / 2 + 1;
	int j = (x - 2) / 4 + 1;

	int count = 0;

	while (i < maxRow && j < maxColum && chessBoard[i][j] == ch)
	{
		++count;
		++i;
		++j;
	}

	if (chessBoard[i][j] == tmp)
		check = 1;

	return count;
}

int Left(char chessBoard[maxRow][maxColum], int y, int x, char ch, int &check)
{
	char tmp = ch == 'X' ? 'O' : 'X';

	int i = (y - 6) / 2;
	int j = (x - 2) / 4 - 1;

	int count = 0;

	while (j >= 0 && chessBoard[i][j] == ch)
	{
		++count;
		--j;
	}

	if (chessBoard[i][j] == tmp)
		check = 1;

	return count;
}

int Right(char chessBoard[maxRow][maxColum], int y, int x, char ch, int &check)
{
	char tmp = ch == 'X' ? 'O' : 'X';

	int i = (y - 6) / 2;
	int j = (x - 2) / 4 + 1;

	int count = 0;

	while (j < maxColum && chessBoard[i][j] == ch)
	{
		++count;
		++j;
	}

	if (chessBoard[i][j] == tmp)
		check = 1;

	return count;
}

bool WinGame(char chessBoard[maxRow][maxColum], Player player, char ch)
{
	bool End = false;

	int checkUp = 0, checkUpLeft = 0, checkUpRight = 0, checkDown = 0, checkDownLeft = 0, checkDownRight = 0, checkLeft = 0, checkRight = 0;

	int up = Up(chessBoard, player.local.y, player.local.x, ch, checkUp);
	int up_left = Up_Left(chessBoard, player.local.y, player.local.x, ch, checkUpLeft);
	int up_right = Up_Right(chessBoard, player.local.y, player.local.x, ch, checkUpRight);
	int down = Down(chessBoard, player.local.y, player.local.x, ch, checkDown);
	int down_left = Down_Left(chessBoard, player.local.y, player.local.x, ch, checkDownLeft);
	int down_right = Down_Right(chessBoard, player.local.y, player.local.x, ch, checkDownRight);
	int left = Left(chessBoard, player.local.y, player.local.x, ch, checkLeft);
	int right = Right(chessBoard, player.local.y, player.local.x, ch, checkRight);


	if ((up + down == 4 && checkUp + checkDown < 2) || up + down > 4)
	{
		End = true;
	}

	if ((up_left + down_right == 4 && checkUpLeft + checkDownRight < 2) || up_left + down_right > 4)
	{
		End = true;
	}

	if ((up_right + down_left == 4 && checkUpRight + checkDownLeft < 2) || up_right + down_left > 4)
	{
		End = true;
	}

	if ((left + right == 4 && checkLeft + checkRight < 2) || left + right > 4)
	{
		End = true;
	}

	if (player.point >= maxRow * maxColum / 2)
		End = true;

	return End;
}

