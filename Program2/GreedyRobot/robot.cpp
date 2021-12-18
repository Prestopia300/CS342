// Purpose: to find all the shortest paths from a start xy coordinate to an end xy coordinate

#include "robot.h"
#include "point.h"
#include <iostream>
#include <cstdlib>


Robot::Robot(Point point, int max_steps) // converts NSEW directions into a positive 2 dimentional measurement for horizontal/vertical
{
	max_steps_ = max_steps;
	int maxDistanceX = point.getTreasureX() - point.getCurrentX();
	int maxDistanceY = point.getTreasureY() - point.getCurrentY();

	max_v_ = abs(maxDistanceY);
	max_h_ = abs(maxDistanceX);

	if (maxDistanceY > 0)
	{
		direction_v_ = 'N';
	}
	else
	{
		direction_v_ = 'S';
	}

	if (maxDistanceX > 0)
	{
		direction_h_ = 'E';
	}
	else
	{
		direction_h_ = 'W';
	}
}


int Robot::GetMaxSteps()
{
	return max_steps_;
}

int Robot::GetMaxH()
{
	return max_h_;
}

int Robot::GetMaxV()
{
	return max_v_;
}

char Robot::GetDirectionH()
{
	return direction_h_;
}

char Robot::GetDirectionV()
{
	return direction_v_;
}

int Robot::recursion(int max_v, int max_h, string s, int max_steps, int consecutiveSteps, bool wasLastH, char direction_v, char direction_h)
{

	if (max_v < 0 || max_h < 0 || consecutiveSteps > max_steps) // stop path if past max_v/h or if path passes max_steps
	{

		return 0;
	}
	if (max_v == 0 && max_h == 0) // at target, success
	{

		cout << s << endl;
		return 1;
	}

	int sum = 0;
	if (wasLastH) { // last was h
		sum += recursion(max_v - 1, max_h, s + direction_v, max_steps, 1, false, direction_v, direction_h); //v
		sum += recursion(max_v, max_h - 1, s + direction_h, max_steps, consecutiveSteps + 1, true, direction_v, direction_h); //h
	}
	else // last was v
	{
		sum += recursion(max_v - 1, max_h, s + direction_v, max_steps, consecutiveSteps + 1, false, direction_v, direction_h); //v 
		sum += recursion(max_v, max_h - 1, s + direction_h, max_steps, 1, true, direction_v, direction_h); //h
	}

	return sum;
}
