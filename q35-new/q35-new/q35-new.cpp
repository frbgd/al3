#include<iostream>

struct T 
{
	T() { std::cout << "T::ctor" << std::endl; }
	static void* operator new(std::size_t size) 
	{
		auto p = ::operator new(size);
		std::cout << "TFoo::new(" << size << ") " << p << std::endl;
		return p;
	}
	static void operator delete(void* p) 
	{
		std::cout << "TFoo::delete(" << p << ")" << std::endl;
		if (!p) return;
		::operator delete(p);
	}

	void* operator new (size_t cnt, const std::string& s) 
	{
		std::cout << s << std::endl;
		return ::operator new(cnt);
	}
	void operator delete (void* p, const std::string& s)
	{
		std::cout << s << std::endl;
		if (!p) return;
		::operator delete(p);
	}
};

int main() 
{
	T* ptr = new T();
	delete ptr;
	std::cout << std::endl;
	T* ptr1 = new (std::string("some bedug message")) T;
	T::operator delete(ptr1, std::string("some debug message"));

	return 0;
}