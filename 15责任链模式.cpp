#include <iostream>
using namespace std;

class CarHandle
{
public:
	virtual void HandleCar() = 0;
public:
	CarHandle * setNextHandle(CarHandle *carhandle)
	{
		next_carhandle = carhandle;
		return next_carhandle;
	}
protected:
	CarHandle * next_carhandle;
};

class CarHandleHead : public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "处理车头 " << endl;
		if (next_carhandle != NULL)
		{
			next_carhandle->HandleCar();
		}
	}
};
class CarHandleBody : public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "处理车身 " << endl;
		if (next_carhandle != NULL)
		{
			next_carhandle->HandleCar();
		}
	}
};
class CarHandleTail : public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "处理车尾 " << endl;
		if (next_carhandle != NULL)
		{
			next_carhandle->HandleCar();
		}
	}
};

void main()
{
	CarHandle *head = new CarHandleHead;
	CarHandle *body = new CarHandleBody;
	CarHandle *tail = new CarHandleTail;
	head->setNextHandle(body);
	body->setNextHandle(tail);
	tail->setNextHandle(NULL);
	// 处理
	head->HandleCar();

	delete head;
	delete body;
	delete tail;

	system("pause");
	return;
}