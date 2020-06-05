#include "stdafx.h"
#include "row.h"


row::row(string s1, string s3, Time t1, string file)
{
	this->s1 = s1;
	this->s3 = s3;
	this->t1 = t1;
	this->file = file;
}

row::row()
{
}


row::~row()
{
}
