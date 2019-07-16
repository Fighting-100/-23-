#include <iostream>
using namespace std;

class SystemA
{
public:
	void doThing()
	{
		cout << "systemA do...." << endl;
	}
};
class SystemB
{
public:
	void doThing()
	{
		cout << "systemB do...." << endl;
	}
};

class System1
{
public:
	void doThing()
	{
		cout << "system1 do...." << endl;
	}
};
class System2
{
public:
	void doThing()
	{
		cout << "system2 do...." << endl;
	}
};


class Facade_Alphabet
{
public:
	Facade_Alphabet()
	{
		a = new SystemA;
		b = new SystemB;
	}
	~Facade_Alphabet()
	{
		delete a;
		delete b;
	}
	void doThing()
	{
		a->doThing();
		b->doThing();
	}
private:
	SystemA *a;
	SystemB *b;
};

class Facade_Number
{
public:
	Facade_Number()
	{
		a = new System1;
		b = new System2;
	}
	~Facade_Number()
	{
		delete a;
		delete b;
	}
	void doThing()
	{
		a->doThing();
		b->doThing();
	}
private:
	System1 *a;
	System2 *b;
};

void main()
{
	cout << "显示字母系统：" << endl;
	Facade_Alphabet *f1 = new Facade_Alphabet;
	f1->doThing();
	delete f1;

	cout << "显示数字系统：" << endl;
	Facade_Number *f2 = new Facade_Number;
	f2->doThing();
	delete f2;

	cout << "hello..." << endl;
	system("pause");
	return;
}