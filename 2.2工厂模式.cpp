#include "iostream"
using namespace std;

class Fruit
{
public:
	virtual void sayname() = 0;
};
class FruitFactory
{
public:
	virtual Fruit* getFruit() = 0;
};

// 香蕉
class Banana : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "Banana \n" << endl;
	}
};
// 香蕉工厂
class BananaFactory : public FruitFactory
{
public:
	virtual Fruit* getFruit()
	{
		return new Banana;
	}
};

// 苹果
class Apple : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "Apple \n" << endl;
	}
};
// 苹果工厂
class AppleFactory : public FruitFactory
{
public:
	virtual Fruit* getFruit()
	{
		return new Apple;
	}
};

void main()
{
	FruitFactory * ff = NULL;
	Fruit *fruit = NULL;
	//1香蕉
	ff = new BananaFactory();
	fruit = ff->getFruit();
	fruit->sayname();
	delete fruit;
	delete ff;
	//2 苹果
	ff = new AppleFactory();
	fruit = ff->getFruit();
	fruit->sayname();
	delete fruit;
	delete ff;

	cout << "hello....\n";
	system("pause");
}