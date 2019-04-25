#include <iostream>
#include <optional>
#include <complex>

class Input
{
	std::string value = "";
public:
	bool valid()
	{
		return value != "" ? true : false;
	}
	std::string asString() 
	{
		return value;
	}
};

//������� optional �� �������
std::optional<std::string> TryParse(Input input)
{
	if (input.valid())
		return input.asString();

	return std::nullopt;
}
///////////////////////////////////////////////////////////////////////////////
int main() 
{
	//�������� optional
	// ������:
	std::optional<int> oEmpty;
	std::optional<float> oFloat = std::nullopt;

	// ������:
	std::optional<int> oInt(10);
	std::optional oIntDeduced(10); // deduction guides

	// make_optional
	auto oDouble = std::make_optional(3.0);
	auto oComplex = std::make_optional<std::complex<double>>(3.0, 4.0);

	// �����������/������������:
	auto oIntCopy = oInt;
	//////////////////////////////////////////////////////////////////////////////
	//��������� ��������

	// � ������� operator*()
	std::optional<int> oint = 10;
	std::cout << "oint " << *oint << '\n';

	// � ������� value()
	std::optional<std::string> ostr("hello");
	try
	{
		std::cout << "ostr " << ostr.value() << '\n';
	}
	catch (const std::bad_optional_access & e)
	{
		std::cout << e.what() << "\n";
	}

	// � ������� value_or()
	std::optional<double> odouble; // ������
	std::cout << "odouble " << odouble.value_or(10.0) << '\n';
	///////////////////////////////////////////////////////////////////////////
	//optional ����� ������������ � �������� ��� bool (������� ���������� �����)

	// ������� ���������� ������:
	std::optional<std::string> oString = "is not null";
	

	if (oString)
		std::cout << "ostr " << *oString << '\n';
	else
		std::cout << "ostr is null\n";

	////////////////////////////////////////////////////////////////////////////
	//��������� ��������
	std::optional<std::string> oString1;
	std::optional<std::string> oString2;
	// emplace:
	oString1.emplace("string1");
	// �������� ������
	oString1.reset();
	//oString1 = std::nullopt;
	oString2.emplace("string2");
	oString1.swap(oString2);
	// oString1 = "string2";
	////////////////////////////////////////////////////////////////////////////
	//���������
	std::optional<int> oTwo(2);
	std::optional<int> oTen(10);

	std::cout << std::boolalpha;
	std::cout << (oTen > oTwo) << "\n";				//true
	std::cout << (oTen < oTwo) << "\n";				//false
	std::cout << (oEmpty < oTwo) << "\n";			//true
	std::cout << (oEmpty == std::nullopt) << "\n";	//true
	std::cout << (oTen == 10) << "\n";				//true


	return 0;
}