#pragma once
#include <raylib.h>
#include "GUI_Const.hpp"
using namespace std;

class Score
{
private:
	int lineClear;
	long score;
	long highScore;
	int pieceDrop;
public:
	Score();
	int getLineClear();
	int getPieceDrop();
	long getScore();
	long getHighScore();
	void setHighScore(long score);
	void setLineClear(int num);
	void setPieceDrop(int num);
	void setScore(long num, int speedLevel);
	void draw();
};