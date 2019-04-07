#include <iostream>

class A
{
public:
	A(std::initializer_list<int> list)
	{
		for (auto& item : list)
		{
			std::cout << "Integral item=" << item << "\n";
		}
	}
	A(std::initializer_list<std::string> list)
	{
		for (auto& item : list)
		{
			std::cout << "String item=" << item << "\n";
		}
	}
};

int main()
{
	//A(std::initializer_list<int> list)
	A a{ 23,321,321,3,213,213,12 };
	//A(std::initializer_list<std::string> list)
	A b{ "one", "two", "three", "eleven" };
	return 0;
};