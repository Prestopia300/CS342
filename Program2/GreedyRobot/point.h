// Purpose: keeps track of current xy coordinates, as well as the target xy coordinates
#pragma once
class Point
{

	// Maybe it keeps track of start, end and current points? Organizes things better, and only one point parameter for recursive function.
public:
	Point();
	Point(int current_x, int current_y, int treasure_x, int treasure_y);

	int getCurrentX();
	int getCurrentY();
	int getTreasureX();
	int getTreasureY();

private:
	//int startX_, startY_;
	int treasure_x_, treasure_y_;
	int current_x_, current_y_;
};



