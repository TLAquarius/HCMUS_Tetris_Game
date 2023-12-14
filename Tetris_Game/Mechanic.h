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
private:
	Field f;
	Score s;
	bool gameOver;
	bool holdFlag;
	bool pause;
	double level;
	double controlTime;
	double fallTime;
	Block curBlock;
	queue<Block> nextBlocks;
	Block holdBlock;
	vector<Block> blockL;
public:
	Mechanic();
	Block blockGenerator();
	void control();
	double fallSpeed();
	bool eventTrigger(double speed,double& flag);
	
	bool isCollision();
	void draw();
	void updateShadow();
	
	bool getPause();
	void logic();

	void rotate();
	void moveDown();
	void moveLeft();
	void moveRight();
	void moveUp();
	void counterRotate();
	void drop();
	void lock();
	void hold();
	void restart();
};