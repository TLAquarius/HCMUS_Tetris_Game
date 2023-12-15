#include "Menu.h"
#include "Score.hpp"
#include "Mechanic.h"

void Menu::DrawMenu() {
	BeginDrawing();

	DrawRectangleRec(StartBox, LIGHTGRAY);
	DrawRectangleLines((int)StartBox.x, (int)StartBox.y, (int)StartBox.width, (int)StartBox.height, BLACK);

	DrawRectangleRec(AboutBox, LIGHTGRAY);
	DrawRectangleLines((int)AboutBox.x, (int)AboutBox.y, (int)AboutBox.width, (int)AboutBox.height, BLACK);

	DrawRectangleRec(HowToPlayBox, LIGHTGRAY);
	DrawRectangleLines((int)HowToPlayBox.x, (int)HowToPlayBox.y, (int)HowToPlayBox.width, (int)HowToPlayBox.height, BLACK);

	ClearBackground(DARKGRAY);

	DrawText(TextFormat("TETRIS"), 170, 50, 200, GREEN);
	DrawText(TextFormat(" START GAME"), 400, 450, 40, BLACK);
	DrawText(TextFormat("     ABOUT"), 405, 500, 40, BLACK);
	DrawText(TextFormat(" HOW TO PLAY"), 400, 550, 40, BLACK);
	DrawText(TextFormat("Press ESC to quit program"), 800, 700, 20, RED);

	EndDrawing();
}


void Menu::About() {
	BeginDrawing();
	ClearBackground(DARKGRAY);

	DrawText(TextFormat("Danh Sach Thanh Vien Nhom"), 250, 100, 40, RED);
	DrawText(TextFormat("Nguyen Anh Hoang		22127124"), 200, 250, 20, BLACK);
	DrawText(TextFormat("Tran Nguyen Loc Quy	22127356"), 200, 280, 20, BLACK);
	DrawText(TextFormat("Le Phuoc Thanh			22127392"), 200, 310, 20, BLACK);
	DrawText(TextFormat("Pham Manh Trung		22127430"), 200, 340, 20, BLACK);

	DrawText(TextFormat("LEFT CLICK to return to main menu"), 200, 600, 20, GREEN);
	EndDrawing();
}

void Menu::HowToPlay() {
	BeginDrawing();
	ClearBackground(DARKGRAY);

	DrawText(TextFormat("Rule: you can only move the pieces in specific ways"), 200, 100, 20, BLACK);
	DrawText(TextFormat("your game is over if your pieces reach the top of the screen."), 200, 120, 20, BLACK);
	DrawText(TextFormat("you can only remove pieces from the screen by filling all the blank space in a line."), 200, 140, 20, BLACK);
	DrawText(TextFormat("CONTROL: USE -ARROWS KEY TO MOVE THE PIECES.\n-UP key or Z and X key for rotation.\n-C to hold piece\n-SPACE to drop piece"), 200, 180, 20, BLACK);

	DrawText(TextFormat("LEFT CLICK to return to main menu"), 200, 600, 20, GREEN);
	EndDrawing();
}

void Menu::GameOverMenu(long a) {
	BeginDrawing();
	Rectangle GameOverBox = { 300, 300, 600, 400 };
	DrawRectangleRec(GameOverBox, LIGHTGRAY);
	DrawRectangleLines((int)GameOverBox.x, (int)GameOverBox.y, (int)GameOverBox.width, (int)GameOverBox.height, BLACK);

	DrawText(TextFormat("  GAME OVER"), 330, 350, 70, RED);
	DrawText(TextFormat("Score: %08i", a), 330, 500, 20, RED);
	DrawText(TextFormat("Press R to restart"), 330, 600, 20, BLACK);
	DrawText(TextFormat("Press M to return to menu"), 330, 650, 20, BLACK);

	EndDrawing();
}


bool Menu::isClickStartBox()
{
	return (CheckCollisionPointRec(GetMousePosition(), StartBox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}

bool Menu::isClickAboutBox()
{
	return (CheckCollisionPointRec(GetMousePosition(), AboutBox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}

bool Menu::isClickHowToPlay()
{
	return (CheckCollisionPointRec(GetMousePosition(), HowToPlayBox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}