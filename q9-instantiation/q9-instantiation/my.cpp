#include "my.h"
template <typename T> T sqr(T x)
{
	return x * x;
}
template <typename T> T X<T>::get() const
{
	return x;
}
template <typename T> void X<T>::set(T x)
{
	this->x = x;
}
template double sqr(double); // ����� ��������������� ������� �������
template int sqr(int);       // ��� ���� ����� ����������
template class X<int>;       // � ������ ��� ���� int