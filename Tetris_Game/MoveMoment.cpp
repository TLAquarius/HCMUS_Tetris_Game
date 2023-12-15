#include "Mechanic.h"

void Mechanic::rotate()
{
	curBlock.rotate();
	//them am thanh di chuyen tuong ung vo may method cua movement
	int count = 0;
	while (curBlock.isOutOfBound() == 1)
	{
		curBlock.move(0, 1);
		count++;
		if (isCollision())
		{
			while (count > 0)
			{
				curBlock.move(0, -1);
				count--;
			}
			curBlock.counterRotate();
			break;
		}
	}
	while (curBlock.isOutOfBound() == 2)
	{
		curBlock.move(0,-1);
		count++;
		if (isCollision())
		{
			while (count > 0)
			{
				curBlock.move(0, 1);
				count--;
			}
			curBlock.counterRotate();
			break;
		}
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
	int count = 0;
	while (curBlock.isOutOfBound() == 1)
	{
		curBlock.move(0,1);
		count++;
		if (isCollision())
		{
			while (count > 0)
			{
				curBlock.move(0, -1);
				count--;
			}
			curBlock.rotate();
			break;
		}
	}
	while (curBlock.isOutOfBound() == 2)
	{
		curBlock.move(0,-1);
		count++;
		if (isCollision())
		{
			while (count > 0)
			{
				curBlock.move(0, 1);
				count--;
			}
			curBlock.rotate();
			break;
		}
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

void Mechanic::hold()
{
	if (holdBlock.getType() == 0)
	{
		holdBlock = curBlock;
		curBlock = nextBlocks.front();
		nextBlocks.pop();
		nextBlocks.push(blockGenerator());
	}
	else
	{
		Block temp = curBlock;
		curBlock = holdBlock;
		holdBlock = temp;
	}
	holdBlock.setX(3);
	holdBlock.setY(0);
	holdBlock.setState(0);
	holdFlag = true;
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
		s.saveHighScore();
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