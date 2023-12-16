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
	level = 1;
	BGM = LoadMusicStream("sounds\\BGM.mp3");
	clearSound = LoadSound("sounds\\ClearSound.wav");
	moveSound = LoadSound("sounds\\MoveSound.mp3");
}

Mechanic::~Mechanic()
{
	UnloadSound(clearSound);
	UnloadSound(moveSound);
	CloseAudioDevice();
}

bool Mechanic::logic()
{
	if (!gameOver)
	{
		
		if (eventTrigger(fallSpeed(), fallTime))
		{
			moveDown();
		}
		control();
		draw();
	}
	while (gameOver) {
		long a = s.getScore();
		menu.GameOverMenu(a);
		if (IsKeyPressed(KEY_R))
		{
			restart();
			return false;
		}
		else if (IsKeyPressed(KEY_M))
		{
			restart();
			return true;
		}
	}
	return false;
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

void Mechanic::updateShadow()
{
	vector<Pos> temp = curBlock.getCurPos();
	int  i = 1;
	int tempY = curBlock.getY();
	while (true)
	{
		curBlock.move(1, 0);
		if (curBlock.isOutOfBound() == 4 || isCollision())
		{
			moveUp();
			curBlock.setSY(curBlock.getY());
			break;
		}
	}
	curBlock.setY(tempY);
}

void Mechanic::draw()
{
	ClearBackground(GRAY);
	f.draw();
	//goi ham ve next voi hold block
	updateShadow();
	curBlock.drawShadow();
	curBlock.draw();
	nextBlocks.front().drawNextBlock();//cai nay ve mot cai next
	holdBlock.drawHoldBlock();
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

void Mechanic::restart()
{
	StopMusicStream(BGM);
	PlayMusicStream(BGM);
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
	s.saveHighScore();
	controlTime = 0;
	fallTime = 0;

	gameOver = false;

	long temp = 0 - s.getScore();
	s.setScore(temp,-1);

	int temp2 = 0-s.getLineClear();
	s.setLineClear(temp2);
	
	temp2 = 0 - s.getPieceDrop();
	s.setPieceDrop(temp2);
	level = 1;
}

double Mechanic::fallSpeed()
{
	return (double)(1 / level);
}