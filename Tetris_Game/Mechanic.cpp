#include "Mechanic.h"

Mechanic::Mechanic()
{
	blockL = { LBlock(), JBlock(), ZBlock(), SBlock(),OBlock(), TBlock(), IBlock() };
	curBlock = blockGenerator();
	for (int i = 0; i < 5; i++)
	{
		nextBlocks.push(blockGenerator());
	}
	controlTime = 0;
	holdFlag = false;
	gameOver = false;
	fallTime = 0;
	speedLevel = 1;
}

Block Mechanic::blockGenerator()
{
	srand(time(0));
	if (blockL.size() == 0)
	{
		blockL = { LBlock(), JBlock(), ZBlock(), SBlock(),OBlock(), TBlock(), IBlock() };
	}
	int num = rand() % blockL.size();
	Block temp = blockL[num];
	blockL.erase(blockL.begin() + num);
	return temp;
}

bool Mechanic::eventTrigger(double speed, double& flag)
{
	long double runTime = GetTime();
	if ((runTime - flag) >= speed)
	{
		flag = runTime;
		return true;
	}
	else
	{
		return false;
	}

}

void Mechanic::draw()
{
	ClearBackground(GRAY);
	f.draw();
	curBlock.draw();
	s.draw();
}

bool Mechanic::isCollision()
{
	vector<Pos> temp = curBlock.getCurPos();
	for (int i = 0; i < temp.size(); i++)
	{
		int tempy = temp[i].getY() + curBlock.getY();
		int tempx = temp[i].getX() + curBlock.getX();
		if (tempx >= 0 && tempx < 10 && tempy >= 0 && tempy < 20)
		{
			if (f.field[tempy][tempx] != 0)
			{
				return true;
			}
		}
	}
	return false;
}

void Mechanic::hold()
{
	if (holdBlock.getType() == 0)
	{
		holdBlock = curBlock;
		holdBlock.setX(3);
		holdBlock.setY(0);
		curBlock = nextBlocks.front();
		nextBlocks.pop();
		nextBlocks.push(blockGenerator());
	}
	else
	{
		Block temp = curBlock;
		temp.setX(3);
		temp.setY(0);
		curBlock = holdBlock;
		holdBlock = temp;
	}
	holdFlag = true;
}

void Mechanic::restart()
{
	f.clear();
	f.fieldInit();
	blockL.clear();
	blockL = { LBlock(), JBlock(), ZBlock(), SBlock(),OBlock(), TBlock(), IBlock() };
	curBlock = blockGenerator();
	while (nextBlocks.size() > 0)
	{
		nextBlocks.pop();
	}
	for (int i = 0; i < 4; i++)
	{
		nextBlocks.push(blockGenerator());
	}
	controlTime = 0;
	gameOver = false;
	fallTime = 0;
	long temp = 0 - s.getScore();
	s.setScore(temp,-1);
	int temp2 = 0-s.getLineClear();
	s.setLineClear(temp2);
	temp2 = 0 - s.getPieceDrop();
	s.setPieceDrop(temp2);
	speedLevel = 1;
}