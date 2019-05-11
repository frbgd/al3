#include <iostream>
#include <string>
#include <memory>

class MyClass
{
	std::string str;
public:
	MyClass(std::string str)
	{
		this->str = str;
	}
	void GetStr()
	{
		std::cout << str << std::endl;
	}
};

int main()
{
	auto ptr = new std::string("string");

	std::shared_ptr<std::string> sptr1(ptr);



	auto sptr2 = std::make_shared<MyClass>("2ndstring");
	std::shared_ptr<MyClass> sptr3;
	sptr3 = sptr2;

	sptr2.reset();
	sptr3.get()->GetStr();

	return 0;
}