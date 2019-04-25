#include <iostream>
using namespace std;

string GetDataFromBD()
{
	return "Data from BD";
}

string GetDataFromWebServer()
{
	return "Data from WebServer";
}

void ShowInfo(string(*foo)())
{
	cout << foo() << endl;
}

int main()
{
	ShowInfo(GetDataFromBD);

	ShowInfo(GetDataFromWebServer);

	return 0;
}