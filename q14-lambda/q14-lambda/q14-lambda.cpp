#include <iostream>
#include <functional>
#include <vector>
using namespace std;

void DoWork(vector<int> & vc, function<void(int)> f)
{
	for (auto el : vc)
	{
		f(el);
	}
}

int main()
{
	vector<int> vc = { 1,51,4,10,44,98,8,12,22,29,49 };

	DoWork(vc, [](int a)
		{
			if (a > 10 && a < 40)
				cout << "FOO " << a << endl;
		});

	DoWork(vc, [](int a)
		{
			if (a % 2 == 0)
				cout << "BAR " << a << endl;
		});
	//видимость внешнего контекста
	int p = 0;

	auto f = [&p]()
	{
		p = 5;
	};

	f();
	//возвращаемые значения лямбда-функции

	auto ff = []()
	{
		return 1;
	};

	auto q = ff();

	return 0;
}