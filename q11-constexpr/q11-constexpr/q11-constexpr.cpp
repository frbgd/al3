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
	constexpr int a1 = new_sum(5, 12); // ОК: constexpr-переменная
	//constexpr int a2 = sum(5, 12); // ошибка: функция sum не является constexp-выражением
	int a3 = new_sum(5, 12); // ОК: функция будет вызвана на этапе компиляции
	int a4 = sum(5, 12); // ОК

	return 0;
}