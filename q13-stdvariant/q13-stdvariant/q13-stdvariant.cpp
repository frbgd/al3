#include <variant>
#include <string>
#include<iostream>
using namespace std;

int main()
{
	//присваивание значения
	variant<string, int, bool> mySetting = string("Hello!"); // или
	mySetting = 42; // или
	mySetting = false;
	/////////////////////////////////////////////////////////////////
	//определение значения
	[=](auto & arg)
	{
		using T = std::decay_t<decltype(arg)>;

		if constexpr (std::is_same_v<T, string>)
		{
			//printf("string: %s\n", arg.c_str());
			// ...
			cout << "string " + arc.c_str();
		}
		else if constexpr (std::is_same_v<T, int>)
		{
			//printf("integer: %d\n", arg);
			// ...
			cout << "int " + arg;
		}
		else if constexpr (std::is_same_v<T, bool>)
		{
			//printf("bool: %d\n", arg);
			// ...
			cout << "bool " + arg;
		}
	}(mySetting);
	return 0;
}