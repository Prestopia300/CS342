// GreedyRobot342.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Purpose: creates point and robot arguments and outputs paths and number of paths
#include "point.h"
#include "robot.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
	int x1 = atoi(argv[1]);
	int y1 = atoi(argv[2]);
	int x2 = atoi(argv[3]);
	int y2 = atoi(argv[4]);
	int max_steps = atoi(argv[5]);

	Point point(x1, y1, x2, y2);
	Robot rob(point, max_steps);

	string path = "";


	cout << "Number of Paths: " << rob.recursion(rob.GetMaxV(), rob.GetMaxH(), path, rob.GetMaxSteps(), 0,
		false, rob.GetDirectionV(), rob.GetDirectionH()) << endl;


	system("pause");
	return 0;
}