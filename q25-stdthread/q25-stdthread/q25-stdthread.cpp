#include <iostream>
#include <thread>
#include <chrono>

void foo()
{
	// simulate expensive operation
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << "foo done\n";
}

void bar()
{
	// simulate expensive operation
	std::this_thread::sleep_for(std::chrono::seconds(10));
	std::cout << "bar done\n";
}

int main()
{
	std::cout << "starting first helper...\n";
	std::thread helper1(foo);

	std::cout << "starting second helper...\n";
	std::thread helper2(foo);

	std::cout << "starting third helper...\n";
	std::thread helper3(bar);

	std::cout << "waiting for helpers to finish...\n";
	helper1.join();
	helper2.join();
	helper3.detach();

	std::cout << "done!\n";
}