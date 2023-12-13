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
		if (IsKeyDown(KEY_LEFT))
		{
			if (IsKeyPressed(KEY_LEFT))
			{
				moveLeft();
				eventTrigger(0.075, controlTime);
			}
			else if (eventTrigger(0.075, controlTime))
				moveLeft();
		}
		else if (IsKeyDown(KEY_RIGHT))
		{
			if (IsKeyPressed(KEY_RIGHT))
			{
				moveRight();
				eventTrigger(0.075, controlTime);
			}
			else if (eventTrigger(0.075, controlTime))
			{
				moveRight();
			}
		}
		if (IsKeyDown(KEY_DOWN))
		{
			if (eventTrigger(0.05, fallTime))
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