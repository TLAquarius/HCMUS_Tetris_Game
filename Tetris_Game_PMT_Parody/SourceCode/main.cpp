#include <raylib.h>
#include <iostream>
#include "PlayField.hpp"
#include "Block.hpp"
#include "Mechanic.h"
#include "Menu.h"
using namespace std;

int main()
{
	InitWindow(1124,820,"Tetris_Group08");
	SetTargetFPS(60);
	Rectangle StartBox = { 350, 445, 425, 50 };
	Rectangle AboutBox = { 350, 495, 425, 50 };
	Rectangle HowToPlayBox = { 350, 545, 425, 50 };
	Mechanic gamePlay;
	
	Menu Menu;
	while (WindowShouldClose() == false)
	{
		Menu.DrawMenu(StartBox, AboutBox, HowToPlayBox);
		if (CheckCollisionPointRec(GetMousePosition(), StartBox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			while (!IsKeyPressed(KEY_Q) && !WindowShouldClose()) {
				BeginDrawing();
				if (gamePlay.eventTrigger(gamePlay.fallSpeed(), gamePlay.fallTime))
				{
					gamePlay.moveDown();
				}
				gamePlay.control();

				while (gamePlay.gameOver) {
					long a = gamePlay.s.getScore();
					Menu.GameOverMenu(a);
					gamePlay.draw();
					if (IsKeyPressed(KEY_R)){
						gamePlay.restart();
						break;
					}
					if (IsKeyPressed(KEY_M)) {
						gamePlay.restart();
						!gamePlay.gameOver;
						break;
					}
				}
				if (IsKeyPressed(KEY_M)) {
					break;
				}
				gamePlay.draw();
				EndDrawing();
				}
		}
		else if (CheckCollisionPointRec(GetMousePosition(), AboutBox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			while (true && !WindowShouldClose()) {
				Menu.About();
				if (IsGestureDetected(GESTURE_TAP))
					break;
			}	
		}
		else if (CheckCollisionPointRec(GetMousePosition(), HowToPlayBox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			while (true && !WindowShouldClose()) {
				Menu.HowToPlay();
				if (IsGestureDetected(GESTURE_TAP))
					break;
				
			}
		}
	}
	CloseWindow();
	return 0;
}