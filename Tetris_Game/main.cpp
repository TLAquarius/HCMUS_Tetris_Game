#include <raylib.h>
#include <iostream>
#include "PlayField.hpp"
#include "Block.hpp"
#include "Mechanic.h"
#include "Menu.h"
using namespace std;

int main()
{
	InitWindow(1124, 820, "Tetris_Group08");
	SetTargetFPS(60);
	Mechanic gamePlay;

	Menu menu;
	while (WindowShouldClose() == false)
	{
		menu.DrawMenu();
		if (menu.isClickStartBox()) {
			while (!IsKeyPressed(KEY_Q) && !WindowShouldClose()) {
				BeginDrawing();
				if (gamePlay.logic())
				{
					EndDrawing();
					break;
				}
				EndDrawing();
			}
		}
		else if (menu.isClickAboutBox()) {
			while (WindowShouldClose() == false)
			{
				menu.About();
				if (IsGestureDetected(GESTURE_TAP))
					break;
			}
		}
		else if (menu.isClickHowToPlay()) {
			while (WindowShouldClose()==false) {
				menu.HowToPlay();
				if (IsGestureDetected(GESTURE_TAP))
					break;
			}
		}
	}
	CloseWindow();
	return 0;
}