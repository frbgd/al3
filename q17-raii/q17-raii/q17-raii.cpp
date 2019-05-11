#include <string>
#include <stdexcept>

template < class T>
struct ScopedPtr 
{
	T* ptr;
	ScopedPtr(T* p) noexcept
	{
		ptr = p;
	}
	~ScopedPtr() noexcept
	{
		delete ptr;
	}
};

int main()
{
	try 
	{
		ScopedPtr<std::string> str(new std::string("newstring"));

		throw std::logic_error("error");
	}
	catch (...) 
	{

	}

	return 0;
}