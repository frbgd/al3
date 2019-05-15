#include <iostream>
#include <future>

int getting_data()
{
	std::this_thread::sleep_for(std::chrono::seconds(10));
	std::cout << "getting_data done\n";
	return 42;
}

int main()
{
	std::cout << "first test - launch\n";

	// launch getting_data here
	std::future<int> f1 = std::async(std::launch::async, getting_data);
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << "main slept, calling f.get()\n";
	std::cout << f1.get() << std::endl;
	// total time is about 10s

	/////////////////////////////////////////////////////////////////////////
	std::cout << "\nsecond test - deffered\n";
	std::future<int> f2 = std::async(std::launch::deferred, getting_data);
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << "main slept, calling f.get()\n";
	std::cout << f2.get() << std::endl; // actually function is launched here
	// total time is about 15s

	return 0;
}