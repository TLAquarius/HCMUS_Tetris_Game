#include "Block.hpp"

Block::Block()
{
	x = 3;
	y = 0;
	color = 0;
	state = 0;
	shadowY = 0;
}

int Block::getType()
{
	return color;
}

int Block::getX()
{
	return x;
}

int Block::getY()
{
	return y;
}
void Block::setX(int x)
{
	this->x = x;
}

void Block::setY(int y)
{
	this->y = y;
}
int Block::getSY()
{
	return shadowY;
}
void Block::setSY(int y)
{
	shadowY = y;
}

void Block::setState(int state)
{
	this->state = state;
}

void Block::draw()
{
	for (int i = 0; i < cells[state].size(); i++)
	{
		DrawRectangle(((cells[state][i].getX()+x)*cellSize + gameOffsetX+1),
			((cells[state][i].getY()+y)*cellSize+gameOffsetY + 1),
			cellSize-2,cellSize-2,colorList[color]);
	}
}

void Block::drawHoldBlock()
{
	DrawRectangle(holdOffsetX, holdOffsetY, 200, 160, BLACK);
	DrawText(TextFormat("HOLD BLOCK"), holdOffsetX + 35, holdOffsetY + 10, 20, GRAY);
	if (color != 0)
	{
		for (int i = 0; i < cells[state].size(); i++)
		{
			DrawRectangle(((cells[state][i].getX() + x) * cellSize + holdOffsetX - 80),
				((cells[state][i].getY() + y) * cellSize + holdOffsetY + 50),
				cellSize - 2, cellSize - 2, colorList[color]);
		}
	}
}

void Block::drawNextBlock()
{
	DrawRectangle(nextOffsetX, nextOffsetY, 240, 160, BLACK);
	DrawText(TextFormat("NEXT BLOCK"), nextOffsetX + 55, nextOffsetY + 10, 20, GRAY);
	for (int i = 0; i < cells[state].size(); i++)
	{
		DrawRectangle(((cells[state][i].getX() + x) * cellSize + nextOffsetX - 60),
			((cells[state][i].getY() + y) * cellSize + nextOffsetY + 50),
			cellSize - 2, cellSize - 2, colorList[color]);
	}
}

void Block::drawShadow()
{
	for (int i = 0; i < cells[state].size(); i++)
	{
		DrawRectangle(((cells[state][i].getX() + x) * cellSize + gameOffsetX + 1),
			((cells[state][i].getY() + shadowY) * cellSize + gameOffsetY + 1),
			cellSize - 2, cellSize - 2, Fade(WHITE,0.25));
	}
}

void Block::move(int row, int col)
{
	x += col;
	y += row;
}

void Block::rotate()
{
	state++;
	state = state % cells.size();
}

void Block::counterRotate()
{
	state--;
	if (state == -1)
		state = cells.size() - 1;
}

vector<Pos> Block::getCurPos()
{
	return cells[state];
}

int Block::isOutOfBound()
{
	for (int i = 0; i < cells[state].size(); i++)
	{
		int xBound = cells[state][i].getX() + x;
		int yBound = cells[state][i].getY() + y;
		if (xBound < 0)
		{
			return 1;
		}
		else if (xBound > 9)
		{
			return 2;
		}
		else if (yBound < 0)
		{
			return 3;
		}
		else if (yBound > 19)
		{
			return 4;
		}
	}
	return 0;
}

IBlock::IBlock()
{
	color = 1;
	cells.push_back({ Pos(1, 0), Pos(1, 1), Pos(1, 2), Pos(1, 3) });
	cells.push_back({ Pos(0, 2), Pos(1, 2), Pos(2, 2), Pos(3, 2) });
	cells.push_back({ Pos(2, 0), Pos(2, 1), Pos(2, 2), Pos(2, 3) });
	cells.push_back({ Pos(0, 1), Pos(1, 1), Pos(2, 1), Pos(3, 1) });
}
JBlock::JBlock()
{
	color = 6;
	cells.push_back({ Pos(0, 0), Pos(1, 0), Pos(1, 1), Pos(1, 2) });
	cells.push_back({ Pos(0, 1), Pos(0, 2), Pos(1, 1), Pos(2, 1) });
	cells.push_back({ Pos(1, 0), Pos(1, 1), Pos(1, 2), Pos(2, 2) });
	cells.push_back({ Pos(0, 1), Pos(1, 1), Pos(2, 1), Pos(2, 0) });
}
LBlock::LBlock()
{
	color = 7;
	cells.push_back({ Pos(0, 2), Pos(1, 0), Pos(1, 1), Pos(1, 2) });
	cells.push_back({ Pos(0, 1), Pos(1, 1), Pos(2, 1), Pos(2, 2) });
	cells.push_back({ Pos(1, 0), Pos(1, 1), Pos(1, 2), Pos(2, 0) });
	cells.push_back({ Pos(0, 0), Pos(0, 1), Pos(1, 1), Pos(2, 1) });
}
SBlock::SBlock()
{
	color = 4;
	cells.push_back({ Pos(0, 1), Pos(0, 2), Pos(1, 0), Pos(1, 1) });
	cells.push_back({ Pos(0, 1), Pos(1, 1), Pos(1, 2), Pos(2, 2) });
	cells.push_back({ Pos(1, 1), Pos(1, 2), Pos(2, 0), Pos(2, 1) });
	cells.push_back({ Pos(0, 0), Pos(1, 0), Pos(1, 1), Pos(2, 1) });
}
ZBlock::ZBlock()
{
	color = 5;
	cells.push_back({ Pos(0, 0), Pos(0, 1), Pos(1, 1), Pos(1, 2) });
	cells.push_back({ Pos(0, 2), Pos(1, 1), Pos(1, 2), Pos(2, 1) });
	cells.push_back({ Pos(1, 0), Pos(1, 1), Pos(2, 1), Pos(2, 2) });
	cells.push_back({ Pos(0, 1), Pos(1, 0), Pos(1, 1), Pos(2, 0) });
}
OBlock::OBlock()
{
	color = 2;
	x = 4;
	cells.push_back({ Pos(0, 0), Pos(0, 1), Pos(1, 0), Pos(1, 1) });
}
TBlock::TBlock()
{
	color = 3;
	cells.push_back({ Pos(0, 1), Pos(1, 0), Pos(1, 1), Pos(1, 2) });
	cells.push_back({ Pos(0, 1), Pos(1, 1), Pos(1, 2), Pos(2, 1) });
	cells.push_back({ Pos(2, 1), Pos(1, 0), Pos(1, 1), Pos(1, 2) });
	cells.push_back({ Pos(0, 1), Pos(1, 0), Pos(1, 1), Pos(2, 1) });
}