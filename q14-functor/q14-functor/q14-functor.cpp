#include <iostream>
using namespace std;

class MyFunctor
{
public:
	int operator ()(int a, int b)
	{
		cout << a + b << endl;
		return a + b;
	}
private:
	
};

class EvenFunctor
{
	int evenSum = 0;
	int evenCount = 0;
public:
	void operator()(int value)
	{
		if (value % 2 == 0)
		{
			evenSum += value;
			evenCount++;
		}
	}

	void ShowEvenSum()
	{
		cout << "Even number sum = " << evenSum << endl;
	}
	void ShowEvenCount()
	{
		cout << "Even number count = " << evenCount << endl;
	}
};

int main()
{
	int arr[] = { 1,2,55,99,44,3,6 };

	EvenFunctor ef;

	for (auto el : arr)
	{
		ef(el);
	}

	ef.ShowEvenCount();
	ef.ShowEvenSum();

	return 0;
}