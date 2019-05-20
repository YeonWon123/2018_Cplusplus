#pragma once
#include <string>
#include <iostream>
using namespace std;

class Data
{
public:
	Data();
	~Data();

private:
	int score;
	string name;

public:
	int GetScore();
	string GetName();
	void SetName(string strName);
	void SetScore(int nScore);
};

