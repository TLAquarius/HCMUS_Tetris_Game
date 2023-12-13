#include "Mechanic.h"

void Mechanic::control()
{
	if (!gameOver)
	{
		if (IsKeyPressed(KEY_UP)||IsKeyPressed(KEY_X))
		{
			rotate();
		}
		else if (IsKeyPressed(KEY_Z))
		{
			counterRotate();
		}
		else if (IsKeyDown(KEY_LEFT))
		{
			if (IsKeyPressed(KEY_RIGHT))
			{
				moveLeft();
				if (curBlock.isOutOfBound() == 1)
					moveRight();
			}
			else if (eventTrigger(0.075, controlTime))
			{
				moveLeft();
				if (curBlock.isOutOfBound() == 1)
					moveRight();
			}
		}
		else if (IsKeyDown(KEY_RIGHT))
		{
			if (IsKeyPressed(KEY_LEFT))
			{
				moveRight();

			}
			else if (eventTrigger(0.075, controlTime))
			{
				moveRight();
			}
		}
		if (IsKeyDown(KEY_DOWN))
		{
			if (eventTrigger(0.05, controlTime))
				moveDown();
		}
		if (IsKeyPressed(KEY_SPACE))
		{
			drop();
		}
		if (IsKeyPressed(KEY_C))
		{
			if (!holdFlag)
				hold();
		}
	}
	else
	{
		if (IsKeyPressed(KEY_R))
		{
			restart();
		}
	}
}