// q8-virtual_override_final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

class Person
{
public:
	Person(std::string n, int a)
	{
		name = n; age = a;
	}
	virtual void display()
	{
		std::cout << "Name: " << name << "\tAge: " << age << std::endl;
	}
	virtual void displayfinal() final 
	{
		std::cout << "this is non-inheritanced function" << std::endl;
	}
protected:
	std::string name;
private:
	int age;
};
class Employee : public Person
{
public:
	Employee(std::string n, int a, std::string c) :Person(n, a)
	{
		company = c;
	}
	void display() override
	{
		Person::display();
		std::cout << "Company: " << company << std::endl;
	}
	/*void displayfinal() override 
	{

	}*/
private:
	std::string company;
};

int main()
{
	Person tom("Tom", 23);
	tom.display();
	Employee bob("Bob", 31, "Microsoft");
	bob.display();

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
