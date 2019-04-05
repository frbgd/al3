template <typename T, size_t Size>
class Vector
{
	static_assert(Size > 3, "Size is too small");
	T _points[Size];
};

int main()
{
	Vector<int, 16> a1;
	//Vector<double, 2> a2;
	return 0;
}