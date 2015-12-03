#pragma once
#include <string>
#include <unordered_map>
#include <list>
#include "wordclass.h"
#include <iostream>
#include <regex>
#include <vector>
#include <map>
using namespace std;

class wordprocessing
{
private:
	bool contains(string x);
	void increment(string x);
	void dividebyten();
	vector<string>* GetRange(int s, int f);
public:
	typedef vector<string>* del;
	typedef map<int, del> _parts;
	_parts Parts;
	vector<wordclass> words;
	vector<string> allwords;
	wordprocessing(string inputstr);
	void PopulateWords(string inputstr);
	string tolow(string in);
};