#pragma once
#include "Colors.hpp"
#include <raylib.h>

class Menu {
public:
	void DrawMenu(Rectangle StartBox, Rectangle AboutBox, Rectangle HowToPlayBox);
	void About();
	void HowToPlay();
	void GameOverMenu(long a);
};

