#include <variant>
#include <string>
#include<iostream>
using namespace std;

int main()
{
	//������������ ��������
	std::variant<int, bool, std::string> value = "Hello, world!";
	value = 24;
	value = false;

	std::visit([](auto && arg) {
		// ��������� ��� ��������� �������� ���������� ����������� ������
		using T = std::decay_t<decltype(arg)>;
		// ��������� constexpr if
		if constexpr (std::is_same_v<T, int>)
			// ��� ����� �������������, ���� T ����� ��� int
			std::cout << "int with value " << arg << '\n';
		else if constexpr (std::is_same_v<T, bool>)
			// ��� ����� �������������, ���� T ����� ��� double
			std::cout << "bool with value " << arg << '\n';
		else if constexpr (std::is_same_v<T, std::string>)
			// ��� ����� �������������, ���� T ����� ��� std::string
			std::cout << "std::string with value " << arg << '\n';
		else
			// ��� ����� ������ ������ ����������, ���� �� ��� ����
			//  ���� ���������� � ��������� ������.
			static_assert(always_false<T>::value, "non-exhaustive visitor!");
		}, value);

	return 0;
}