// sputnik.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "row.h"
#include "time.h"
#include <sstream>
#include <algorithm>


using namespace std;
bool cmp(row r1, row r2);


int main()
{
	system("dir VOB / B > files.txt");
	vector<string> files;
	ifstream in("files.txt");
	while (!in.eof()) {
		string line;
		getline(in, line);
		files.push_back(line); //закидываем в вектор значения (в конец)
	}
	vector<row>rows;
	for (int i = 0; i < files.size(); i++){
		string file = files[i];
		cout << file << endl;
		ifstream in("VOB/"+file);
		while ((int) in.tellg() !=-1) {
			string s1, s2, s3;
			s1.resize(20);
			s2.resize(20);
			s3.resize(50);
			in.read(&s1[0], 13);//указатель на первый символ 
			in.read(&s2[0], 9);
			in.read(&s3[0], 46);
			stringstream strin;
			Time t1;
			strin << s2;
			strin >> t1;
			row tmp(s1, s3, t1, file);
			rows.push_back(tmp);

		}
		
	}
	sort(rows.begin(), rows.end(), cmp);
	ofstream out("ura.txt");
	for (row tmp : rows) {
		out << tmp.file << " " << tmp.s1 << tmp.t1 << tmp.s3 << endl;
	}

    return 0;
}

bool cmp(row r1, row r2) {
	if ((float)r1.t1 != (float)r2.t1)
		return (float)r1.t1 > (float)r2.t1;
	else
		return r1.file.compare(r2.file)==-1;
}