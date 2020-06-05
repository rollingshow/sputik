#pragma once
#include "time.h"
#include <string>
using namespace std;

class row
{
public:
	string s1, s3;
	Time t1;
	string file;
	row(string s1, string s3, Time t1, string file);
	row();
	~row();
};

