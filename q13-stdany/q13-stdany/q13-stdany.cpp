#include <any>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	std::vector<any> v{ 1, 2.2, false, "hi!" };

	auto& t = v[1].type();  // Что содержится в этом std::any?
	if (t == typeid(double))
		std::cout << "We have a double" << "\n";
	else
		std::cout << "We have a problem!" << "\n";

	std::cout << any_cast<double>(v[1]) << std::endl;

	//нужно точное соответствие данных
	try {
		std::cout << any_cast<int>(v[1]) << std::endl;
	}
	catch (std::bad_any_cast&) {
		std::cout << "wrong type" << std::endl;
	}


	return 0;
}