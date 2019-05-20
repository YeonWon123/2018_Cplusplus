#include "pch.h"
#include "Data.h"


Data::Data()
{
}


Data::~Data()
{
}


int Data::GetScore()
{
	return score;
}


string Data::GetName()
{
	return name;
}

void Data::SetName(string strName)
{
	name = strName;
}

void Data::SetScore(int nScore)
{
	score = nScore;
}
