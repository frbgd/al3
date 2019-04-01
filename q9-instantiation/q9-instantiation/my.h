#pragma once
template <typename T> T sqr(T);
template <typename T> class X
{
	T x;
public:
	X(T x) :x(x) {}
	T get()const;
	void set(T);
};