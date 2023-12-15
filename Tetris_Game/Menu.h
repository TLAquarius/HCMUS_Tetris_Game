#pragma once
#include "Colors.hpp"
#include <raylib.h>

class Menu {
private:
	Rectangle StartBox = { 350, 445, 425, 50 };
	Rectangle AboutBox = { 350, 495, 425, 50 };
	Rectangle HowToPlayBox = { 350, 545, 425, 50 };
public:
	void DrawMenu();
	void About();
	void HowToPlay();
	void GameOverMenu(long a);
	bool isClickStartBox();
	bool isClickAboutBox();
	bool isClickHowToPlay();
};

