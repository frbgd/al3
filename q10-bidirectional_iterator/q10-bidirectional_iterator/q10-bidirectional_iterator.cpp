#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	vector<int>::iterator iter = v.begin();
	while (iter != v.end()) 
	{
		cout << *iter << " ";
		iter++;
	}
	cout << endl;
	while (iter != v.begin())
	{
		iter--;
		cout << *iter << " ";
	}
	cout << endl;;

	//////////////////////////////

	vector<int> w = { 1, 2, 3, 4, 5 };
	vector<int>::iterator iter1 = w.begin();
	vector<int>::iterator iter2 = iter1 + 2;
	cout << *iter2 << endl;       // 3

	bool res = iter2 > iter1;    // true
	cout << res << endl;
	return 0;
}