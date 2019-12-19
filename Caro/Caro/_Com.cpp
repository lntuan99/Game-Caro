#include "_Com.h"

long Attack[] = { 0, 2, 28, 256, 2308 };
long Defense[] = { 0, 1, 9, 85, 769 };

//long Attack[] = { 0, 3, 45, 315, 3465, 31185 };
//long Defense[] = { 0, 2, 30, 270, 3240, 29160 };

long matrixpoint[maxRow + 1][maxColum + 1];

int depth = 0;

Node myMoves[maxBreadth + 1];
Node hisMoves[maxBreadth + 1];
Node winMoves[100];

bool win, lose;

void resetMatrix()
{
	int i, j;

	for (i = 0; i < maxRow + 1; ++i)
		for (j = 0; j < maxColum + 1; ++j)
		{
			matrixpoint[i][j] = 0;
		}

}

Node getMaxNode()
{
	int i, j;
	Node tmp;

	tmp.row = 0;
	tmp.colum = 0;
	tmp.max = matrixpoint[0][0];

	for (i = 0; i < maxRow; ++i)
		for (j = 0; j < maxColum; ++j)
			if (tmp.max < matrixpoint[i][j])
			{
				tmp.max = matrixpoint[i][j];
				tmp.row = i;
				tmp.colum = j;
			}

	return tmp;
}

void scoreBoard(char chessBoard[maxRow][maxColum], char player)
{
	int row, colum;
	int nX, nO;

	//Dọc
	for (row = 0; row < maxRow; ++row)
		for (colum = 0; colum < maxColum - 4; ++colum)
		{
			nX = 0;
			nO = 0;

			int i;
			for (i = 0; i < 5; ++i)
			{
				if (chessBoard[row][colum + i] == 'X') ++nX;
				if (chessBoard[row][colum + i] == 'O') ++nO;
			}

			if (nX * nO == 0 && nX != nO)
				for (i = 0; i < 5; ++i)
					if (chessBoard[row][colum + i] == ' ')
					{
						if (nX == 0)
						{
							if (player == 'X')
								matrixpoint[row][colum + i] += Defense[nO];
							else
								matrixpoint[row][colum + i] += Attack[nO];

							if (chessBoard[row][colum - 1] == 'X' && chessBoard[row][colum + 5] == 'X')
								matrixpoint[row][colum + i] = 0;
						}

						if (nO == 0)
						{
							if (player == 'O')
								matrixpoint[row][colum + i] += Defense[nX];
							else
								matrixpoint[row][colum + i] += Attack[nX];

							if (chessBoard[row][colum - 1] == 'O' && chessBoard[row][colum + 5] == 'O')
								matrixpoint[row][colum + i] = 0;
						}

						if ((nX == 4 || nO == 4) && (chessBoard[row][colum + i - 1] == ' ' || chessBoard[row][colum + i + 1] == ' '))
							matrixpoint[row][colum + i] *= 2;
					}

		}

	//Ngang
	for (colum = 0; colum < maxColum; ++colum)
		for (row = 0; row < maxRow - 4; ++row)
		{
			nX = 0;
			nO = 0;

			int i;
			for (i = 0; i < 5; ++i)
			{
				if (chessBoard[row + i][colum] == 'X') ++nX;
				if (chessBoard[row + i][colum] == 'O') ++nO;
			}

			if (nX * nO == 0 && nX != nO)
				for (i = 0; i < 5; ++i)
					if (chessBoard[row + i][colum] == ' ')
					{
						if (nX == 0)
						{
							if (player == 'X')
								matrixpoint[row + i][colum] += Defense[nO];
							else
								matrixpoint[row + i][colum] += Attack[nO];

							if (chessBoard[row - 1][colum] == 'X' && chessBoard[row + 5][colum] == 'X')
								matrixpoint[row + i][colum] = 0;
						}

						if (nO == 0)
						{
							if (player == 'O')
								matrixpoint[row + i][colum] += Defense[nX];
							else
								matrixpoint[row + i][colum] += Attack[nX];

							if (chessBoard[row - 1][colum] == 'O' && chessBoard[row + 5][colum] == 'O')
								matrixpoint[row + i][colum] = 0;
						}

						if ((nX == 4 || nO == 4) && (chessBoard[row + i - 1][colum] == ' ' || chessBoard[row + i + 1][colum] == ' '))
							matrixpoint[row + i][colum] *= 2;
					}
		}

	//Chéo chính
	for (row = 0; row < maxRow - 4; ++row)
		for (colum = 0; colum < maxColum - 4; ++colum)
		{
			nX = 0;
			nO = 0;

			int i;
			for (i = 0; i < 5; ++i)
			{
				if (chessBoard[row + i][colum + i] == 'X') ++nX;
				if (chessBoard[row + i][colum + i] == 'O') ++nO;
			}

			if (nX * nO == 0 && nX != nO)
				for (i = 0; i < 5; ++i)
					if (chessBoard[row + i][colum + i] == ' ')
					{
						if (nX == 0)
						{
							if (player == 'X')
								matrixpoint[row + i][colum + i] += Defense[nO];
							else
								matrixpoint[row + i][colum + i] += Attack[nO];

							if (chessBoard[row - 1][colum - 1] == 'X' && chessBoard[row + 5][colum + 5] == 'X')
								matrixpoint[row + i][colum + i] = 0;
						}

						if (nO == 0)
						{
							if (player == 'O')
								matrixpoint[row + i][colum + i] += Defense[nX];
							else
								matrixpoint[row + i][colum + i] += Attack[nX];

							if (chessBoard[row - 1][colum - 1] == 'O' && chessBoard[row + 5][colum + 5] == 'O')
								matrixpoint[row + i][colum + i] = 0;
						}

						if ((nX == 4 || nO == 4) && (chessBoard[row + i - 1][colum + i - 1] == ' ' || chessBoard[row + i + 1][colum + i + 1] == ' '))
							matrixpoint[row + i][colum + i] *= 2;
					}

		}

	//Chéo phụ
	for (row = 4; row < maxRow - 4; ++row)
		for (colum = 0; colum < maxColum - 4; ++colum)
		{
			nX = 0;
			nO = 0;

			int i;
			for (i = 0; i < 5; ++i)
			{
				if (chessBoard[row - i][colum + i] == 'X') ++nX;
				if (chessBoard[row - i][colum + i] == 'O') ++nO;
			}

			if (nX * nO == 0 && nX != nO)
				for (i = 0; i < 5; ++i)
					if (chessBoard[row - i][colum + i] == ' ')
					{
						if (nX == 0)
						{
							if (player == 'X')
								matrixpoint[row - i][colum + i] += Defense[nO];
							else
								matrixpoint[row - i][colum + i] += Attack[nO];

							if (chessBoard[row + 1][colum - 1] == 'X' && chessBoard[row - 5][colum + 5] == 'X')
								matrixpoint[row - i][colum + i] = 0;
						}

						if (nO == 0)
						{
							if (player == 'O')
								matrixpoint[row - i][colum + i] += Defense[nX];
							else
								matrixpoint[row - i][colum + i] += Attack[nX];

							if (chessBoard[row + 1][colum - 1] == 'O' && chessBoard[row - 5][colum + 5] == 'O')
								matrixpoint[row - i][colum + i] = 0;
						}

						if ((nX == 4 || nO == 4) && (chessBoard[row - i + 1][colum + i - 1] == ' ' || chessBoard[row - i - 1][colum + i + 1] == ' '))
							matrixpoint[row - i][colum + i] *= 2;
					}
		}
}

void Move(char chessBoard[maxRow][maxColum], int maxDepth)
{
	if (depth > maxDepth) return;
	depth++;

	int i;
	bool _lose = false;
	win = false;

	Node myNode;
	Node hisNode;
	int count = 0;

	scoreBoard(chessBoard, 'X');

	for (i = 1; i <= maxBreadth; ++i)
	{
		myNode = getMaxNode();
		myMoves[i] = myNode;
		matrixpoint[myNode.row][myNode.colum] = 0;
	}

	// -- Lay nuoc di
	count = 0;
	while (count < maxBreadth)
	{
		count++;
		myNode = myMoves[count];
		winMoves[depth] = myNode;
		chessBoard[myNode.row][myNode.colum] = 'X';

		// Tim cac nuoc di toi uu cua doi thu
		resetMatrix();
		scoreBoard(chessBoard, 'O');

		for (i = 1; i <= maxBreadth; i++)
		{
			hisNode = getMaxNode();
			hisMoves[i] = hisNode;
			matrixpoint[hisNode.row][hisNode.colum] = 0;
		}
		for (i = 1; i <= maxBreadth; i++)
		{
			hisNode = hisMoves[i];
			chessBoard[hisNode.row][hisNode.colum] = 'O';

			Player tmp;
			tmp.local.x = myNode.colum * 4 + 2;
			tmp.local.y = (myNode.row + 1) * 2 + 6;

			if (WinGame(chessBoard, tmp, 'X'))
				win = true;

			tmp.local.x = hisNode.colum * 4 + 2;
			tmp.local.y = (hisNode.row + 1) * 2 + 6;

			if (WinGame(chessBoard, tmp, 'O'))
				_lose = true;

			if (_lose)
			{
				lose = true;
				chessBoard[hisNode.row][hisNode.colum] = ' ';
				chessBoard[myNode.row][myNode.colum] = ' ';
				return;
			}

			if (win)
			{
				chessBoard[hisNode.row][hisNode.colum] = ' ';
				chessBoard[myNode.row][myNode.colum] = ' ';
				return;
			}

			else Move(chessBoard, maxDepth);

			chessBoard[hisNode.row][hisNode.colum] = ' ';
		}
		chessBoard[myNode.row][myNode.colum] = ' ';
	}
}

void getGenResult(char chessBoard[maxRow][maxColum], long matrixpoint[maxRow + 1][maxColum + 1], int maxDepth)
{
	int i;

	win = lose = false;
	for (i = 0; i <= maxDepth; i++)
	{
		Node n;
		n.row = 0;
		n.colum = 0;
		winMoves[i] = n;
	}

	for (i = 0; i < maxBreadth; i++)
	{
		Node n;
		n.row = 0;
		n.colum = 0;
		myMoves[i] = n;
	}

	depth = 0;
	Move(chessBoard, maxDepth);
}

void Computer(char chessBoard[maxRow][maxColum], int point, bool &EndGame, int maxDepth, stack<Node> &MOVE)
{
	Node n;
	int row, colum, i;
	int count = rand() % 4;
	resetMatrix();

	getGenResult(chessBoard, matrixpoint, maxDepth);

	if (win)
	{
		n = winMoves[1];
	}
	else
	{
		resetMatrix();
		scoreBoard(chessBoard, 'X');
		n = getMaxNode();
		if (!lose)
		{
			for (i = 0; i < count; ++i)
			{
				matrixpoint[n.row][n.colum] = 0;
				n = getMaxNode();
			}
		}
	}

	row = n.row; colum = n.colum;
	MOVE.push(n);

	setCharacterInChessBoard(chessBoard, row * 2 + 6, colum * 4 + 2, 'X');

	gotoXY(colum * 4 + 2, row * 2 + 6);
	TextColor(7);
	printf(" X ");

	Player Com;

	Com.local.y = row * 2 + 6;
	Com.local.x = colum * 4 + 2;
	Com.point = point;

	EndGame = WinGame(chessBoard, Com, 'X');
}