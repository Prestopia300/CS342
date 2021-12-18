// Purpose: keeps track of current xy coordinates, as well as the target xy coordinates

#include "point.h"
#include <iostream>

Point::Point()
{
}

Point::Point(int current_x, int current_y, int treasure_x, int treasure_y)
{
	current_x_ = current_x;
	current_y_ = current_y;
	treasure_x_ = treasure_x;
	treasure_y_ = treasure_y;
}

int Point::getCurrentX()
{
	return current_x_;
}
int Point::getCurrentY()
{
	return current_y_;
}

int Point::getTreasureX()
{
	return treasure_x_;
}
int Point::getTreasureY()
{
	return treasure_y_;
}