#include <iostream>
#include <functional>
#include <vector>
using namespace std;


void Foo(int a)
{
	if (a > 10 && a < 40)
		cout << "FOO " << a << endl;
}

void Bar(int a)
{
	if (a % 2 == 0)
		cout << "BAR " << a << endl;
}

void DoWork(vector<int>& vc, vector<function<void(int)>> funcvector)
{
	for (auto el : vc)
	{
		for (auto fel : funcvector)
		{
			fel(el);
		}
	}
}

int main()
{
	vector<int> vc = { 1,51,4,10,44,98,8,12,22,29,49 };

	vector<function<void(int)>> fVector;
	fVector.emplace_back(Foo);
	fVector.emplace_back(Bar);

	DoWork(vc, fVector);

	return 0;
}