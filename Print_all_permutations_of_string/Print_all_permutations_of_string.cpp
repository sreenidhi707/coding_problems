// Print_all_permutations_of_string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void walker(string current_string, vector<char> char_list, int max_size);
int total_permutations;

int main()
{
	string given_string;
	cout << "Enter your string:";
	getline(cin, given_string);

	vector<char> char_list;
	for (size_t i = 0; i < given_string.size(); i++)
	{
		char_list.push_back(given_string[i]);
	}

	total_permutations = 0;
	cout << "All possible permutations of \"" << given_string << "\" are:" << endl;

	walker("", char_list, given_string.size());
	cout << "There are totally " << total_permutations << " permutations" << endl;

	return 0;
}

void walker(string current_string, vector<char> char_list, int max_size)
{
	if (current_string.size() == max_size)
	{
		cout << current_string << endl;
		total_permutations++;
		return;
	}

	for (size_t i = 0; i < char_list.size(); i++)
	{
		vector<char> temp = char_list;
		char current_char = temp.at(i);

		temp.erase(temp.begin() + i);
		walker(current_string + current_char, temp, max_size);
	}
	return;
}

