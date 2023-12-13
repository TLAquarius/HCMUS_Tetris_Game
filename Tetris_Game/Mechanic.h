#pragma once
#include "Block.hpp"
#include "PlayField.hpp"
#include "Colors.hpp"
#include "GUI_Const.hpp"
#include "Score.hpp"
#include <time.h>
#include <vector>
#include <queue>
using namespace std;

class Mechanic
{
public:
	Mechanic();
	Field f;
	Score s;
	bool gameOver;
	bool holdFlag;
	Block blockGenerator();
	void control();
	Block curBlock;
	queue<Block> nextBlocks;
	Block holdBlock;
	double speedLevel;
	double controlTime;
	double fallTime;
	bool eventTrigger(double speed,double& flag);
	void draw();
	void rotate();
	bool isCollision();
	void moveDown();
	void moveLeft();
	void moveRight();
	void moveUp();
	void counterRotate();
	void drop();
	void lock();
	void hold();
	void restart();
	vector<Block> blockL;

};