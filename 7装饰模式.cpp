#include <iostream>
using namespace std;

class Car
{
public:
	virtual void show() = 0;
};
class RunCar : public Car
{
public:
	void run()
	{
		cout << "可以跑 " << endl;
	}
	virtual void show()
	{
		run();
	}
};

class SwimCarDirector : public Car
{
public:
	SwimCarDirector(Car *p)
	{
		m_p = p;
	}
	void swim()
	{
		cout << "可以游 " << endl;
	}
	virtual void show()
	{
		m_p->show();
		swim();
	}
private:
	Car * m_p;
};
class FlyCarDirector : public Car
{
public:
	FlyCarDirector(Car *p)
	{
		m_p = p;
	}
	void fly()
	{
		cout << "可以飞 " << endl;
	}
	virtual void show()
	{
		m_p->show();
		fly();
	}
private:
	Car * m_p;
};

void main()
{
	Car *runcar = NULL;
	runcar = new RunCar;
	runcar->show();

	cout << " 车开始装饰 swim：" << endl;
	SwimCarDirector *swimCar = new SwimCarDirector(runcar);
	swimCar->show();

	cout << " 车开始装饰 fly：" << endl;
	FlyCarDirector *flyCar = new FlyCarDirector(swimCar);
	flyCar->show();

	delete flyCar;
	delete swimCar;
	delete runcar;
	return;
}