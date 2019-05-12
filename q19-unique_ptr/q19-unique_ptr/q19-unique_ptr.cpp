#include <iostream>
#include <memory>

struct Foo {
	Foo() { std::cout << "Foo::Foo\n"; }
	~Foo() { std::cout << "Foo::~Foo\n"; }
	void bar() { std::cout << "Foo::bar\n"; }
};

void f(const Foo& foo)
{
	std::cout << "f(const Foo&)\n";
}

int main()
{
	std::unique_ptr<Foo> p1(new Foo);  // p1 ������� Foo
	if (p1) p1->bar();

	{
		std::unique_ptr<Foo> p2(std::move(p1));  // ������ p2 ������� Foo
		f(*p2);

		p1 = std::move(p2);  // �������� ���������� p1
		std::cout << "destroying p2...\n";
	}

	if (p1) p1->bar();

	std::unique_ptr<Foo> p3(p1.release());

	p3.reset(new Foo);

	p3.swap(p1);

	// ��������� Foo ���������, ����� p1 �������� ������� ���������

	return 0;
}