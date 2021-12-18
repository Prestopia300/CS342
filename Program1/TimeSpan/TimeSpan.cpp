#include "TimeSpan.h"
#include<cmath>
#include<iostream>

using namespace std;


// Constructors (4)

TimeSpan::TimeSpan()
{
    hours_ = 0;
    minutes_ = 0;
    seconds_ = 0;
}

TimeSpan::TimeSpan(double secs)
{
    double hrs = 0;
    double mins = 0;

    FixTime(hrs, mins, secs);

    hours_ = round(hrs);
    minutes_ = round(mins);
    seconds_ = round(secs);
}

TimeSpan::TimeSpan(double mins, double secs)
{
    double hrs = 0;
    
    FixTime(hrs, mins, secs);

    hours_ = round(hrs);
    minutes_ = round(mins);
    seconds_ = round(secs);

}

TimeSpan::TimeSpan(double hrs, double mins, double secs)
{
    FixTime(hrs, mins, secs);

    hours_ = round(hrs);
    minutes_ = round(mins);
    seconds_ = round(secs);
}


// fix time and setTime for input

void TimeSpan::FixTime(double& hrs, double& mins, double& secs)
{
    // Handles decimals
    
    double hrsDecimal = fmod(hrs, 1);
    double minsDecimal = fmod(mins, 1);
    
    if (int(hrs) != hrs) // if hrs has decimal
    {
        hrs -= hrsDecimal;
        mins += (hrsDecimal * 60); // hrs whole number, decimal added to mins
    }
    
    if (int(mins) != mins) // if mins has decimal
    {
        mins -= minsDecimal;
        secs += (minsDecimal * 60); // mins whole number, decimal added to secs
    }
 

    // -60 to 60 constraints

    while (secs >= 60 || mins >= 60 || secs <= -60 || mins <= -60)
    {
        if (secs >= 60)
        {
            secs -= 60;
            mins += 1;
        }
        if (mins >= 60)
        {
            mins -= 60;
            hrs += 1;
        }
        if (secs <= -60)
        {
            secs += 60;
            mins -= 1;
        }
        if (mins <= -60)
        {
            mins += 60;
            hrs -= 1;
        }
    }

    // the "or 0" parts could go either way, or could they...
    
    if (hrs < 0 && mins > 0) // (-, +, -/+)
    {
        if (secs > 0) // Ex: (-2, 30, 30) -> (-1, -29, -30)  -  (-, +, >+)
        {
            hrs += 1;
            mins -= 59;
            secs -= 60;
        }
        else  // Ex: (-2, 30, -30(or 0)) -> (-1, -30, -30(or 0))  -  (-, +, -(or 0))
        {
            hrs += 1;
            mins -= 60;
        }
            
    }
    if (mins < 0 && secs >= 0) // (-/+, -, +(or 0))
    {
        if (hrs > 0) // Ex: (2, -30, 30) -> (1, 30, 30)  -  (>+, -, +)
        {
            hrs -= 1;
            mins += 60;
        }
        else // Ex: (-2, -30, 30) -> (-2, -29, -30)  -  (-(or 0), -, +)
        {
            mins += 1;
            secs -= 60;
        }
    }
    if (hrs > 0 && secs < 0) // (+,-/+,-) 
    {
        if (mins > 0) // Ex: (2, 30, -30) -> (2, 29, 30)
        {
            mins -= 1;
            secs += 60;
        }
        else // Ex: (2, -30, -30) -> (1, 29, 30)
        {
            hrs -= 1;
            mins += 59;
            secs += 60;
        }
    }

}

bool TimeSpan::SetTime(int hrs, int mins, int secs) // TODO: find out why bool?
{
    
    double hrsDouble = hrs; // I need to do this because I need to use FixTime()
    double minsDouble = mins;
    double secsDouble = secs;

    FixTime(hrsDouble, minsDouble, secsDouble); // must take in double
    
    hours_ = round(hrsDouble);
    minutes_ = round(minsDouble);
    seconds_ = round(secsDouble);
    
    return true;
}


// Getters

int TimeSpan::GetHours() const {
    return hours_;
}
int TimeSpan::GetMinutes() const
{
    return minutes_;
}
int TimeSpan::GetSeconds() const
{
    return seconds_;
}


// Operator time!!!

TimeSpan TimeSpan::operator+(const TimeSpan& obj) // add
{

    TimeSpan timespan;
    timespan.hours_ = hours_ + obj.hours_;
    timespan.minutes_ = minutes_ + obj.minutes_;
    timespan.seconds_ = seconds_ + obj.seconds_;

    //FixTime()
    double hrs = timespan.hours_;
    double mins = timespan.minutes_;
    double secs = timespan.seconds_;

    FixTime(hrs, mins, secs);

    timespan.hours_ = hrs;
    timespan.minutes_ = mins;
    timespan.seconds_ = secs;

    
    return timespan;
}

TimeSpan TimeSpan::operator-(const TimeSpan& obj) // subtract
{
    TimeSpan timespan;
    timespan.hours_ = hours_ - obj.hours_;
    timespan.minutes_ = minutes_ - obj.minutes_;
    timespan.seconds_ = seconds_ - obj.seconds_;

    //FixTime()
    double hrs = timespan.hours_;
    double mins = timespan.minutes_;
    double secs = timespan.seconds_;

    FixTime(hrs, mins, secs);

    timespan.hours_ = hrs;
    timespan.minutes_ = mins;
    timespan.seconds_ = secs;


    return timespan;
}

TimeSpan TimeSpan::operator- ()
{
    hours_ = -hours_;
    minutes_ = -minutes_;
    seconds_ = -seconds_;
    return TimeSpan(hours_, minutes_, seconds_);
}

bool TimeSpan::operator==(const TimeSpan& obj) // why does == set equals to obj this way? Why bool?
{
    if ((hours_ == obj.hours_) && (minutes_ == obj.minutes_) && (seconds_ == obj.seconds_))
    {
        return true;
    }
    else
        return false;
    //return hours == obj.hours && minutes_ == obj.minutes_ && obj.seconds_;
}

bool TimeSpan::operator!=(const TimeSpan& obj) // why does != set not equals to obj like above? Why bool?
{
    if (!(hours_ == obj.hours_) || !(minutes_ == obj.minutes_) || !(seconds_ == obj.seconds_))
    {
       return true;
    }
    else 
        return false;
    //return !(hours_ == obj.hours_ && minutes_ == obj.minutes_ && obj.seconds_);
}

TimeSpan TimeSpan::operator +=(const TimeSpan& obj) { 
    hours_ = hours_ + obj.hours_;
    minutes_ = minutes_ + obj.minutes_;
    seconds_ = seconds_ + obj.seconds_;


    //FixTime()
    double hrs = hours_;
    double mins = minutes_;
    double secs = seconds_;

    FixTime(hrs, mins, secs);

    hours_ = hrs;
    minutes_ = mins;
    seconds_ = secs;
    return TimeSpan(hours_, minutes_, seconds_);
}

TimeSpan TimeSpan::operator -=(const TimeSpan& obj) {
    hours_ = hours_ - obj.hours_;
    minutes_ = minutes_ - obj.minutes_;
    seconds_ = seconds_ - obj.seconds_;

    
    //FixTime()
    double hrs = hours_;
    double mins = minutes_;
    double secs = seconds_;

    FixTime(hrs, mins, secs);

    hours_ = hrs;
    minutes_ = mins;
    seconds_ = secs;
    return TimeSpan(hours_, minutes_, seconds_);
}


// << >> Operators

ostream& operator<<(ostream& output, const TimeSpan& obj)
{
    output << "Hours: " << obj.GetHours() << ", Minutes: " << obj.GetMinutes() << ", Seconds: " << obj.GetSeconds();
    return output;
}

istream& operator>>(istream& input, TimeSpan& obj) // Why does this work / not work? Supposed to take in input to create a time obj
{
    int hrs, mins, secs;
    input >> hrs >> mins >> secs;
    obj.SetTime(hrs, mins, secs);
    return input;
}