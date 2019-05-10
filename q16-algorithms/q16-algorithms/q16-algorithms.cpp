#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <cctype>
#include <iterator> 
#include <numeric>

int main()
{
	setlocale(LC_ALL, "Russian");
	/////////////////////////////////////////////////////////////////////////////////////count_if

	int data[] = { 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };
	std::vector<int> v(data, data + 10);

	int num_items0 = std::count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });

	std::cout << "количество чисел, дел€щихс€ на три: " << num_items0 << '\n';

	/////////////////////////////////////////////////////////////////////////////////////count

	int target1 = 3;
	int target2 = 5;
	int num_items1 = std::count(v.begin(), v.end(), target1);
	int num_items2 = std::count(v.begin(), v.end(), target2);

	std::cout << "число: " << target1 << " количество: " << num_items1 << '\n';
	std::cout << "число: " << target2 << " количество: " << num_items2 << '\n';

	/////////////////////////////////////////////////////////////////////////////////////find

	auto result1 = std::find(v.begin(), v.end(), target1);
	auto result2 = std::find(v.begin(), v.end(), target2);

	if (result1 != v.end()) 
	{
		std::cout << "v содержит " << target1 << '\n';
	}
	else 
	{
		std::cout << "v не содержит " << target1 << '\n';
	}

	if (result2 != v.end()) 
	{
		std::cout << "v содержит " << target2 << '\n';
	}
	else 
	{
		std::cout << "v не содержит " << target2 << '\n';
	}

	/////////////////////////////////////////////////////////////////////////////////////find_if

	auto result3 = std::find_if(v.begin(), v.end(), [](int i) {return i % 2 == 0; });

	if (result3 != v.end())
	{
		std::cout << "v содержит числа, дел€щиес€ без остатка на 2\n";
	}
	else
	{
		std::cout << "v не содержит чисел, дел€щихс€ без остатка на 2\n";
	}

	/////////////////////////////////////////////////////////////////////////////////////transform
	std::string s("hello");
	std::transform(s.begin(), s.end(), s.begin(), (int (*)(int))std::toupper);
	std::cout << s << std::endl;

	/////////////////////////////////////////////////////////////////////////////////////sort

	std::array<int, 10> arr{ 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };

	std::sort(arr.begin(), arr.end());
	std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	/////////////////////////////////////////////////////////////////////////////////////all_of

	std::vector<int> vctr{ 10, 2 };
	std::cout << "—реди чисел: ";
	std::copy(vctr.cbegin(), vctr.cend(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';
	if (std::all_of(vctr.cbegin(), vctr.cend(), [](int i) { return i % 2 == 0; }))
	{
		std::cout << "¬се числа чЄтные\n";
	}

	/////////////////////////////////////////////////////////////////////////////////////any_of

	struct DivisibleBy
	{
		const int d;
		DivisibleBy(int n) : d(n) {}
		bool operator()(int n) const { return n % d == 0; }
	};

	if (std::any_of(vctr.cbegin(), vctr.cend(), DivisibleBy(10))) {
		std::cout << "ѕо крайней мере одно из чисел делитс€ на 10\n";
	}

	/////////////////////////////////////////////////////////////////////////////////////remove_if

	std::string str = "“екст с несколькими   пробелами";
	std::remove_if(str.begin(), str.end(), [](char i) {return i == ' '; });
	std::cout << str << '\n';

	/////////////////////////////////////////////////////////////////////////////////////replace_if

	std::string str1 = "“екст с несколькими   пробелами";
	std::replace_if(str1.begin(), str1.end(), [](char i) {return i == ' '; }, '_');
	std::cout << str1 << '\n';

	/////////////////////////////////////////////////////////////////////////////////////merge

	const std::size_t items = 10;

	std::vector<int> v1, v2, dst;

	// fill the vectors
	for (std::size_t idx = 0; idx < items; ++idx) {
		v1.push_back(std::rand() % items);
		v2.push_back(std::rand() % items);
	}

	// sort
	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());

	// output v1
	std::cout << "v1 : ";
	std::copy(v1.begin(), v1.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';

	// output v2
	std::cout << "v2 : ";
	std::copy(v2.begin(), v2.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';

	// merge
	std::merge(v1.begin(), v1.end(),
		v2.begin(), v2.end(),
		std::back_inserter(dst));

	// output
	std::cout << "dst: ";
	std::copy(dst.begin(), dst.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';

	/////////////////////////////////////////////////////////////////////////////////////max

	std::cout << "большее из 1 и 9999: " << std::max(1, 9999) << '\n'
		<< "большее из 'a', и 'b': " << std::max('a', 'b') << '\n'
		<< "самое длинное из \"foo\", \"bar\", и \"hello\": " <<
		std::max({ "foo", "bar", "hello" },
			[](const std::string& s1, const std::string& s2) {
				return s1.size() < s2.size();
			}) << '\n';

	/////////////////////////////////////////////////////////////////////////////////////max_element

	std::vector<int> vctr1{ 3, 1, -14, 1, 5, 9 };
	std::vector<int>::iterator result;

	result = std::max_element(vctr1.begin(), vctr1.end());
	std::cout << "индекс максимального элемента: " << std::distance(vctr1.begin(), result) << '\n';

	/////////////////////////////////////////////////////////////////////////////////////is_sorted

	const int N = 5;
	int digits[N] = { 3, 1, 4, 1, 5 };

	for (auto i : digits) std::cout << i << ' ';
	std::cout << ": отсортирован: " << std::is_sorted(digits, digits + N) << '\n';

	std::sort(digits, digits + N);

	for (auto i : digits) std::cout << i << ' ';
	std::cout << ": отсортирован: " << std::is_sorted(digits, digits + N) << '\n';


	/////////////////////////////////////////////////////////////////////////////////////upper_bound
	/////////////////////////////////////////////////////////////////////////////////////lower_bound

	std::vector<int> vdata = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };

	auto lower = std::lower_bound(vdata.begin(), vdata.end(), 4);
	auto upper = std::upper_bound(vdata.begin(), vdata.end(), 4);

	std::copy(lower, upper, std::ostream_iterator<int>(std::cout, " "));

	/////////////////////////////////////////////////////////////////////////////////////accumulate

	std::vector<int> vv{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int sum = std::accumulate(vv.begin(), vv.end(), 0);
	int product = std::accumulate(vv.begin(), vv.end(), 1, [](int x, int y) {return x * y; });
	std::string magic = std::accumulate(vv.begin(), vv.end(), std::string(),[](std::string res, int x) {return res += (x > 5) ? "b" : "s"; });

	std::cout << sum << '\n'
		<< product << '\n'
		<< magic << '\n';

	return 0;
}