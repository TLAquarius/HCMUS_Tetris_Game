#pragma once
#include "Score.hpp"
#include "Colors.hpp"
#include "GUI_Const.hpp"

class Field
{
private:
	int rowNum;
	int colNum;
	vector<Color> cList;
public:
	int** field;
	bool isLineComplete(int row);
	Field();
	~Field();
	void clear();
	void fieldInit();
	void moveLine(int curRow, int num);
	int clearLine();
	void draw();
};