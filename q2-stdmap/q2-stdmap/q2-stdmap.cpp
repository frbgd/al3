// q2-stdmap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int,char> c;
	c = {{1,'a'},{2,'b'},{3,'c'},{4,'c'},{5,'e'}};

	cout << c.size() << endl;
	cout << c.max_size() << endl;
	if (c.empty())
		cout << "empty" << endl;
	else
		cout << "not empty" << endl;
	cout << c.count(3) << endl;
	auto iter = c.find(3);

	map<int, char> c1 = { {3,'c'},{2,'b'} ,{1,'a'} };
	c.swap(c1);

	for (auto& elem : c)
		cout << elem.first << "\t" << elem.second << endl;
	cout << endl;

	for (auto pos = c1.begin(); pos != c1.end(); ++pos)
		cout << pos->first << "\t" << pos->second << endl;
	cout << endl;

	c.insert( { 15, 'o' });
	auto iter1 = c.insert(c.find(15), { 6,'f' });
	c.emplace(' ', 0);

	c.erase(4);
	c.erase(c.find(2));
	c.clear();


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
