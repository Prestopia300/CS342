#pragma once
#include <iostream>
using namespace std;

class TimeSpan
{

public:
	TimeSpan(double, double, double);
	TimeSpan(double, double);
	TimeSpan(double);
	TimeSpan();
	
	int GetHours() const;
	int GetMinutes() const;
	int GetSeconds() const;

	bool SetTime(int, int, int); // Only used during obj input
	void FixTime(double& hrs, double& mins, double& secs);

	TimeSpan operator+(const TimeSpan&);
	TimeSpan operator-(const TimeSpan&);
	TimeSpan operator-();
	bool operator==(const TimeSpan&);
	bool operator!=(const TimeSpan&);
	TimeSpan operator+=(const TimeSpan&);
	TimeSpan operator-=(const TimeSpan&);
	
    friend ostream& operator<<(ostream& out_stream, const TimeSpan& time_span);
	friend istream& operator>>(istream& in_stream, TimeSpan& time_span);

private:
	int hours_;
	int minutes_;
	int seconds_;
};