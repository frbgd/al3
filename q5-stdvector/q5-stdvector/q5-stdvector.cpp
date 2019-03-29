// q5-stdvector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	std::vector<int> v1;              // пустой вектор
	std::vector<int> v2(v1);          // вектор v2 - копия вектора v1
	std::vector<int> v3 = v1;         // вектор v3 - копия вектора v1
	std::vector<int> v4(5);               // вектор v4 состоит из 5 чисел
	std::vector<int> v5(5, 2);            // вектор v5 состоит из 5 чисел, каждое число равно 2
	std::vector<int> v6{ 1, 2, 4, 5 };  // вектор v6 состоит из чисел 1, 2, 4, 5
	std::vector<int> v7 = { 1, 2, 3, 5 }; // вектор v7 состоит из чисел 1, 2, 4, 5

	std::vector<int> v8(5);       // вектор состоит из 5 чисел, каждое число в векторе равно 0
	std::vector<int> v9{ 5 };       // вектор состоит из одного числа, которое равно 5
	std::vector<int> v10(5, 2);    // вектор состоит из 5 чисел, каждое число равно 2
	std::vector<int> v11{ 5, 2 };    // вектор состоит из двух чисел 5 и 2

	///////////////////////////////////////////////////

	std::vector<int> numbers = { 1, 2, 3, 4, 5 };

	int n1 = numbers.front();   // n1 = 1
	int n2 = numbers.back();    // n2 = 5
	int x = numbers[1]; // x = 2
	numbers[0] = 6;

	for (int n : numbers)
		cout << n << "\t";  // 6  2  3  4  5

	std::cout << std::endl;

	/////////////////////////////////////////////////////

	try
	{
		int n = numbers.at(8);
	}
	catch (std::out_of_range e)
	{
		std::cout << "Incorrect index" << std::endl;
	}

	////////////////////////////////////////////////////

	numbers.clear();

	numbers.push_back(5);
	numbers.push_back(3);
	numbers.push_back(10);
	for (int n : numbers)
		cout << n << "\t";      // 5    3   10

	std::cout << std::endl;

	///////////////////////////////////////////////////////

	std::vector<int> numbers0 = { 1, 2, 3, 4, 5 };
	numbers0.emplace_back(8);   // numbers0 = { 1, 2, 3, 4, 5, 8 };

	////////////////////////////////////////////////

	auto iter = numbers.cbegin();   // константный итератор указывает на первый элемент
	numbers.emplace(iter + 2, 8); // добавляем после второго элемента  numbers = { 1, 2, 8, 3, 4, 5};

	//////////////////////////////////////////////////

	std::vector<int> numbers1 = { 1, 2, 3, 4, 5 };
	auto iter1 = numbers1.cbegin(); // константный итератор указывает на первый элемент
	numbers1.insert(iter1 + 2, 8); // добавляем после второго элемента  
	//numbers1 = { 1, 2, 8, 3, 4, 5};

	std::vector<int> numbers2 = { 1, 2, 3, 4, 5 };
	auto iter2 = numbers2.cbegin(); // константный итератор указывает на первый элемент
	numbers2.insert(iter2 + 1, 3, 4); // добавляем после первого элемента три четверки  
	//numbers2 = { 1, 4, 4, 4, 2, 3, 4, 5};

	std::vector<int> values = { 10, 20, 30, 40, 50 };
	std::vector<int> numbers3 = { 1, 2, 3, 4, 5 };
	auto iter3 = numbers3.cbegin(); // константный итератор указывает на первый элемент
	// добавляем после первого элемента три первых элемента из вектора values
	numbers3.insert(iter3 + 1, values.begin(), values.begin() + 3);
	//numbers3 = { 1, 10, 20, 30, 2, 3, 4, 5};

	std::vector<int> numbers4 = { 1, 2, 3, 4, 5 };
	auto iter4 = numbers4.cend();   // константный итератор указывает на позицию за последним элементом
	// добавляем в конец вектора numbers4 элементы из списка { 21, 22, 23 }
	numbers4.insert(iter4, { 21, 22, 23 });
	//numbers4 = { 1, 2, 3, 4, 5, 21, 22, 23};

	//////////////////////////////////////////////////////////

	std::vector<int> v = { 1,2,3,4 };
	v.pop_back();       // v = { 1,2,3 }

	///////////////////////////////////////

	std::vector<int> numbers5 = { 1, 2, 3, 4, 5, 6 };
	auto iter5 = numbers5.cbegin(); // указатель на первый элемент
	numbers5.erase(iter5 + 2);   // удаляем третий элемент
	// numbers5 = { 1, 2, 4, 5, 6 }

	std::vector<int> numbers6 = { 1, 2, 3, 4, 5, 6 };
	auto begin = numbers6.cbegin(); // указатель на первый элемент
	auto end = numbers6.cend();     // указатель на последний элемент
	numbers6.erase(begin + 2, end - 1); // удаляем с третьего элемента до последнего
	// numbers6 = {1, 2, 6}

	////////////////////////////////////////////////

	vector<int> numbers7 = { 1, 2, 3 };
	if (numbers7.empty())
		cout << "Vector is empty" << endl;
	else
		cout << "Vector has size " << numbers.size() << endl;

	///////////////////////////////////////////////////////////

	std::vector<int> numbers8 = { 1, 2, 3, 4, 5, 6 };
	numbers8.resize(4); // оставляем первые четыре элемента - numbers1 = {1, 2, 3, 4}

	numbers8.resize(6, 8);   // numbers8 = {1, 2, 3, 4, 8, 8}

	////////////////////////////////////////////////

	std::vector<std::string> names = { "Tom", "Bob", "Kate" };
	names.assign(4, "Sam"); // numbers = {"Sam", "Sam", "Sam", "Sam"}

	/////////////////////////////////////////////////////

	std::vector<std::string> clangs = { "C++", "C#", "Java" };
	std::vector<std::string> ilangs = { "JavaScript", "Python", "PHP" };
	clangs.swap(ilangs);    // clangs = { "JavaScript", "Python", "PHP"};
	for (std::string n : clangs)
		std::cout << n << "\t";
	std::cout << std::endl;

	/////////////////////////////////////////////////////////

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
