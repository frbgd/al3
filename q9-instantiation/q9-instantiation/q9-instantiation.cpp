#include <iostream>
#include "my.h"
#include "my.cpp"

using namespace std;

int main()
{
	cout << sqr(10) << "\n";  // OK
	cout << sqr(1.2) << "\n"; // OK
	cout << sqr(10L) << "\n"; // Ошибка, нет sqr(long)

	X<int> x1(10);
	cout << x1.get() << "\n"; // OK
	X<double> x2(1.2);
	cout << x2.get() << "\n"; // Ошибка, нет X<double>::get()
	return 0;
}