#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	setlocale(LC_ALL, "Russian");
	/////////////////////////////////////////////////////////////////////////////////////count_if

	int data[] = { 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };
	std::vector<int> v(data, data + 10);

	int num_items0 = std::count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });

	std::cout << "количество чисел, делящихся на три: " << num_items0 << '\n';

	/////////////////////////////////////////////////////////////////////////////////////count

	int target1 = 3;
	int target2 = 5;
	int num_items1 = std::count(v.begin(), v.end(), target1);
	int num_items2 = std::count(v.begin(), v.end(), target2);

	std::cout << "число: " << target1 << " количество: " << num_items1 << '\n';
	std::cout << "число: " << target2 << " количество: " << num_items2 << '\n';

	/////////////////////////////////////////////////////////////////////////////////////find

	auto result1 = std::find(v.begin(), v.end(), target1);
	auto result2 = std::find(v.begin(), v.end(), target2);

	if (result1 != v.end()) 
	{
		std::cout << "v содержит " << target1 << '\n';
	}
	else 
	{
		std::cout << "v не содержит " << target1 << '\n';
	}

	if (result2 != v.end()) 
	{
		std::cout << "v содержит " << target2 << '\n';
	}
	else 
	{
		std::cout << "v не содержит " << target2 << '\n';
	}

	/////////////////////////////////////////////////////////////////////////////////////find_if

	auto result3 = std::find_if(v.begin(), v.end(), [](int i) {return i % 2 == 0; });

	if (result3 != v.end())
	{
		std::cout << "v содержит числа, делящиеся без остатка на 2\n";
	}
	else
	{
		std::cout << "v не содержит чисел, делящихся без остатка на 2\n";
	}

	return 0;
}