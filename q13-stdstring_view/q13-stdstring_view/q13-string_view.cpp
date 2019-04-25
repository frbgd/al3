#include <string>
#include <string_view>

class foo
{
	std::string m_str;

public:
	std::string_view GetString() const
	{
		return m_str;
	}

	// �� ���� � ������������� ������� ���� ������� �����-�� ��������, �� ��� �������� ����� ��������� ��������� ������, ������� �������� �� ����, ��� � ������ string_view
	//��������� ���������� ������
	std::string_view GetSubstring() const
	{
		return std::string_view(m_str).substr(1u);
	}
};

int main()
{
	return 0;
}