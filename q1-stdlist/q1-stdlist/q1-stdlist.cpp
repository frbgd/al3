// q1-stdlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <list>

int main()
{
	std::list<int> numbers = { 1, 2, 3, 4, 5 };

	int first = numbers.front();  // 1
	int last = numbers.back();  // 5

	// перебор в цикле
	for (int n : numbers)
		std::cout << n << "\t";
	std::cout << std::endl;

	// перебор с помощью итераторов
	for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
	{
		std::cout << *iter << "\t";
	}
	std::cout << std::endl;

	//////////////////////////////////////////////////////////////////////
	
	int size = numbers.size();   // 5

	/////////////////////////////////////////////////////////////////////////
	
	if (numbers.empty())
		std::cout << "The list is empty" << std::endl;
	else
		std::cout << "The list is not empty" << std::endl;

	///////////////////////////////////////////////////////

	numbers = { 1, 2, 3, 4, 5, 6 };
	numbers.resize(4);  // оставляем первые четыре элемента - numbers = {1, 2, 3, 4}

	numbers.resize(6, 8);    // numbers = {1, 2, 3, 4, 8, 8}

	////////////////////////////////////////////////////////

	numbers = { 1, 2, 3, 4, 5 };

	numbers.assign({ 21, 22, 23, 24, 25 }); // numbers = { 21, 22, 23, 24, 25 }

	numbers.assign(4, 3);       // numbers = {3, 3, 3, 3}

	std::list<int> values = { 6, 7, 8, 9, 10, 11 };
	auto start = ++values.begin();  // итератор указывает на второй элемент из values
	auto end = values.end();
	numbers.assign(start, end); //  numbers = { 7, 8, 9, 10, 11 }

	///////////////////////////////////////////////////////////

	std::list<int> list1 = { 1, 2, 3, 4, 5 };
	std::list<int> list2 = { 6, 7, 8, 9 };
	list1.swap(list2);
	// list1 = { 6, 7, 8, 9};
	// list2 = { 1, 2, 3, 4, 5 };

	/////////////////////////////////////////////////////////

	numbers = { 1, 2, 3, 4, 5 };
	numbers.push_back(23);  // { 1, 2, 3, 4, 5, 23 }
	numbers.push_front(15); // { 15, 1, 2, 3, 4, 5, 23 }
	numbers.emplace_back(24);   // { 1, 2, 3, 4, 5, 23, 24 }
	numbers.emplace_front(14);  // { 14, 15, 1, 2, 3, 4, 5, 23, 24 }

	/////////////////////////////////////////////////////////

	numbers = { 1, 2, 3, 4, 5 };
	auto iter = ++numbers.cbegin(); // итератор указывает на второй элемент
	numbers.emplace(iter, 8); // добавляем после первого элемента  numbers = { 1, 8, 2, 3, 4, 5};

	/////////////////////////////////////////////////////////////

	std::list<int> numbers1 = { 1, 2, 3, 4, 5 };
	auto iter1 = numbers1.cbegin(); // итератор указывает на первый элемент
	numbers1.insert(iter1, 0); // добавляем начало списка  
	//numbers1 = { 0, 1, 2, 3, 4, 5};

	std::list<int> numbers2 = { 1, 2, 3, 4, 5 };
	auto iter2 = numbers2.cbegin(); // итератор указывает на первый элемент
	numbers2.insert(++iter2, 3, 4); // добавляем после первого элемента три четверки  
	//numbers2 = { 1, 4, 4, 4, 2, 3, 4, 5};

	values = { 10, 20, 30, 40, 50 };
	std::list<int> numbers3 = { 1, 2, 3, 4, 5 };
	auto iter3 = numbers3.cbegin(); // итератор указывает на первый элемент
	// добавляем в начало все элементы из values
	numbers3.insert(iter3, values.begin(), values.end());
	//numbers3 = { 10, 20, 30, 40, 50, 1, 2, 3, 4, 5};

	std::list<int> numbers4 = { 1, 2, 3, 4, 5 };
	auto iter4 = numbers4.cend();   // итератор указывает на позицию за последним элементом
	// добавляем в конец список из трех элементов
	numbers4.insert(iter4, { 21, 22, 23 });
	//numbers4 = { 1, 2, 3, 4, 5, 21, 22, 23};


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
