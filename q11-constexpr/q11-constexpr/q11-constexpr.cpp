int sum(int a, int b)
{
	return a + b;
}

constexpr int new_sum(int a, int b)
{
	return a + b;
}

int main()
{
	constexpr int a1 = new_sum(5, 12); // ��: constexpr-����������
	//constexpr int a2 = sum(5, 12); // ������: ������� sum �� �������� constexp-����������
	int a3 = new_sum(5, 12); // ��: ������� ����� ������� �� ����� ����������
	int a4 = sum(5, 12); // ��

	return 0;
}