#include <iostream>
#include <string>
using namespace std;

class Product {
public:
	virtual string getName() = 0;
	virtual ~Product() = default;
};

class ConcreteProductA : public Product {
public:
	string getName()override { return "ConcreteProductA"; }
};

class ConcreteProductB : public Product {
public:
	string getName()override { return "ConcreteProductB"; }
};

class Creator {
public:
	virtual Product* factoryMethod() = 0;
	virtual ~Creator() = default;
};

class ConcreteCreatorA : public Creator {
public:
	Product* factoryMethod()override { return new ConcreteProductA(); }
};

class ConcreteCreatorB : public Creator {
public:
	Product* factoryMethod()override { return new ConcreteProductB(); }
};

int main()
{

	ConcreteCreatorA CreatorA;
	ConcreteCreatorB CreatorB;
	// An array of creators
	Creator* creators[] = { &CreatorA, &CreatorB };
	// Iterate over creators and create products
	for (auto&& creator : creators) {
		Product* product = creator->factoryMethod();
		cout << product->getName() << endl;
		delete product;
	}
	return 0;
}