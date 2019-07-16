#include <iostream>
using namespace std;

class Engine
{
public:
	virtual void installEngine() = 0;
};
class Engine4000 : public Engine
{
public:
	virtual void installEngine()
	{
		cout << "安装发动机 Engine4000" << endl;
	}
};
class Engine3500 : public Engine
{
public:
	virtual void installEngine()
	{
		cout << "安装发动机 Engine 3500" << endl;
	}
};

class Car
{
public:
	Car(Engine* engine):m_engine(engine){}
	virtual void installEngine() = 0;
protected:
	Engine * m_engine;
};

class BMW5 : public Car
{
public:
	BMW5(Engine* engine) : Car(engine){}
	virtual void installEngine()
	{
		m_engine->installEngine();
		cout << "BMW5 3500CC" << endl;
	}
};
class BMW6 : public Car
{
public:
	BMW6(Engine* engine) : Car(engine) {}
	virtual void installEngine()
	{
		m_engine->installEngine();
		cout << "BMW5 3500CC" << endl;
	}
};

void main()
{
	Engine* engine = NULL;
	Car* car = NULL;

	engine = new Engine4000;
	car = new BMW5(engine);
	car->installEngine();

	delete engine;
	delete car;

	system("pause");
	return;
}