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

	// но если с возвращаемыми данными надо сделать какую-то операцию, то эта операция будет отадавать временную строку, которая удалится до того, как её примет string_view
	//требуется приведение данных
	std::string_view GetSubstring() const
	{
		return std::string_view(m_str).substr(1u);
	}
};

int main()
{
	return 0;
}