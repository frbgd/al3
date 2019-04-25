#include <variant>
#include <string>
#include<iostream>
using namespace std;

int main()
{
	//присваивание значения
	std::variant<int, bool, std::string> value = "Hello, world!";
	value = 24;
	value = false;

	std::visit([](auto && arg) {
		// Извлекаем тип аргумента текущего применения полиморфной лямбды
		using T = std::decay_t<decltype(arg)>;
		// Выполняем constexpr if
		if constexpr (std::is_same_v<T, int>)
			// Эта ветвь компилируется, если T имеет тип int
			std::cout << "int with value " << arg << '\n';
		else if constexpr (std::is_same_v<T, bool>)
			// Эта ветвь компилируется, если T имеет тип double
			std::cout << "bool with value " << arg << '\n';
		else if constexpr (std::is_same_v<T, std::string>)
			// Эта ветвь компилируется, если T имеет тип std::string
			std::cout << "std::string with value " << arg << '\n';
		else
			// Эта ветвь выдаст ошибку компиляции, если не все типы
			//  были обработаны в остальных ветвях.
			static_assert(always_false<T>::value, "non-exhaustive visitor!");
		}, value);

	return 0;
}