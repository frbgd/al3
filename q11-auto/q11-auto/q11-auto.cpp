template <typename T, typename E>
auto compose(T a, E b) -> decltype(a + b) // decltype - ��������� ���������� ��� �� ������ �������� ���������
{
	return a + b;
}

int main()
{
	auto c = compose(2, 3.14); // c - double

	return 0;
}