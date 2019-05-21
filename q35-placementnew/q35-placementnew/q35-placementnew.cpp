#include<iostream>

struct TFoo 
{
	TFoo() { std::cout << "TFoo::TFoo" << std::endl; }
	~TFoo() { std::cout << "TFoo::~TFoo" << std::endl; }
};

constexpr int memorySize = 1000;
static_assert(memorySize > sizeof(TFoo), "too little memory");
char static_data[memorySize];

int main() 
{
	char* data = static_data;
	TFoo* foo = new (data) TFoo;
	data += sizeof(TFoo);
	foo->~TFoo();

	return 0;
}