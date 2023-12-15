#pragma once
#include <vector>
#include <raylib.h>
#include "Position.hpp"
#include "Colors.hpp"
#include "GUI_Const.hpp"
using namespace std;

class Block
{
protected:
	int color;
	int x;
	int y;
	int shadowY;
	vector <vector<Pos>> cells;
public:
	Block();
	int state;
	vector<Pos> getCurPos();
	void setState(int state);
	int getType();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	int getSY();
	void setSY(int y);
	void draw();
	void drawHoldBlock();
	void drawNextBlock();
	void drawShadow();
	void move(int row, int col);
	void rotate();
	void counterRotate();
	int isOutOfBound();
};

class IBlock:public Block
{
public:
	IBlock();
};

class JBlock :public Block
{
public:
	JBlock();
};

class LBlock :public Block
{
public:
	LBlock();
};

class ZBlock :public Block
{
public:
	ZBlock();
};

class SBlock :public Block
{
public:
	SBlock();
};

class OBlock :public Block
{
public:
	OBlock();
};

class TBlock :public Block
{
public:
	TBlock();
};