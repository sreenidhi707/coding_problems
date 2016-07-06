// Reverse_words_in_string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include<stack>
using namespace std;

string reverse_words_in_string(string s)
{
	string reversed = "";

	if (s.size() == 0)
	{
		return reversed;
	}

	int pos = 0;
	
	//Remove spaces in front
	while (s[pos] == ' ')
	{
		pos++;
	}

	stack<string> word_list;

	for (; pos < s.size(); pos ++)
	{
		string word;
		while (s[pos] != ' ' && pos < s.size())
		{
			word += s[pos];
			pos++;
		}

		if (word.size() > 0)
		{
			word_list.push(word);
		}
	}

	while (word_list.size() > 0)
	{
		reversed += word_list.top() + ' ';
		word_list.pop();
	}

	return reversed;
}

int main()
{
	string s;
	
	while (s != "quit")
	{
		cout << "Enter the string of your choice:";
		getline(std::cin, s);

		string rev = reverse_words_in_string(s);

		cout << "Reversed string is:" << rev << endl;
	}
	


    return 0;
}

