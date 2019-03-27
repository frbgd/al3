// q3-stdset.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	set <string> S; // инициализация set

	S.insert("January");
	S.insert("February");
	S.insert("March");
	S.insert("April");
	cout << S.size() << '\n'; // будет выведено 4
	cout << S.max_size() << '\n';
	cout << *(S.begin()) << '\n'; // April
	cout << *(--S.end()) << '\n'; // NULL
	cout << *(S.rbegin()) << '\n'; // March
	cout << *(--S.rend()) << '\n'; // January
	cout << S.count("January") << '\n'; // 1
	cout << *S.lower_bound("January") << '\n'; // January
	cout << *S.upper_bound("January") << '\n'; // March
	cout << *(S.equal_range("January")).first << '\n'; // January
	cout << *(S.equal_range("January")).second << '\n'; // March
	cout << *S.find("January") << '\n'; // January
	S.erase("January");
	cout << S.count("January") << '\n'; // 0
	S.clear();
	cout << S.size() << '\n'; // 0
	cin.get(); // ожидаем нажатие пользователем клавиши

	return 0; // выдаём 0 - правило хорошего тона 
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
