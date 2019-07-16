#include "iostream"
using namespace std;

class Fruit
{
public:
	virtual void sayname() = 0;
};
class AbstractFactory
{
public:
	virtual Fruit* CreateBanana() = 0;
	virtual Fruit* CreateApple() = 0;
};

// 北方香蕉
class NorthBanana : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "我是北方香蕉" << endl;
	}
};
//北方苹果
class NorthApple : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "我是北方苹果" << endl;
	}
};
//北方工厂
class NorthFoctory : public AbstractFactory
{
public:
	virtual Fruit* CreateBanana()
	{
		return new NorthBanana;
	}
	virtual Fruit* CreateApple()
	{
		return new NorthApple;
	}
};

// 南方香蕉
class SourthBanana : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "我是南方香蕉" << endl;
	}
};
//南方苹果
class SourthApple : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "我是南方苹果" << endl;
	}
};
//南方工厂
class SourthFoctory : public AbstractFactory
{
public:
	virtual Fruit* CreateBanana()
	{
		return new SourthBanana;
	}
	virtual Fruit* CreateApple()
	{
		return new SourthApple;
	}
};


void main()
{
	Fruit *fruit = NULL;
	AbstractFactory *af = NULL;
	//1南方工厂
	af = new SourthFoctory;
	fruit = af->CreateBanana();
	fruit->sayname();
	delete fruit;
	fruit = af->CreateApple();
	fruit->sayname();
	delete fruit;
	//2 北方工厂
	af = new NorthFoctory;
	fruit = af->CreateBanana();
	fruit->sayname();
	delete fruit;
	fruit = af->CreateApple();
	fruit->sayname();
	delete fruit;

	cout << "hello....\n";
	system("pause");
}