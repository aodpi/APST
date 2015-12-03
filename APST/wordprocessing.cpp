#include "wordprocessing.h"

wordprocessing::wordprocessing(string inputstr)
{
	PopulateWords(inputstr);
	dividebyten();
}


void wordprocessing::PopulateWords(string inputstr)
{
	inputstr = tolow(inputstr);
	match_results<string::const_iterator> sm;
	regex rgx("\\b\\w+");
	for (sregex_iterator it(inputstr.begin(), inputstr.end(), rgx), it_end; it != it_end; ++it)
	{
		allwords.push_back((*it)[0]);
		if (!contains((*it)[0]))
		{
			words.push_back(wordclass((*it)[0], 1));
		}
		else
		{
			increment((*it)[0]);
		}
	}
}

void wordprocessing::increment(string x)
{
	for (size_t i = 0; i < words.size(); i++)
	{
		if (x==words[i].Word)
		{
			words.at(i).Count = words.at(i).Count + 1;
		}
	}
}

void wordprocessing::dividebyten()
{
	int lastindex = allwords.size(), startindex = 0, count = 0, total = allwords.size();
	while (true)
	{
		if (lastindex%10==0)
		{
			count = lastindex / 10;
			break;
		}
		else
		{
			lastindex -= 1;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (i==9)
		{
			Parts.insert(_parts::value_type(i + 1, GetRange(startindex, total - startindex)));
		}
		else
		{
			Parts.insert(_parts::value_type(i + 1, GetRange(startindex, count)));
			startindex += count;
		}
	}
}

vector<string>* wordprocessing::GetRange(int s, int f)
{
	vector<string> *result = new vector<string>;
	int x = 0;
	while (x<f)
	{
		result->push_back(allwords[s]);
		s++;
		x++;
	}
	return result;
}

bool wordprocessing::contains(string x)
{
	for (size_t i = 0; i < words.size(); i++)
	{
		if (x==words[i].Word)
		{
			return true;
		}
	}
	return false;
}

string wordprocessing::tolow(string in)
{
	for (size_t i = 0; i < in.length(); i++)
	{
		if (in[i] <= 'Z' && in[i] >= 'A')
		{
			in[i] = in[i] - ('Z' - 'z');
		}
	}
	return in;
}