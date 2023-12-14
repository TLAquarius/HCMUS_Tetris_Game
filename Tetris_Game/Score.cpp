#include "Score.hpp"

Score::Score()
{
	lineClear = 0;
	score = 0;
	pieceDrop = 0;
	ifstream sFile("high_score.txt");
	if (sFile.is_open())
	{
		sFile >> highScore;
	}
	else
		highScore = 0;
}

int Score::getLineClear()
{
	return lineClear;
}
int Score::getPieceDrop()
{
	return pieceDrop;
}
long Score::getScore()
{
	return score;
}

void Score::setLineClear(int num)
{
	lineClear += num;
}
void Score::setPieceDrop(int num)
{
	pieceDrop += num;
}
void Score::setScore(long num, int speedLevel)
{
	if (num == 1)
	{
		score += 100 * speedLevel;
	}
	else if (num == 2)
	{
		score += 300 * speedLevel;
	}
	else if (num == 3)
	{
		score += 500 * speedLevel;
	}
	else if (num == 4)
	{
		score += 800 * speedLevel;
	}
	else if (num == 0)
		score += 10;
	else
		score += num;
}

long Score::getHighScore()
{
	return highScore;
}
void Score::setHighScore(long score)
{
	highScore = score;
}

void Score::saveHighScore()
{
	ofstream sFile("high_score.txt");
	if (sFile.is_open())
	{
		sFile << highScore;
	}
}

void Score::draw()
{
	DrawText(TextFormat("Score: %08i", score), scoreOffsetX, scoreOffsetY, 20, RED);
	DrawText(TextFormat("HiScore: %08i", highScore), scoreOffsetX, scoreOffsetY+20, 20, GREEN);
	DrawText(TextFormat("Num of Pieces: %02i", pieceDrop), scoreOffsetX, scoreOffsetY+80, 40, BLUE);
	DrawText(TextFormat("Lines cleared: %08i", lineClear), scoreOffsetX, scoreOffsetY+120, 20, BLACK);
}
