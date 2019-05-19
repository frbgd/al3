#include<atomic>
#include<mutex>
#include<future>
#include<iostream>

int main()
{

	std::atomic_int temp{ 0 };
	std::recursive_mutex _mutex;

	//launch_deferred launches asynchronous tasks on the same thread id

	auto future1 = std::async(
		std::launch::deferred,
		[&]()
		{
			std::cout << std::this_thread::get_id() << std::endl;

			std::this_thread::sleep_for(std::chrono::seconds(3));
			std::unique_lock<std::recursive_mutex> lock(_mutex);
			temp = 0;

		});

	auto future2 = std::async(
		std::launch::deferred,
		[&]()
		{
			std::cout << std::this_thread::get_id() << std::endl;
			while (true)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				std::unique_lock<std::recursive_mutex> lock(_mutex, std::try_to_lock);
				if (temp < INT_MAX)
					temp++;

				std::cout << temp << std::endl;

			}
		});
	future1.get();
	future2.get();

	return 0;
}