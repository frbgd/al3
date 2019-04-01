//template
//Function for_each(InputIterator first, InputIterator last, Function f)
//{
//	while (first != last) f(*first++);
//	return f;
//}

#include <iostream>
#include <algorithm>

using namespace std;

void printValue(int num)
{
	cout << num << " ";
}

int main()
{
	int init[] = { 1, 2, 3, 4, 5 };
	for_each(init, init + 5, printValue);
	return 0;
}