#include <iostream>
using namespace std;

class MakeCar
{
public:
	virtual void makeHead() = 0;
	virtual void makeBody() = 0;
	virtual void makeTail() = 0;
public: //把一组行为变成一个模板
	void make()
	{
		makeHead();
		makeBody();
		makeTail();
	}
};

class MakeBus : public MakeCar
{
public:
	virtual void makeHead()
	{
		cout << "bus 组装车头 " << endl;
	}
	virtual void makeBody()
	{
		cout << "bus 组装车身 " << endl;
	}
	virtual void makeTail()
	{
		cout << "bus 组装车尾 " << endl;
	}
};
class MakeJeep : public MakeCar
{
public:
	virtual void makeHead()
	{
		cout << "Jeep 组装车头 " << endl;
	}
	virtual void makeBody()
	{
		cout << "Jeep 组装车身 " << endl;
	}
	virtual void makeTail()
	{
		cout << "Jeep 组装车尾 " << endl;
	}
};

void main()
{
	MakeCar *bus = new MakeBus;
	bus->make();
	MakeCar *jeep = new MakeJeep;
	jeep->make();

	delete bus;
	delete jeep;
	cout << "hello..." << endl;
	system("pause");
	return;
}