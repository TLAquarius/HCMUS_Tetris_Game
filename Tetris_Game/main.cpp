#include <raylib.h>
#include <iostream>
#include "PlayField.hpp"
#include "Block.hpp"
#include "Mechanic.h"
using namespace std;

int main()
{
	InitWindow(1124,820,"Tetris_Group08");
	SetTargetFPS(60);
	Mechanic gamePlay;
	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		gamePlay.logic();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}