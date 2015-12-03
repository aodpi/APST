// APST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "wordprocessing.h"
#include "bayes.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <map>
using namespace std;

int main()
{
	char x = 'a';
	char xm = 'A';
	/*for (size_t i = 0; i < 26; i++)
	{
		cout << x << "=" << (int)x << "\t" << xm << "=" << (int)xm << endl;
		x += 1;
		xm += 1;
	}*/
	cout << (char)('a' + ('Z' - 'z')) << endl;
	string filec;
	string line;
	string filename;
	cout << "Dati fisierul:";
	cin >> filename;
	system("cls");
	ifstream file(filename);
	if (file.is_open())
	{
		while (getline(file,line))
		{
			filec.append(line);
		}
		file.close();
	}
	wordprocessing xx = wordprocessing(filec);
	bayes bs = bayes(xx.Parts);
	string input;
begin:
	system("cls");
	cout << "dati cuvintul:";
	cin >> input;
	cout << "    Probailitate" << endl;
	cout << "Text:\tProbabilitate:" << endl;
	for (size_t i = 1; i < bs.ProbByParts.size()+1; i++)
	{
		cout << i << "\t" << bs.getprobforword(input, i) << endl;
	}
	cout << endl << "Aposterioara"<<endl;
	cout << "Text:\tProbabilitate:" << endl;
	for (size_t i = 1; i < bs.ProbByParts.size()+1; i++)
	{
		cout << i << "\t" << bs.getaprob(input, i, xx.Parts) << endl;
	}

	cout << endl << "Aparitia dubla"<<endl;
	cout << "Text:\tProbabilitate:" << endl;
	for (size_t i = 1; i < bs.ProbByParts.size()+1; i++)
	{
		cout << i << "\t" << bs.getadoubleprob(input, i, xx.Parts) << endl;
	}
	cout << "Alt cuvint ? (y/n)";
	cin >> x;
	switch (x)
	{
	case 'y':
		goto begin;
		break;
	case 'n':
		exit(1);
		break;
	default:
		exit(1);
		break;
	}
    return 0;
}

