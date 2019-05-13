#include "q22-pimpl.h"

class Class::Private
{
public:
	// ... приватные данные и методы ...
	bool canAcceptN(double num) const { return num != 0; }
	double n;
};

Class::Class()
	: d(new Private) {}

Class::~Class()
{
	delete d;
}

void Class::f(double n)
{
	if (d->canAcceptN(n))
		d->n = n;
}

int main()

{
	auto a = new Class();

	a->f(0);

	a->f(2.71);

	a->~Class();

	return 0;
}