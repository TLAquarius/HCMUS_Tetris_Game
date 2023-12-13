#include "PlayField.hpp"

Field::Field()
{
	colNum = 10;
	rowNum = 20;
	fieldInit();
	cList = colorList;
}

Field::~Field()
{
	for (int i = 0; i < rowNum; i++)
	{
		delete[] field[i];
	}
	delete[]field;
}

void Field::fieldInit()
{
	field = new int*[rowNum]();
	for (int i = 0; i < rowNum; i++)
	{
		field[i] = new int[colNum]();
	}
}

void Field::clear()
{
	for (int i = 0; i < rowNum; i++)
	{
		delete[] field[i];
	}
	delete[]field;
}

void Field::draw()
{
	DrawLineEx({ gameOffsetX-10,gameOffsetY }, { (float)gameOffsetX-10,
		((float)gameOffsetY + rowNum*cellSize)}, 12, WHITE);
	DrawLineEx({ ((float)gameOffsetX),((float)gameOffsetY + rowNum * cellSize+10) },
		{ ((float)gameOffsetX + colNum * cellSize),((float)gameOffsetY + rowNum * cellSize+10) }, 12, WHITE);
	DrawLineEx({ (float)gameOffsetX + colNum * cellSize+10,(float)gameOffsetY + rowNum * cellSize },
		{ (float)gameOffsetX + colNum*cellSize+10,(float)gameOffsetY}, 12, WHITE);
	for (int row = 0; row < rowNum; row++)
	{
		for (int col = 0; col < colNum; col++)
		{
			DrawRectangle((col * cellSize + gameOffsetX + 1), (row* cellSize + gameOffsetY + 1),
				cellSize - 2, cellSize - 2, cList[field[row][col]]);
		}
	}
}

bool Field::isLineComplete(int row)
{
	for (int i = 0; i < colNum; i++)
	{
		if (field[row][i] == 0)
			return false;
	}
	for (int i = 0; i < colNum; i++)
	{
		field[row][i] = 0;
	}
	return true;
}

int Field::clearLine()
{
	int num = 0;
	for (int i = rowNum - 1; i >= 0; i--)
	{
		if (isLineComplete(i))
		{
			num++;
		}
		else
		{
			moveLine(i, num);
		}
	}
	return num;
}
void Field::moveLine(int curRow, int num)
{
	field[curRow+num] = field[curRow];
}