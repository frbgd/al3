//template
//void replace(ForwardIterator first, ForwardIterator last, const T& old_value,
//	const T& new_value)
//{
//	while (first != last)
//	{
//		if (*first == old_value) *first = new_value;
//		++first;
//	}
//}

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	int init[] = { 0, 0, 0, 0, 0 };
	replace(init, init + 5, 0, 1);
	replace(init, init + 5, 1, 2);
	replace(init, init + 5, 2, 0);
	copy(init, init + 5, ostream_iterator<int>(cout, " "));
	return 0;
}