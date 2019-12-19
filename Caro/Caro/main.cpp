#include "mainGame.h"
#include <stdlib.h>
#include <Windows.h>

int main(void)
{
	int horizontal = 0;
	int vertical = 0;

	GetDesktopResolution(horizontal, vertical);
	resizeConsole(horizontal, vertical);
	FixConsoleWindow();

	play();

	return 0;
}