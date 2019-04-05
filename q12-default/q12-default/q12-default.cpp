class Foo
{
public:
	Foo() = default;
	Foo(const Foo&) = delete;
	void bar(int) = delete;
	void bar(double) {}
};

int main()
{
	Foo obj;
	//obj.bar(5);     // ошибка!
	obj.bar(5.42);  // ok

	return 0;
}