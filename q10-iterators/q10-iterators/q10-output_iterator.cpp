#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

using namespace std;
int main(void)
{
	int init1[] = { 1, 2, 3, 4, 5 };
	int init2[] = { 6, 7, 8, 9, 10 };
	vector<int> v(10);
	merge(init1, init1 + 5, init2, init2 + 5, v.begin());
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	return 0;
}