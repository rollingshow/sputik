#pragma once
#include <iostream>


using namespace std;

class Time
{
	//	int hour, min;
	//	float sec;
public:
	int hour, min;
	float sec;
	Time();
	Time(float sec);
	Time(int hour, int min, float sec);
	Time(const Time& t);


	Time operator + (Time& other) const;
	Time operator - (Time& other) const;

	operator int() const;
	operator float() const;

	int Hours() const;
	int Minutes() const;
	float Seconds() const;


};

istream& operator>>(istream & in, Time & t);
ostream& operator<<(ostream & out, const Time & t);

