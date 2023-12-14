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
		if (gamePlay.getPause() == false)
		{
			gamePlay.logic();//thiet ke man hinh pause + game over
		}
		else if(IsKeyPressed(KEY_R))
		{
			gamePlay.restart();
		}
		else if (IsKeyPressed(KEY_Q))
		{
			//thoat ra menu
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}