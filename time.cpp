#include "stdafx.h"
#include "time.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

Time::Time()
{
	hour = 0;
	min = 0;
	sec = 0.0;
}


Time::Time(float sec)
{
	int hour = ((int)sec) / 3600;
	int min = (((int)abs(sec)) / 60) % 60;
	this->min = min;
	this->hour = hour;
	this->sec = abs(sec) - min * 60 - abs(hour) * 3600;
}


Time::Time(int hour, int min, float sec)
{
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}


Time::Time(const Time& t)
{
	this->hour = t.Hours();
	this->min = t.Minutes();
	this->sec = t.Seconds();
}


Time Time::operator + (Time& other) const
{
	auto t1 = (float)*this;
	auto t2 = (float)other;
	return  *(new Time(t1 + t2));
}


Time::operator int() const
{
	return this->hour * 3600 + this->min * 60 + this->sec;
}

Time::operator float() const
{
	return this->hour * 3600 + this->min * 60 + this->sec;
}


Time Time::operator - (Time& other) const
{
	float hh = 86400;
	float del = abs((float)*this) - ((float)other);
	if (del < 0)
	{
		del = hh + del;
	}
	return *(new Time(del));
}

int Time::Hours() const
{
	return this->hour;
}

int Time::Minutes() const
{
	return this->min;
}

float Time::Seconds() const
{
	return this->sec;
}

istream& operator>>(istream & in, Time& t)
{
	int hour, min;
	float sec;
	char ch1, ch2;
	in >> t.hour >> ch1 >> t.min >> ch2 >> t.sec;
	return in;
}

ostream& operator<<(ostream & out, const Time & t)
{
	out << setw(2) << setfill('0') << t.Hours() << ":" << setw(2) << setfill('0') << t.Minutes() << ":" << setw(2) << setfill('0') << t.Seconds() << endl;
	return out;
}


