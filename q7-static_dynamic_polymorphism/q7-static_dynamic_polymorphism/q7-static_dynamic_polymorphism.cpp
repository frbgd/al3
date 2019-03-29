// q7-static_dynamic_polymorphism.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class A
{
public:
	virtual void Foo1()
	{
		std::cout << "Foo of A" << std::endl;
	}
	void Foo2()
	{
		std::cout << "Foo of A" << std::endl;
	}
};

class B : public A
{
public:
	void Foo1() override		//динамический полиморфизм
	{
		std::cout << "Foo of B" << std::endl;
	}
	void Foo2()					//статический полиморфизм
	{
		std::cout << "Foo of B" << std::endl;
	}
};

int main()
{
	A a;
	B b;
	A *ptr;
	ptr = &a;
	ptr->Foo1();
	ptr->Foo2();

	ptr = &b;
	ptr->Foo1();
	ptr->Foo2();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
