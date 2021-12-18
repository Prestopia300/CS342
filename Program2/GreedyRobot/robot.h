#pragma once
#include <iostream>
#include "Point.h"
using namespace std;

class Robot : public Point
{
public:
	Robot(Point point, int max_steps);

	int GetMaxSteps();
	int GetMaxH();
	int GetMaxV();
	char GetDirectionH();
	char GetDirectionV();

	int recursion(int max_v, int max_h, string path, int maxSteps, int consecutiveSteps, bool wasLastH, char direction_v, char direction_h);

private:
	int current_x_, current_y_, target_x_, target_y_;
	int max_steps_;

	char direction_v_;
	char direction_h_;

	int max_v_;
	int max_h_;
};

