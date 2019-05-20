#include <atomic>
#include <thread>
#include <iostream>

struct AtomicCounter {
	std::atomic<int> value;

	void increment() {
		++value;
	}

	void decrement() {
		--value;
	}

	int get() {
		return value.load();
	}
};


AtomicCounter counter;

void hello() {
	for (int i = 0; i < 100; i++) {
		counter.increment();
	}
}

int main() {
	// создаем потоки
	std::thread t1(hello);
	std::thread t2(hello);
	std::thread t3(hello);

	t1.join();
	t2.join();
	t3.join();

	std::cout << counter.get() << std::endl;

	return 0;
}