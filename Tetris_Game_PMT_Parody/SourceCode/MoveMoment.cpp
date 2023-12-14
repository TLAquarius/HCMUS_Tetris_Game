#include "Mechanic.h"

void Mechanic::rotate()
{
	curBlock.rotate();
	while (curBlock.isOutOfBound() == 1 && !isCollision())
	{
		moveRight();
	}
	while (curBlock.isOutOfBound() == 2 && !isCollision())
	{
		moveLeft();
	}
	while (curBlock.isOutOfBound() == 3 && !isCollision())
	{
		moveDown();
	}
	while (curBlock.isOutOfBound() == 4 && !isCollision())
	{
		moveUp();
	}
	if (isCollision())
	{
		curBlock.counterRotate();
	}
}
void Mechanic::counterRotate()
{
	curBlock.counterRotate();
	while (curBlock.isOutOfBound() == 1 && !isCollision())
	{
		moveRight();
	}
	while (curBlock.isOutOfBound() == 2 && !isCollision())
	{
		moveLeft();
	}
	while (curBlock.isOutOfBound() == 3 && !isCollision())
	{
		moveDown();
	}
	while (curBlock.isOutOfBound() == 4 && !isCollision())
	{
		moveUp();
	}
	if (isCollision())
	{
		curBlock.rotate();
	}
}
void Mechanic::moveDown()
{
	if (!gameOver)
	{
		curBlock.move(1, 0);
		if (curBlock.isOutOfBound() == 4 || isCollision())
		{
			moveUp();
			lock();
		}
	}
}
void Mechanic::moveLeft()
{
	curBlock.move(0, -1);
	if (curBlock.isOutOfBound() == 1 ||isCollision())
		curBlock.move(0, 1);
}
void Mechanic::moveRight()
{
	curBlock.move(0, 1);
	if (curBlock.isOutOfBound() == 2 || isCollision())
		curBlock.move(0, -1);
}

void Mechanic::moveUp()
{
	curBlock.move(-1, 0);
}

void Mechanic::drop()
{
	curBlock.setY(curBlock.getSY());
	lock();
	
}

void Mechanic::lock()
{
	vector <Pos> temp = curBlock.getCurPos();
	for (int i = 0; i < temp.size(); i++)
	{
		f.field[temp[i].getY() + curBlock.getY()][temp[i].getX() + curBlock.getX()] = curBlock.getType();
	}
	int templ = f.clearLine();
	s.setLineClear(templ);
	s.setScore(templ, level);
	if (s.getScore() > s.getHighScore())
	{
		s.setHighScore(s.getScore());
	}
	if (s.getLineClear() >= level * 10+10)
	{
		level++;
	}
	if (!gameOver)
	{
		curBlock = nextBlocks.front();
	}
	if (isCollision())
	{
		gameOver = true;
	}
	else
	{
		s.setPieceDrop(1);
		holdFlag = false;
		nextBlocks.pop();
		nextBlocks.push(blockGenerator());
	}
}