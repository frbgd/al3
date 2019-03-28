// q4-stdunordered_map.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <unordered_map>
#include <string>

int main()
{

	std::unordered_map<std::string, std::string> mymap;
	mymap = { {"Australia","Canberra"},{"U.S.","Washington"},{"France","Paris"} };

	std::cout << "mymap contains:";
	for (auto it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << " " << it->first << ":" << it->second;
	std::cout << std::endl;

	std::cout << "mymap's buckets contain:\n";
	for (unsigned i = 0; i < mymap.bucket_count(); ++i) {
		std::cout << "bucket #" << i << " contains:";
		for (auto local_it = mymap.begin(i); local_it != mymap.end(i); ++local_it)
			std::cout << " " << local_it->first << ":" << local_it->second;
		std::cout << std::endl;
	}

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
