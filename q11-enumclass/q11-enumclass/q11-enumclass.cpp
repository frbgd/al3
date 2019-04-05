#include <iostream>
using namespace std;

int main()
{
	enum oldFruits
	{
		LEMON, // LEMON ��������� ������ ��� �� ������� ���������, ��� � Fruits
		KIWI
	};

	enum oldColors
	{
		PINK, // PINK ��������� ������ ��� �� ������� ���������, ��� � Colors
		GRAY
	};

	oldFruits oldfruit = LEMON; // Fruits � LEMON �������� � ����� ������� ��������� (��������� ������� �� ����)
	oldColors oldcolor = PINK; // Colors � PINK �������� � ����� ������� ��������� (��������� ������� �� ����)

	if (oldcolor == oldfruit) // ���������� ����� ���������� ���������� ��� ����� �����
		std::cout << "fruit and color are equal\n"; // � ���������, ��� ��� �����!
	else
		std::cout << "fruit and color are not equal\n";

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	enum class Fruits // ���������� "class" � enum ���������� ������������ � ������������ �������� ���������, ������ ������������ "�����������" ������������ 
	{
		LEMON, // LEMON ��������� ������ ��� �� ������� ���������, ��� � Fruits
		Kiwi
	};

	enum class Colors
	{
		PINK, // PINK ��������� ������ ��� �� ������� ���������, ��� � Colors
		GRAY
	};

	// ����������: LEMON �������� �� ��������, �� ������ ������������ Fruits::LEMON
	// ����������: PINK �������� �� ��������, �� ������ ������������ Colors::PINK

	Colors color = Colors::PINK;

	//if (fruit == color) // ������ ����������, ��������� ���������� �� ����� ��� ���������� ������ ����: Fruits � Colors
	//	std::cout << "fruit and color are equal\n";
	//else
	//	std::cout << "fruit and color are not equal\n";

	if (color == Colors::PINK) // ��� ���������
		std::cout << "The color is pink!\n";
	else if (color == Colors::GRAY)
		std::cout << "The color is gray!\n";

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//std::cout << color; // �� ����� ��������, ��������� ��� �������� �������������� � int
	std::cout << static_cast<int>(color); // ����������� ����� 1

	return 0;
}