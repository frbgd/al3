#include <iostream>
using namespace std;

int main()
{
	enum oldFruits
	{
		LEMON, // LEMON находится внутри той же области видимости, что и Fruits
		KIWI
	};

	enum oldColors
	{
		PINK, // PINK находится внутри той же области видимости, что и Colors
		GRAY
	};

	oldFruits oldfruit = LEMON; // Fruits и LEMON доступны в одной области видимости (добавлять префикс не надо)
	oldColors oldcolor = PINK; // Colors и PINK доступны в одной области видимости (добавлять префикс не надо)

	if (oldcolor == oldfruit) // Компилятор будет сравнивать переменные как целые числа
		std::cout << "fruit and color are equal\n"; // и обнаружит, что они равны!
	else
		std::cout << "fruit and color are not equal\n";

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	enum class Fruits // добавление "class" к enum определяет перечисление с ограниченной областью видимости, вместо стандартного "глобального" перечисления 
	{
		LEMON, // LEMON находится внутри той же области видимости, что и Fruits
		Kiwi
	};

	enum class Colors
	{
		PINK, // PINK находится внутри той же области видимости, что и Colors
		GRAY
	};

	// примечание: LEMON напрямую не доступен, мы должны использовать Fruits::LEMON
	// примечание: PINK напрямую не доступен, мы должны использовать Colors::PINK

	Colors color = Colors::PINK;

	//if (fruit == color) // ошибка компиляции, поскольку компилятор не знает как сравнивать разные типы: Fruits и Colors
	//	std::cout << "fruit and color are equal\n";
	//else
	//	std::cout << "fruit and color are not equal\n";

	if (color == Colors::PINK) // это нормально
		std::cout << "The color is pink!\n";
	else if (color == Colors::GRAY)
		std::cout << "The color is gray!\n";

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//std::cout << color; // не будет работать, поскольку нет неявного преобразования в int
	std::cout << static_cast<int>(color); // результатом будет 1

	return 0;
}