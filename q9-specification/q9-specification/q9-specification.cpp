#include <cstring>

template <typename T>
inline T maximum(T a, T b)
{
	return  a < b ? b : a;
}

template<>
inline const char * maximum<const char *>(const char *a, const char * b)
{
	return strcmp(a, b) > 0 ? a : b;
}

////////////////////////////////////////////

template <typename T = int, int size = 100>
class Stack {
	T s[size];
	int t;
public:
	Stack() :t(-1) {} // ������������ ������
	bool isEmpty()const { return t == -1; }
	bool isFull()const { return t == size - 1; }
	void pop();
	const T & top()const;
	void push(const T &);
};
class StackEmpty {}; // ������ ��� �������������� �� �������
class StackFull {};
template <typename T, int size>
void Stack<T, size>::pop()
{
	if (!isEmpty())
		--t;
}
template <typename T, int size>
const T & Stack<T, size>::top()const
{
	if (isEmpty())
		throw StackEmpty();
	return s[t];
}
template <typename T, int size>
void Stack<T, size>::push(const T& v)
{
	if (isFull())
		throw StackFull(); // �������� �� ������
	s[++t] = v;
}

template <int size> // ��������� �������������
class Stack<char *, size> {
	char *s[size];
	int t;
public:
	Stack() :t(-1) {} // ������������ ������
	bool isEmpty() { return t == -1; }
	bool isFull() { return t == size - 1; }
	~Stack() { while (!isEmpty()) pop(); }
	void pop();
	const char * top();
	void push(const char *);
};
template <int size>
void Stack<char *, size>::pop()
{
	if (!isEmpty())
		delete[] s[t--];
}
template <int size>
const char * Stack<char *, size>::top()
{
	if (isEmpty())
		throw StackEmpty();
	return s[t];
}
template <int size>
void Stack<char *, size>::push(const char *v)
{
	if (isFull())
		throw StackFull(); // �������� �� ������
	s[++t] = new char[strlen(v) + 1];
	strcpy(s[t], v);
}

int main()
{
	int a = 0, b = 1, c;
	double d = 0.5, e;
	c = maximum(a, b); // ��� ��������� ������� ����� ��� int, ������ �������� ������� - ��� int
	e = maximum<double>(d, a); // ��� ��������� ������� ������ ���������� �� ���� ���������� �������,
						// ��������� ���� ��� double

	//////////////////////////////////////////////

	Stack<int, 200> A; // ���� ����� ����� �������� 200
	Stack<double> B;  // ���� ������������ ����� �������� 100
	Stack<> C;        // ���� ����� ����� �������� 100, <> �����������
	return 0;
}