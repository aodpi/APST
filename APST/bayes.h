#pragma once
#include "wordprocessing.h"
#include "probitem.h"
#include <math.h>
#include <map>
using namespace std;
class bayes
{
private:
	bool contains(string x,int part);
public:
	double getprobforword(string word, int part);
	bayes(wordprocessing::_parts Parts);
	int aparitionsinpart(string str, wordprocessing::del part);
	vector<probitem*> probabilities;
	typedef vector<probitem>* prlist;
	typedef map<int, prlist> pparts;
	pparts ProbByParts;
	double getadoubleprob(string w, int part, wordprocessing::_parts parts);
	double gettextratio(int part, wordprocessing::_parts parts);
	double getaprob(string w,int part,wordprocessing::_parts parts);
	double getprobofword(string w,wordprocessing::_parts parts,bool squared);
	void calcprobparts(wordprocessing::_parts Parts);
};