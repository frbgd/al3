#include<iostream>

struct Y
{
	Y() {}
	Y(const Y&) { std::cout << "Copy constructor\n"; }
	Y(Y&&) { std::cout << "Move constructor\n"; }
};

struct X
{
	template<typename A, typename B>
	X(A&& a, B&& b) :
		// retrieve the original value category from constructor call
		// and pass on to member variables
		a_{ std::forward<A>(a) },
		b_{ std::forward<B>(b) }
	{
	}

	Y a_;
	Y b_;
};

template<typename A, typename B>
X factory(A&& a, B&& b)
{
	// retrieve the original value category from the factory call
	// and pass on to X constructor
	return X(std::forward<A>(a), std::forward<B>(b));
}

int main()
{
	Y y;
	X two = factory(y, Y());
	// the first argument is a lvalue, eventually a_ will have the
	// copy constructor called
	// the second argument is an rvalue, eventually b_ will have the
	// move constructor called
	return 0;
}

// prints:
// Copy constructor
// Move constructor