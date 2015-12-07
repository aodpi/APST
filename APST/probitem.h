#pragma once
#include <string>
#include <math.h>
using namespace std;
class probitem
{
public:

	string word;
	double probability;
	probitem(string w,double p)
	{
		word = w;
		probability = p;
	}
};

