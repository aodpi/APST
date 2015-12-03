#include "bayes.h"

bool bayes::contains(string x,int part)
{
	for (size_t i = 0; i < ProbByParts.at(part)->size(); i++)
	{
		if (x==ProbByParts.at(part)->at(i).word)
		{
			return true;
		}
	}
	return false;
}

double bayes::getprobforword(string word, int part)
{
	double result = 0;
	for (size_t i = 0; i < ProbByParts.at(part)->size(); i++)
	{
		if (word==ProbByParts.at(part)->at(i).word)
		{
			return ProbByParts.at(part)->at(i).probability;
		}
	}
	return 0.0;
}

bayes::bayes(wordprocessing::_parts Parts)
{
	calcprobparts(Parts);
}

int bayes::aparitionsinpart(string str, wordprocessing::del part)
{
	int result = 0;
	for (size_t i = 0; i < part->size(); i++)
	{
		if (str == part->at(i))
		{
			result += 1;
		}
	}
	return result;
}

double bayes::getadoubleprob(string w, int part, wordprocessing::_parts parts)
{
	double result = 0;
	if (contains(w, part))
	{
		result = gettextratio(part, parts)*(pow(getprobforword(w, part), 2) / getprobofword(w, parts, true));
		return result;
	}
	return 0.0;
}

double bayes::gettextratio(int part, wordprocessing::_parts parts)
{
	int sum = 0;
	double result = 0;
	for (size_t i = 1; i < parts.size()+1; i++)
	{
		sum += parts.at(i)->size();
	}
	result = (double)parts.at(part)->size() / sum;
	return result;
}

double bayes::getaprob(string w, int part, wordprocessing::_parts parts)
{
	double result = 0;
	if (contains(w,part))
	{
		result = gettextratio(part, parts)*(getprobforword(w, part) / getprobofword(w, parts, false));
		return result;
	}
	return 0.0;
}

double bayes::getprobofword(string w, wordprocessing::_parts parts, bool squared)
{
	double result = 0.0;
	for (size_t i = 1; i < ProbByParts.size()+1; i++)
	{
		for (size_t x = 0; x < ProbByParts.at(i)->size(); x++)
		{
			if (ProbByParts.at(i)->at(x).word==w)
			{
				switch (squared)
				{
				case true:
					result+=gettextratio(i, parts)*pow(ProbByParts.at(i)->at(x).probability, 2);
					break;
				case false:
					result += gettextratio(i, parts)*ProbByParts.at(i)->at(x).probability;
					break;
				default:
					break;
				}
			}
		}
	}
	return result;
}

void bayes::calcprobparts(wordprocessing::_parts Parts)
{
	int count = 1;
	for (size_t i = 1; i < Parts.size() + 1; i++)
	{
		vector<probitem>* tmp = new vector<probitem>;
		for (size_t x = 0; x < Parts.at(i)->size(); x++)
		{
			tmp->push_back(probitem(Parts.at(i)->at(x), (double)aparitionsinpart(Parts.at(i)->at(x), Parts.at(i)) / (double)Parts.at(i)->size()));
			probabilities.push_back(new probitem(Parts.at(i)->at(x), (double)aparitionsinpart(Parts.at(i)->at(x), Parts.at(i)) / (double)Parts.at(i)->size()));
		}
		ProbByParts.insert(pparts::value_type(count,tmp));
		count++;
	}
}

bayes::~bayes()
{
}
