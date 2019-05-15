#include<thread>
#include<vector>
#include<chrono>
#include<iostream>

void add_to_element(std::vector<int> *vct, int n)
{
	vct->front() += n;
}

int main()
{
	auto v = new std::vector<int>(1, 1);

	std::thread t1(add_to_element, v, 3);
	std::thread t2(add_to_element, v, 5);

	t1.detach();
	t2.detach();
	for (int i = 0; i < 10; i++) 
	{
		std::cout << v->front() << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	return 0;
}