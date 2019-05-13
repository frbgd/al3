#pragma once

class Class
{
public:
	Class();
	~Class();

	// ... публичные методы ...

	void f(double n);

private:
	class Private;
	Private* d;
};